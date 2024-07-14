#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Adding (objects) cars
    Addition Audi;
    Audi.setBrandCar("Audi");
    Audi.setManufactureCar("Germany");
    Audi.setPriceCar(14000);
    Audi.setTypeCar("Sedan");
    Audi.setColorCar("Gray");
    Audi.setModelCar("A4");
    Audi.setNumberSeatsCar(5);
    Audi.setYearCar(2014);
    cars.append(Audi);

    Addition BMW;
    BMW.setBrandCar("BMW");
    BMW.setManufactureCar("Germany");
    BMW.setPriceCar(80000);
    BMW.setTypeCar("Sedan");
    BMW.setColorCar("Blue");
    BMW.setModelCar("M5");
    BMW.setNumberSeatsCar(5);
    BMW.setYearCar(2018);
    cars.append(BMW);

    Addition Volkswagen;
    Volkswagen.setBrandCar("Volkswagen");
    Volkswagen.setManufactureCar("Germany");
    Volkswagen.setPriceCar(30000);
    Volkswagen.setTypeCar("Crossover");
    Volkswagen.setColorCar("White");
    Volkswagen.setModelCar("Crozz");
    Volkswagen.setNumberSeatsCar(5);
    Volkswagen.setYearCar(2022);
    cars.append(Volkswagen);

    Addition Skoda;
    Skoda.setBrandCar("Skoda");
    Skoda.setManufactureCar("Germany");
    Skoda.setPriceCar(20000);
    Skoda.setTypeCar("Universal");
    Skoda.setColorCar("Brown");
    Skoda.setModelCar("Octavia А5");
    Skoda.setNumberSeatsCar(7);
    Skoda.setYearCar(2015);
    cars.append(Skoda);

    Addition Mercedes;
    Mercedes.setBrandCar("Mercedes-Benz");
    Mercedes.setManufactureCar("Germany");
    Mercedes.setPriceCar(190000);
    Mercedes.setTypeCar("Compartment");
    Mercedes.setColorCar("Black");
    Mercedes.setModelCar("S-Class");
    Mercedes.setNumberSeatsCar(5);
    Mercedes.setYearCar(2021);
    cars.append(Mercedes);

    Addition Daewoo;
    Daewoo.setBrandCar("Daewoo");
    Daewoo.setManufactureCar("Korea");
    Daewoo.setPriceCar(3000);
    Daewoo.setTypeCar("Hatchback");
    Daewoo.setColorCar("Red");
    Daewoo.setModelCar("Matiz");
    Daewoo.setNumberSeatsCar(4);
    Daewoo.setYearCar(2005);
    cars.append(Daewoo);

    Addition Toyota;
    Toyota.setBrandCar("Toyota");
    Toyota.setManufactureCar("Japan");
    Toyota.setPriceCar(45000);
    Toyota.setTypeCar("Pickup");
    Toyota.setColorCar("Green");
    Toyota.setModelCar("Hilux");
    Toyota.setNumberSeatsCar(5);
    Toyota.setYearCar(2021);
    cars.append(Toyota);

    Addition Ford;
    Ford.setBrandCar("Ford");
    Ford.setManufactureCar("America");
    Ford.setPriceCar(20000);
    Ford.setTypeCar("Minivan");
    Ford.setColorCar("Gray");
    Ford.setModelCar("Transit");
    Ford.setNumberSeatsCar(8);
    Ford.setYearCar(2020);
    cars.append(Ford);
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
    if (!ui->l_fromYear->text().isEmpty())
    {
        fromYear = ui->l_fromYear->text().toInt();
    }
    if (!ui->l_toYear->text().isEmpty())
    {
        toYear = ui->l_toYear->text().toInt();
    }
    if (!ui->l_fromPrice->text().isEmpty())
    {
        fromPrice = ui->l_fromPrice->text().toInt();
    }
    if (!ui->l_toPrice->text().isEmpty())
    {
        toPrice = ui->l_toPrice->text().toInt();
    }

    // Сar selection filtering
    for (const auto& car : cars)
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
