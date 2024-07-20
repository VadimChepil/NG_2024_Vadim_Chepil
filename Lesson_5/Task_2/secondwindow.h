#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QStackedWidget>
#include <QPushButton>

#include "mainwindow.h"

class CardFile;

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void addPageDocument(const CardFile &document);

private slots:
    void updateCountPage();
    void onNextClicked();
    void onPreviousClicked();

private:
    // Pointers
    Ui::SecondWindow *ui;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QLabel *countPage;

};

#endif // SECONDWINDOW_H
