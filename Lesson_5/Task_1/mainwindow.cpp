#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Adding (objects) cars
    cars.append(Addition(QString("Audi"), QString("Germany"), 14000, QString("Sedan"), QString("Gray"), QString("A4"), 5, 2014));
    cars.append(Addition(QString("BMW"), QString("Germany"), 80000, QString("Sedan"), QString("Blue"), QString("M5"), 5, 2018));
    cars.append(Addition(QString("Volkswagen"), QString("Germany"), 30000, QString("Crossover"), QString("White"), QString("Crozz"), 5, 2022));
    cars.append(Addition(QString("Skoda"), QString("Germany"), 20000, QString("Universal"), QString("Brown"), QString("Octavia A5"), 7, 2015));
    cars.append(Addition(QString("Mercedes-Benz"), QString("Germany"), 190000, QString("Compartment"), QString("Black"), QString("S-Class"), 5, 2021));
    cars.append(Addition(QString("Daewoo"), QString("Korea"), 3000, QString("Hatchback"), QString("Red"), QString("Matiz"), 4, 2005));
    cars.append(Addition(QString("Toyota"), QString("Japan"), 45000, QString("Pickup"), QString("Green"), QString("Hilux"), 5, 2021));
    cars.append(Addition(QString("Ford"), QString("America"), 20000, QString("Minivan"), QString("Gray"), QString("Transit"), 8, 2020));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_search_clicked()
{
    secondWindow.reset(new SecondWindow(this));

    QString typeCar = ui->c_typeCar->currentText();
    QString brandCar = ui->c_brandCar->currentText();

    // Default data
    int fromYear = 1900;
    int toYear = 2024;
    int fromPrice = 1000;
    int toPrice = 1000000;

    // Verification of entered data
    bool checkError = false;

    if (!ui->l_fromYear->text().isEmpty())
    {
        if (ui->l_fromYear->text().toInt() >= 0)
        {
            fromYear = ui->l_fromYear->text().toInt();
        }
        else
        {
            checkError = true;
        }
    }

    if (!ui->l_toYear->text().isEmpty())
    {
        if (ui->l_toYear->text().toInt() <= 2024 && ui->l_toYear->text().toInt() >= fromYear)
        {
            toYear = ui->l_toYear->text().toInt();
        }
        else
        {
            checkError = true;
        }
    }

    if (!ui->l_fromPrice->text().isEmpty())
    {
        if (ui->l_fromPrice->text().toInt() >= 0)
        {
            fromPrice = ui->l_fromPrice->text().toInt();
        }
        else
        {
            checkError = true;
        }
    }

    if (!ui->l_toPrice->text().isEmpty())
    {
        if (ui->l_toPrice->text().toInt() <= 1000000000 && ui->l_toPrice->text().toInt() >= fromPrice)
        {
            toPrice = ui->l_toPrice->text().toInt();
        }
        else
        {
            checkError = true;
        }
    }

    if (checkError)
    {
        QMessageBox::warning(this, "Data", "Invalid data!");
        return; //Stop run of the secondwindow
    }

    // Сar selection filtering
    for (Addition car : cars)
    {
        if ((typeCar == "All types" || car.getTypeCar() == typeCar) &&
            (brandCar == "All brands" || car.getBrandCar() == brandCar) &&
            (car.getYearCar() >= fromYear && car.getYearCar() <= toYear) &&
            (car.getPriceCar() >= fromPrice && car.getPriceCar() <= toPrice))
        {
            secondWindow->addPageCar(car);
        }
    }

    secondWindow->show();
}

