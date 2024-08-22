#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QFileSystemModel>

namespace Ui {
class User;
}

class User : public QMainWindow
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = nullptr);
    ~User();

private slots:
    void login();
    void sendMessage();
    void connectionEstablished();
    void MessageReceived();
    void on_b_backChat_clicked();
    void on_b_selectFile_clicked();
    void on_lv_showFile_doubleClicked(const QModelIndex &index);
    void on_b_addFile_clicked();
    void copyFileToServerDirectory(const QString &sourceFilePath);

private:
    Ui::User *ui;
    QTcpSocket *m_socket;
    QFileSystemModel *model;
    QFileInfo selectedFileInfo;
};

#endif // USER_H
