#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QList>

#include "Addition.h"
#include "secondwindow.h"

class SecondWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
