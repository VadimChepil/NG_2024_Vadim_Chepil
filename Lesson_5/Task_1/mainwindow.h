#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QList>
#include "secondwindow.h"

class SecondWindow;

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Car
{
public:
    QString getManufactureCar() const
    {
        return manufactureCar;
    }

    void setManufactureCar(const QString &nameCar)
    {
        manufactureCar = nameCar;
    }

    QString getBrandCar() const
    {
        return brandCar;
    }

    void setBrandCar(const QString &brand)
    {
        brandCar = brand;
    }

    int getPriceCar() const
    {
        return priceCar;
    }

    void setPriceCar(int price)
    {
        priceCar = price;
    }

    QString getTypeCar() const
    {
        return typeCar;
    }

    void setTypeCar(const QString &type)
    {
        typeCar = type;
    }

private:
    QString manufactureCar;
    QString brandCar;

protected:
    int priceCar;
    QString typeCar;
};

class Addition : public Car
{
public:
    QString getColorCar() const
    {
        return colorCar;
    }

    void setColorCar(const QString &color)
    {
        colorCar = color;
    }

    QString getModelCar() const
    {
        return modelCar;
    }

    void setModelCar(const QString &model)
    {
        modelCar = model;
    }

    int getNumberSeatsCar() const
    {
        return numberSeatsCar;
    }

    void setNumberSeatsCar(int seats)
    {
        numberSeatsCar = seats;
    }

    int getYearCar() const
    {
        return yearCar;
    }

    void setYearCar(int year)
    {
        yearCar = year;
    }

private:
    QString colorCar;
    QString modelCar;
    int numberSeatsCar;
    int yearCar;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b_search_clicked();

signals:
    void sendDataCar(const QString &typeCar, const QString &brandCar, const QString &manufactureCar, const QString &colorCar,
                        const QString &modelCar, const QString &seatsCar, const QString &priceCar, const QString &yearCar);

private:
    Ui::MainWindow *ui;
    QScopedPointer<SecondWindow> secondWindow;
    QList<Addition> cars;
};

#endif // MAINWINDOW_H
