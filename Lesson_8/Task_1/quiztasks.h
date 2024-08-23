#ifndef QUIZTASKS_H
#define QUIZTASKS_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class QuizTasks;
}

class QuizTasks : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuizTasks(QWidget *parent = nullptr);
    ~QuizTasks();

private slots:
    void sendAnswer();
    void generateTask();
    void onReplyFinished(QNetworkReply *reply);

private:
    void sendAi(const QString &prompt);

    Ui::QuizTasks *ui;
    QNetworkAccessManager *manager;
    QString aiAnswer;
    bool receivedTask = false;
};

#endif // QUIZTASKS_H
