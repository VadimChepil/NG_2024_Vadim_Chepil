#ifndef CAR_H
#define CAR_H

#include <QString>

class Car
{
public:
    QString getManufactureCar() const;
    void setManufactureCar(const QString &nameCar);

    QString getBrandCar() const;
    void setBrandCar(const QString &brand);

    int getPriceCar() const;
    void setPriceCar(int price);

    QString getTypeCar() const;
    void setTypeCar(const QString &type);

private:
    QString manufactureCar;
    QString brandCar;

protected:
    int priceCar;
    QString typeCar;
};

#endif // CAR_H
