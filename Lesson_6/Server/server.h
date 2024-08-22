#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QDir>
#include <Qlist>

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
    void start(int port);

private slots:
    void newClient();
    void leftClient();
    void messageFromClient();
    void sendToAll(QByteArray message, int messageType);

private:
    QTcpServer *m_server;
    QList<QTcpSocket *> m_clients;
    QString fileName;
    QList<int> clientsId;
    int clientIndex;
    int clientId;
};

#endif // SERVER_H
