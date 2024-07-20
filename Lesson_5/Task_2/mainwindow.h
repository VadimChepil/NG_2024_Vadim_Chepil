#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QList>

#include "cardfile.h"
#include "secondwindow.h"

class SecondWindow;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_b_changeDocuments_clicked();
    void on_b_search_clicked();
    void on_b_return_clicked();
    void on_b_addDocuments_clicked();
    void on_b_deleteDocuments_clicked();

private:
    Ui::MainWindow *ui;
    QScopedPointer<SecondWindow> secondWindow;
    QList<CardFile> documents;
};
#endif // MAINWINDOW_H
