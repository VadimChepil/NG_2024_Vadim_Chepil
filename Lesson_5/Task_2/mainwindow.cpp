#include <QDebug>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cardfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->sb_getDate->setMaximum(2024);
    ui->sb_setDate->setMaximum(2024);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b_search_clicked()
{
    secondWindow.reset(new SecondWindow(this));

    QString typeDocument = ui->cb_getType->currentText();
    QString nameDocument = ui->l_getName->text();
    QString author = ui->l_getAuthor->text();
    int dateCreation = ui->sb_getDate->value();
    QString addressLibrary = ui->l_getAddress->text();

    bool found = false;
    for (const CardFile &document : documents)
    {
        if ((typeDocument == "All types" || document.getTypeDocument() == typeDocument) &&
            (nameDocument.isEmpty() || document.getNameDocument() == nameDocument) &&
            (author.isEmpty() || document.getAuthorDocument() == author) &&
            (dateCreation == 0 || document.getCreationDate() == dateCreation) &&
            (addressLibrary.isEmpty() || document.getAddressLibrary() == addressLibrary))
        {
            secondWindow->addPageDocument(document);
            found = true;
        }
    }

    if (found)
    {
        secondWindow->show();
    }
    else
    {
        QMessageBox::information(this, "Search result", "Document not found");
    }
}

void MainWindow::on_b_changeDocuments_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_b_return_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_b_addDocuments_clicked()
{
    CardFile newDocument(ui->cb_setType->currentText(), ui->l_setName->text(),
                         ui->l_setAuthor->text(), ui->sb_setDate->value(), ui->l_setAddress->text());

    // Check if the document is valid
    if ((!newDocument.getTypeDocument().isEmpty()) &&
        (!newDocument.getNameDocument().isEmpty()) &&
        (!newDocument.getAuthorDocument().isEmpty()) &&
        (newDocument.getCreationDate() != 0) &&
        (!newDocument.getAddressLibrary().isEmpty()))
    {
        bool documentExists = false;

        // Check if the document already exists
        for (const CardFile &document : documents)
        {
            if ((newDocument.getTypeDocument() == document.getTypeDocument()) &&
                (newDocument.getNameDocument() == document.getNameDocument()) &&
                (newDocument.getAuthorDocument() == document.getAuthorDocument()) &&
                (newDocument.getCreationDate() == document.getCreationDate()) &&
                (newDocument.getAddressLibrary() == document.getAddressLibrary()))
            {
                documentExists = true;
                break;
            }
        }

        // Adding the document if it does not already exist
        if (!documentExists)
        {
            documents.append(newDocument);
            if (documents.contains(newDocument))
            {
                QMessageBox::information(this, "Adding document", "Document added successfully");
            }
        }
        else
        {
            QMessageBox::information(this, "Adding document", "This document already exists");
        }
    }
    else
    {
        QMessageBox::warning(this, "Adding document", "Invalid data");
    }
}

void MainWindow::on_b_deleteDocuments_clicked()
{
    QString typeDocument = ui->cb_setType->currentText();
    QString nameDocument = ui->l_setName->text();
    QString author = ui->l_setAuthor->text();
    int dateCreation = ui->sb_setDate->value();
    QString addressLibrary = ui->l_setAddress->text();

    bool found = false;
    for (const CardFile &document : documents)
    {
        if ((document.getTypeDocument() == typeDocument) &&
            (document.getNameDocument() == nameDocument) &&
            (document.getAuthorDocument() == author) &&
            (document.getCreationDate() == dateCreation) &&
            (document.getAddressLibrary() == addressLibrary))
        {
            documents.removeOne(document);
            QMessageBox::information(this, "Delete documents", "Document deleted successfully");
            found = true;
            break;
        }
    }
    if (!found)
    {
        QMessageBox::warning(this, "Delete documents", "This document does not exist");
    }
}

