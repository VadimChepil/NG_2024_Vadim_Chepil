#include "user.h"
#include "ui_user.h"
#include <QFileDialog>
#include <QDataStream>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>

User::User(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::User)
{
    ui->setupUi(this);
    m_socket = new QTcpSocket(this);
    model = new QFileSystemModel(this);

    model->setFilter(QDir::AllEntries);
    model->setRootPath("");
    ui->lv_showFile->setModel(model);

    ui->sb_port->setMaximum(16000);
    ui->te_chat->setReadOnly(true);

    connect(ui->b_login, &QPushButton::clicked, this, &User::login);
    connect(ui->b_send, &QPushButton::clicked, this, &User::sendMessage);
    connect(m_socket, &QTcpSocket::connected, this, &User::connectionEstablished);
    connect(m_socket, &QTcpSocket::readyRead, this, &User::MessageReceived);
}

User::~User()
{
    delete ui;
}

void User::login()
{
    QString address = ui->e_address->text();
    int port = ui->sb_port->value();
    m_socket->connectToHost(QHostAddress(address), port);
}

void User::connectionEstablished()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void User::sendMessage()
{
    QString data = QTime::currentTime().toString("hh:mm") + "  " + ui->te_input->toPlainText();

    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    int messageType = 1;  // Message
    out << messageType;
    out << data;

    m_socket->write(packet);
    ui->te_input->clear();
}

void User::copyFileToServerDirectory(const QString &sourceFilePath)
{
    QFile file(sourceFilePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QByteArray packet;
    QDataStream out(&packet, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_7);

    int messageType = 2;  // File
    out << messageType;
    out << QFileInfo(sourceFilePath).fileName();
    out << fileData;

    m_socket->write(packet);
}

void User::MessageReceived()
{
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_6_7);

    int messageType;
    int clientId;
    QString fileName;
    in >> messageType >> clientId >> fileName;

    if (messageType == 1) // Message
    {
        QByteArray byteArray;
        in >> byteArray;

        QString message = QString::fromUtf8(byteArray);
        ui->te_chat->append(message);
    }
    else if (messageType == 2) // File
    {
        QByteArray fileData;
        in >> fileData;

        QString data = QTime::currentTime().toString("hh:mm") + "  Added " + fileName;
        ui->te_chat->append(data.toUtf8());

        if (clientId != 0)
        {
            qDebug() << "Skipping file save prompt for the sender.";
            return;
        }
        if (fileData.isEmpty())
        {
            qDebug() << "Received empty file data.";
            return;
        }
        QString savePath = QFileDialog::getSaveFileName(this, "Save File", fileName);
        if (!savePath.isEmpty())
        {
            QFile file(savePath);
            if (file.open(QIODevice::WriteOnly))
            {
                file.write(fileData);
                file.close();
                qDebug() << "File received and saved as: " + savePath;
            }
            else
            {
                qDebug() << "Failed to save the file.";
            }
        }
    }
}

void User::on_b_backChat_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->le_fileName->clear();
}

void User::on_b_selectFile_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void User::on_lv_showFile_doubleClicked(const QModelIndex &index)
{
    QListView* listView = (QListView*)sender();
    QFileInfo fileInfo = model->fileInfo(index);

    if (fileInfo.fileName() == "..")
    {
        QDir dir = fileInfo.dir();
        dir.cdUp();
        listView->setRootIndex(model->index(dir.absolutePath()));
    }
    else if (fileInfo.fileName() == ".")
    {
        listView->setRootIndex(model->index(""));
    }
    else if (fileInfo.isDir())
    {
        listView->setRootIndex(index);
    }
    else
    {
        selectedFileInfo = fileInfo;
        ui->le_fileName->setText(selectedFileInfo.fileName());
    }
}

void User::on_b_addFile_clicked()
{
    if (selectedFileInfo.isFile())
    {
        QString path = selectedFileInfo.absoluteFilePath();
        copyFileToServerDirectory(path);
    }
}
