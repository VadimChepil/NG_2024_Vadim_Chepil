#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    bool foundSymbol();

private slots:
    void numberOutput();
    void numberAction();
    void on_b_delete_clicked();
    void on_b_deleteSymbol_clicked();
    void on_b_changeSign_clicked();

    void on_b_equal_clicked();

private:
    Ui::MainWindow *ui;
    QString digitText;
};
#endif // MAINWINDOW_H
