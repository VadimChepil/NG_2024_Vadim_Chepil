#include <QPixmap>

#include "secondwindow.h"
#include "ui_secondwindow.h"


SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    // Create and configure "Next" and "Previous" buttons
    nextButton = new QPushButton("Next", this);
    previousButton = new QPushButton("Previous", this);

    connect(nextButton, &QPushButton::clicked, this, &SecondWindow::onNextClicked);
    connect(previousButton, &QPushButton::clicked, this, &SecondWindow::onPreviousClicked);

    ui->verticalLayout->addWidget(previousButton);
    ui->verticalLayout->addWidget(nextButton);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::addPageCar(const Addition &car)
{
    QWidget *page = new QWidget;
    QLabel *l_information = new QLabel(page);
    QLabel *l_image = new QLabel(page);

    QString carDetails = "Type: " + car.getTypeCar() + "\n" + "Brand: " + car.getBrandCar() + "\n"
                         + "Manufacture: " + car.getManufactureCar() + "\n" + "Color: " + car.getColorCar() + "\n"
                         + "Model: " + car.getModelCar() + "\n" + "Year: " + QString::number(car.getYearCar()) + "\n"
                         + "Seats: " + QString::number(car.getNumberSeatsCar()) + "\n" + "Price: " + QString::number(car.getPriceCar()) + "$";

    l_information->setText(carDetails);

    // Setting the size of information
    l_information->setGeometry(0, 405, 778, 200);

    // Adding photos
    QPixmap pixmap;
    if (car.getBrandCar() == "Audi")
    {
        pixmap.load(":/resources/images/Audi A4.jpg");
    }
    else if (car.getBrandCar() == "BMW")
    {
        pixmap.load(":/resources/images/BMW M5.jpg");
    }
    else if (car.getBrandCar() == "Daewoo")
    {
        pixmap.load(":/resources/images/Daewoo Matiz.jpg");
    }
    else if (car.getBrandCar() == "Mercedes-Benz")
    {
        pixmap.load(":/resources/images/Mercedes-Benz S-Class.jpg");
    }
    else if (car.getBrandCar() == "Toyota")
    {
        pixmap.load(":/resources/images/Toyota Hilux.jpg");
    }
    else if (car.getBrandCar() == "Ford")
    {
        pixmap.load(":/resources/images/Ford Transit.jpg");
    }
    else if (car.getBrandCar() == "Volkswagen")
    {
        pixmap.load(":/resources/images/Volkswagen Crozz.jpg");
    }
    else if (car.getBrandCar() == "Skoda")
    {
        pixmap.load(":/resources/images/Skoda Octavia.jpg");
    }

    if (!pixmap.isNull())
    {
        l_image->setPixmap(pixmap.scaled(778, 428, Qt::KeepAspectRatio));
    }
    // Setting the size of photos
    l_image->setGeometry(0, 0, 778, 428);

    // Adding a page with car information
    ui->stackedWidget->addWidget(page);
}

void SecondWindow::onNextClicked()
{
    // Check for an existing next page
    int currentIndex = ui->stackedWidget->currentIndex();
    int pageCount = ui->stackedWidget->count();
    if (currentIndex < pageCount - 1)
    {
        ui->stackedWidget->setCurrentIndex(currentIndex + 1);
    }
}

void SecondWindow::onPreviousClicked()
{
    // Check for an existing previous page
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0)
    {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
    }
}
