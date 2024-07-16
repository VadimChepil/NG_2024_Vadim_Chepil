#ifndef ADDITION_H
#define ADDITION_H

#include "Car.h"

class Addition : public Car
{
public:
    QString getColorCar() const;
    void setColorCar(const QString &color);

    QString getModelCar() const;
    void setModelCar(const QString &model);

    int getNumberSeatsCar() const;
    void setNumberSeatsCar(int seats);

    int getYearCar() const;
    void setYearCar(int year);

    Addition(const QString& brand, const QString& manufacture, int price, const QString& type, const QString& color,
             const QString& model, int seats, int year);

private:
    QString colorCar;
    QString modelCar;
    int numberSeatsCar;
    int yearCar;
};

#endif // ADDITION_H
