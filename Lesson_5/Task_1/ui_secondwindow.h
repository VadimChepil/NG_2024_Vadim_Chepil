/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName("SecondWindow");
        SecondWindow->setEnabled(true);
        SecondWindow->resize(800, 650);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SecondWindow->sizePolicy().hasHeightForWidth());
        SecondWindow->setSizePolicy(sizePolicy);
        SecondWindow->setMinimumSize(QSize(800, 650));
        SecondWindow->setMaximumSize(QSize(1920, 1080));
        verticalLayout = new QVBoxLayout(SecondWindow);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(SecondWindow);
        stackedWidget->setObjectName("stackedWidget");

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
