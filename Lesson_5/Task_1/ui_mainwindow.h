/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *c_typeCar;
    QLabel *label_2;
    QComboBox *c_brandCar;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *l_fromYear;
    QLineEdit *l_toYear;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *l_fromPrice;
    QLineEdit *l_toPrice;
    QPushButton *b_search;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(281, 361);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(646, 600));
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(259, 20));

        verticalLayout->addWidget(label);

        c_typeCar = new QComboBox(centralwidget);
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->addItem(QString());
        c_typeCar->setObjectName("c_typeCar");

        verticalLayout->addWidget(c_typeCar);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(259, 20));

        verticalLayout->addWidget(label_2);

        c_brandCar = new QComboBox(centralwidget);
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->addItem(QString());
        c_brandCar->setObjectName("c_brandCar");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(c_brandCar->sizePolicy().hasHeightForWidth());
        c_brandCar->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(c_brandCar);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(259, 20));

        verticalLayout->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMaximumSize(QSize(125, 20));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setMaximumSize(QSize(125, 20));

        horizontalLayout->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        l_fromYear = new QLineEdit(centralwidget);
        l_fromYear->setObjectName("l_fromYear");
        sizePolicy3.setHeightForWidth(l_fromYear->sizePolicy().hasHeightForWidth());
        l_fromYear->setSizePolicy(sizePolicy3);
        l_fromYear->setMaximumSize(QSize(125, 28));

        horizontalLayout_2->addWidget(l_fromYear);

        l_toYear = new QLineEdit(centralwidget);
        l_toYear->setObjectName("l_toYear");
        sizePolicy3.setHeightForWidth(l_toYear->sizePolicy().hasHeightForWidth());
        l_toYear->setSizePolicy(sizePolicy3);
        l_toYear->setMaximumSize(QSize(125, 28));

        horizontalLayout_2->addWidget(l_toYear);


        verticalLayout->addLayout(horizontalLayout_2);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMaximumSize(QSize(259, 20));

        verticalLayout->addWidget(label_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMaximumSize(QSize(125, 20));

        horizontalLayout_4->addWidget(label_9);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setMaximumSize(QSize(125, 20));

        horizontalLayout_4->addWidget(label_10);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        l_fromPrice = new QLineEdit(centralwidget);
        l_fromPrice->setObjectName("l_fromPrice");
        sizePolicy3.setHeightForWidth(l_fromPrice->sizePolicy().hasHeightForWidth());
        l_fromPrice->setSizePolicy(sizePolicy3);
        l_fromPrice->setMaximumSize(QSize(125, 28));

        horizontalLayout_3->addWidget(l_fromPrice);

        l_toPrice = new QLineEdit(centralwidget);
        l_toPrice->setObjectName("l_toPrice");
        sizePolicy3.setHeightForWidth(l_toPrice->sizePolicy().hasHeightForWidth());
        l_toPrice->setSizePolicy(sizePolicy3);
        l_toPrice->setMaximumSize(QSize(125, 28));

        horizontalLayout_3->addWidget(l_toPrice);


        verticalLayout->addLayout(horizontalLayout_3);

        b_search = new QPushButton(centralwidget);
        b_search->setObjectName("b_search");

        verticalLayout->addWidget(b_search);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(c_typeCar, c_brandCar);
        QWidget::setTabOrder(c_brandCar, l_fromYear);
        QWidget::setTabOrder(l_fromYear, l_fromPrice);
        QWidget::setTabOrder(l_fromPrice, l_toPrice);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Body type", nullptr));
        c_typeCar->setItemText(0, QCoreApplication::translate("MainWindow", "All types", nullptr));
        c_typeCar->setItemText(1, QCoreApplication::translate("MainWindow", "Sedan", nullptr));
        c_typeCar->setItemText(2, QCoreApplication::translate("MainWindow", "Pickup", nullptr));
        c_typeCar->setItemText(3, QCoreApplication::translate("MainWindow", "Hatchback", nullptr));
        c_typeCar->setItemText(4, QCoreApplication::translate("MainWindow", "Universal", nullptr));
        c_typeCar->setItemText(5, QCoreApplication::translate("MainWindow", "Compartment", nullptr));
        c_typeCar->setItemText(6, QCoreApplication::translate("MainWindow", "Minivan", nullptr));
        c_typeCar->setItemText(7, QCoreApplication::translate("MainWindow", "Crossover", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Brand", nullptr));
        c_brandCar->setItemText(0, QCoreApplication::translate("MainWindow", "All brands", nullptr));
        c_brandCar->setItemText(1, QCoreApplication::translate("MainWindow", "Audi", nullptr));
        c_brandCar->setItemText(2, QCoreApplication::translate("MainWindow", "Skoda", nullptr));
        c_brandCar->setItemText(3, QCoreApplication::translate("MainWindow", "Daewoo", nullptr));
        c_brandCar->setItemText(4, QCoreApplication::translate("MainWindow", "BMW", nullptr));
        c_brandCar->setItemText(5, QCoreApplication::translate("MainWindow", "Mercedes-Benz", nullptr));
        c_brandCar->setItemText(6, QCoreApplication::translate("MainWindow", "Ford", nullptr));
        c_brandCar->setItemText(7, QCoreApplication::translate("MainWindow", "Toyota", nullptr));
        c_brandCar->setItemText(8, QCoreApplication::translate("MainWindow", "Volkswagen", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "Graduation year", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Price ($)", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
        b_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
