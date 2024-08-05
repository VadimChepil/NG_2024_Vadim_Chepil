#include <QDebug>
#include <QRegularExpression>
#include <QStack>
#include <cmath>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , digitText("")
{
    ui->setupUi(this);
    connect(ui->b_set0, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set1, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set2, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set3, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set4, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set5, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set6, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set7, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set8, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_set9, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_setPoint, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_squareRoot, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_interest, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_exaltationToSecondDegree, SIGNAL(clicked()), this, SLOT(numberOutput()));
    connect(ui->b_deleteOneOnX, SIGNAL(clicked()), this, SLOT(numberOutput()));

    connect(ui->b_addition, SIGNAL(clicked()), this, SLOT(numberAction()));
    connect(ui->b_multiply, SIGNAL(clicked()), this, SLOT(numberAction()));
    connect(ui->b_subtract, SIGNAL(clicked()), this, SLOT(numberAction()));
    connect(ui->b_divide, SIGNAL(clicked()), this, SLOT(numberAction()));

    ui->le_display->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::foundSymbol()
{
    bool found = false;
    QString symbolText = digitText.right(1);
    QList<QString> symbols = {"+", "-", "*", "/", ".", "^", "√", "%"};
    for (const QString &symbol : symbols)
    {
        if (symbolText == symbol)
        {
            found = true;
            break;
        }
    }
    return found;
}

void MainWindow::numberOutput()
{
    QPushButton *button = (QPushButton *)sender();

    if (button->text() == "." || button->text() == "^" || button->text() == "√" || button->text() == "%")
    {
        if (!digitText.isEmpty() && !digitText.right(1).contains(QRegularExpression("[0-9]")) && !foundSymbol())
        {
            return;
        }
        int lastOperatorIndex = qMax(digitText.lastIndexOf('+'), qMax(digitText.lastIndexOf('-'), qMax(digitText.lastIndexOf('*'), digitText.lastIndexOf('/'))));
        QString lastNumber = digitText.mid(lastOperatorIndex + 1);
        if (lastNumber.contains('.') || lastNumber.contains("√") || lastNumber.contains("^") || lastNumber.contains("%"))
        {
            return;
        }
        if (button->text() == "%")
        {
            if (!lastNumber.isEmpty() && lastNumber.toDouble() > 0)
            {
                ui->le_display->setText(digitText + "%");
                digitText += "*0.01";
                return;
            }
        }
        else if (button->text() == "√")
        {
            if (!lastNumber.isEmpty() && lastNumber.toDouble() > 0)
            {
                digitText += "*";
            }
        }
        else if (button->text() == ".")
        {
            if (digitText.length() == 0)
            {
                digitText += "0";
            }
        }
    }
    digitText += button->text();
    ui->le_display->setText(digitText);
}

void MainWindow::numberAction()
{
    QPushButton *button = (QPushButton *)sender();
    if (!foundSymbol() && digitText.length() > 0)
    {
        digitText += button->text();
    }
    ui->le_display->setText(digitText);
}

void MainWindow::on_b_delete_clicked()
{
    digitText.clear();
    ui->le_display->setText("0");
}

void MainWindow::on_b_deleteSymbol_clicked()
{
    digitText.removeLast();
    if (digitText.length() == 0)
    {
        ui->le_display->setText("0");
    }
    else
    {
        ui->le_display->setText(digitText);
    }
}

void MainWindow::on_b_changeSign_clicked()
{
    if (digitText.length() > 0)
    {
        if (digitText.front() == '-')
        {
            digitText.remove(0, 1);
        }
        else
        {
            digitText.prepend('-');
        }
    }
    ui->le_display->setText(digitText);
}

int priority(QChar operation)
{
    if (operation == '^' || operation == QChar(0x221A))
    {
        return 3;
    }
    if (operation == '*' || operation == '/')
    {
        return 2;
    }
    if (operation == '+' || operation == '-')
    {
        return 1;
    }
    return 0;
}

double applyOperation(double val1, double val2, QChar operation)
{
    switch (operation.unicode())
    {
    case '+':
        return val1 + val2;
    case '-':
        return val1 - val2;
    case '*':
        return val1 * val2;
    case '/':
        return val1 / val2;
    case '^':
        return pow(val1, val2);
    case 0x221A:
        return sqrt(val2);
    default:
        return 0;
    }
}

double checkExpression(const QString& expression)
{
    QStack<double> values;
    QStack<QChar> operators;
    int i = 0;

    auto applyTopOperator = [&values, &operators]()
    {
        if (values.size() < 2 && operators.top() != QChar(0x221A))
        {
            throw std::runtime_error("Insufficient values for operation");
        }
        double val2 = values.pop();
        QChar op = operators.pop();
        double val1 = (op == QChar(0x221A)) ? 0 : values.pop();

        if (op == '/' && val2 == 0)
        {
            throw std::runtime_error("Division by zero");
        }

        values.push(applyOperation(val1, val2, op));
    };

    while (i < expression.length())
    {
        if (expression[i].isDigit() || expression[i] == '.')
        {
            QString valueStr;
            bool hasExponent = false;
            while (i < expression.length() && (expression[i].isDigit() || expression[i] == '.' || (expression[i].toLower() == 'e' && !hasExponent)))
            {
                if (expression[i].toLower() == 'e')
                {
                    hasExponent = true;
                }
                valueStr += expression[i++];
            }
            bool ok;
            double value = valueStr.toDouble(&ok);
            if (!ok)
            {
                throw std::runtime_error("Invalid number format");
            }
            values.push(value);
        }
        else
        {
            if (expression[i] == QChar(0x221A))
            {
                operators.push(expression[i++]);
            }
            else
            {
                while (!operators.isEmpty() && priority(operators.top()) >= priority(expression[i]))
                {
                    applyTopOperator();
                }
                operators.push(expression[i++]);
            }
        }
    }

    while (!operators.isEmpty())
    {
        applyTopOperator();
    }

    return values.top();
}

void MainWindow::on_b_equal_clicked()
{
    try
    {
        if (digitText.length() != 0)
        {
            double result = checkExpression(digitText);
            digitText = QString::number(result);
        }
        ui->le_display->setText(digitText);
    }
    catch (const std::exception &e) {
        qDebug() << "Error:" << e.what();
        ui->le_display->setText("Error");
    }
}
