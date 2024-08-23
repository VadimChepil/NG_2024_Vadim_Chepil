#include "quiztasks.h"
#include "ui_quiztasks.h"

QuizTasks::QuizTasks(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuizTasks)
    , m_manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(ui->b_sendAnswear, &QPushButton::clicked, this, &QuizTasks::sendAnswer);
    connect(ui->b_generationTask, &QPushButton::clicked, this, &QuizTasks::generateTask);
    connect(m_manager, &QNetworkAccessManager::finished, this, &QuizTasks::onReplyFinished);
}

QuizTasks::~QuizTasks()
{
    delete ui;
}

void QuizTasks::sendAnswer()
{
    QString userAnswer = ui->le_userAnswear->text().trimmed();
    if (userAnswer.isEmpty())
        return;

    ui->le_correctAnswear->setText(m_llmAnswer);
    ui->b_sendAnswear->setEnabled(false);
    ui->le_userAnswear->setReadOnly(true);

    bool isCorrect = m_llmAnswer.trimmed() == userAnswer;
    ui->le_checkAnswear->setText(isCorrect ? "True" : "False");

    int correctCount = ui->le_numberCorrectAnswears->text().toInt();
    int incorrectCount = ui->le_numberIncorrectAnswears->text().toInt();

    ui->le_numberCorrectAnswears->setText(isCorrect ? QString::number(correctCount + 1) : QString::number(correctCount));
    ui->le_numberIncorrectAnswears->setText(!isCorrect ? QString::number(incorrectCount + 1) : QString::number(incorrectCount));

    if (ui->l_number->text().split('/').first().toInt() == 5)
    {
        ui->le_assessmentResult->setText(QString("%1/%2").arg(correctCount).arg(correctCount + incorrectCount));
    }

    ui->b_generationTask->setEnabled(true);
}

void QuizTasks::generateTask()
{
    if (m_taskReceived) {
        m_taskReceived = false;
        int taskNumber = ui->l_number->text().split('/').first().toInt();
        if (taskNumber == 5) {
            ui->l_number->setText("0/5");
            ui->le_checkAnswear->setText("Not checked");
            ui->le_numberCorrectAnswears->setText("0");
            ui->le_numberIncorrectAnswears->setText("0");
            ui->le_assessmentResult->setText("Assessment result for 5 tasks:");
        } else {
            ui->l_number->setText(QString::number(taskNumber + 1) + "/5");
        }
    }

    ui->b_generationTask->setEnabled(false);
    ui->le_task->setText("Loading…");
    ui->le_userAnswear->clear();
    ui->le_correctAnswear->clear();
    ui->le_checkAnswear->setText("Not checked");

    sendPrompt("Create a mathematical problem and provide the correct answer (only the number). "
               "The problem can range from simple equations to logic puzzles.  "
               "Write both the problem and the answer on separate lines. "
               "The problem should be on the first line, and the answer on the second.  "
               "Avoid using the equation 2𝑥+5=11.");
}

void QuizTasks::sendPrompt(const QString &prompt)
{
    QNetworkRequest request(QUrl("http://127.0.0.1:11434/api/generate"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["model"] = "llama3.1:8b";
    json["prompt"] = prompt;
    json["stream"] = false;

    m_manager->post(request, QJsonDocument(json).toJson());
}

void QuizTasks::onReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray textReply = reply->readAll();
        QStringList data = QJsonDocument::fromJson(textReply).object().value("response").toString().split('\n');
        ui->le_task->setText(data[0]);
        m_llmAnswer = (data.size() > 1 && !data[1].isEmpty()) ? data[1] : (data.size() > 2 ? data[2] : QString());

        m_taskReceived = true;
        ui->b_sendAnswear->setEnabled(true);
        ui->le_userAnswear->setReadOnly(false);
    } else {
        ui->le_task->setText("Error: " + reply->errorString());
        ui->b_generationTask->setEnabled(true);
    }
    reply->deleteLater();
}
