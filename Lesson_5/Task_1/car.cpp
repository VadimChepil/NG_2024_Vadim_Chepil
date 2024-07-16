#include "Car.h"

QString Car::getManufactureCar() const
{
    return manufactureCar;
}
void Car::setManufactureCar(const QString &nameCar)
{
    manufactureCar = nameCar;
}

QString Car::getBrandCar() const
{
    return brandCar;
}
void Car::setBrandCar(const QString &brand)
{
    brandCar = brand;
}

int Car::getPriceCar() const
{
    return priceCar;
}
void Car::setPriceCar(int price)
{
    priceCar = price;
}

QString Car::getTypeCar() const
{
    return typeCar;
}
void Car::setTypeCar(const QString &type)
{
    typeCar = type;
}

