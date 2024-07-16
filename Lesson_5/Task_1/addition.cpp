#include "Addition.h"

Addition::Addition(const QString& brand, const QString& manufacture, int price, const QString& type, const QString& color,
                   const QString& model, int seats, int year)
{
    setBrandCar(brand);
    setManufactureCar(manufacture);
    setPriceCar(price);
    setTypeCar(type);
    setColorCar(color);
    setModelCar(model);
    setNumberSeatsCar(seats);
    setYearCar(year);
}

QString Addition::getColorCar() const
{
    return colorCar;
}
void Addition::setColorCar(const QString &color)
{
    colorCar = color;
}

QString Addition::getModelCar() const
{
    return modelCar;
}
void Addition::setModelCar(const QString &model)
{
    modelCar = model;
}

int Addition::getNumberSeatsCar() const
{
    return numberSeatsCar;
}
void Addition::setNumberSeatsCar(int seats)
{
    numberSeatsCar = seats;
}

int Addition::getYearCar() const
{
    return yearCar;
}
void Addition::setYearCar(int year)
{
    yearCar = year;
}
