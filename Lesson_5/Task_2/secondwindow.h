#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QStackedWidget>
#include <QPushButton>
#include <QList>
#include "cardfile.h"

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
    void updateDocuments(const QList<CardFile> &documents);

private slots:
    void updateCountPage();
    void onNextClicked();
    void onPreviousClicked();

private:
    Ui::SecondWindow *ui;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QLabel *countPage;
};

#endif // SECONDWINDOW_H
