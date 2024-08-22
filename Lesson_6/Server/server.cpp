#include "server.h"
#include <QDataStream>
#include <QFileInfo>
#include <QDebug>

Server::Server(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer();
    connect(m_server, &QTcpServer::newConnection, this, &Server::newClient);
}

Server::~Server()
{
    if (m_server->isListening())
    {
        qDebug() << "Closing server...";
        m_server->close();
    }
    delete m_server;
}

void Server::start(int port)
{
    bool ok = m_server->listen(QHostAddress::Any, port);
    if (ok)
    {
        qDebug() << "We are online!";
    }
    else
    {
        qDebug() << "Error creating connection: " << m_server->errorString();
    }
}

void Server::newClient()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    qDebug() << "Client connected:" << client->peerAddress().toString();

    connect(client, &QTcpSocket::disconnected, this, &Server::leftClient);
    connect(client, &QTcpSocket::readyRead, this, &Server::messageFromClient);

    m_clients.append(client);
    int id = m_clients.size();
    clientsId.append(id);
    qDebug() << "ID of the new client: " << id;
    qDebug() << "Number of clients:" << m_clients.size();

}

void Server::leftClient()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    if (client)
    {
        int index = m_clients.indexOf(client);
        if (index != -1)
        {
            int removedId = clientsId.takeAt(index);
            qDebug() << "Client disconnected with ID:" << removedId;

            m_clients.removeAt(index);
            client->deleteLater();

            qDebug() << "Number of clients:" << m_clients.size();
        }
    }
}


void Server::messageFromClient()
{
    QTcpSocket *client = qobject_cast<QTcpSocket *>(sender());
    if (!client) return;

    QDataStream in(client);
    in.setVersion(QDataStream::Qt_6_7);

    int messageType;
    in >> messageType;

    clientIndex = m_clients.indexOf(client);
    clientId = clientsId[clientIndex];

    if (messageType == 1) // Message
    {
        QString message;
        in >> message;

        sendToAll(message.toUtf8(), 1);
    }
    else if (messageType == 2) // File
    {
        fileName.clear();
        QByteArray fileData;
        in >> fileName >> fileData;

        if (!fileName.isEmpty() && !fileData.isEmpty())
        {
            QString destinationFilePath = QDir::currentPath() + QDir::separator() + fileName;
            QFile file(destinationFilePath);

            if (file.open(QIODevice::WriteOnly))
            {
                file.write(fileData);
                file.close();
                qDebug() << "File saved to:" << destinationFilePath;

                if (file.remove())
                {
                    qDebug() << "File seccussful deleted: " << fileName;
                }
                else
                {
                    qDebug() << "Error! File not deleted: " << fileName;
                }
                sendToAll(fileData, 2);
            }
            else
            {
                qDebug() << "Failed to save the file.";
            }
        }
        else
        {
            qDebug() << "Received data is not a valid file.";
        }
    }
}

void Server::sendToAll(QByteArray message, int messageType)
{
    QByteArray packet;

    for (int index = 0; index < m_clients.size(); ++index)
    {
        QTcpSocket *client = m_clients[index];
        if (client->state() == QAbstractSocket::ConnectedState)
        {
            packet.clear();
            QDataStream out(&packet, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_6_7);

            if (clientId != clientsId[index])
            {
                clientId = 0;
            }
            out << messageType << clientId << fileName << message;
            clientId = clientsId[clientIndex];

            client->write(packet);
            client->flush();
        }
    }
    qDebug() << "Sending to client with ID:" <<  clientId;
}

