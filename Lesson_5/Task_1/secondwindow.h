#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QStackedWidget>
#include <QPushButton>
#include "mainwindow.h"

class Addition;

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void addPageCar(const Addition &car);

private slots:
    void onNextClicked();
    void onPreviousClicked();

private:
    // Pointers
    Ui::SecondWindow *ui;
    QLabel *imageLabel;
    QPushButton *nextButton;
    QPushButton *previousButton;
};

#endif // SECONDWINDOW_H
