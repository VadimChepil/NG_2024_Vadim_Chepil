#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cardfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , secondWindow(new SecondWindow(this))
{
    ui->setupUi(this);
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
    QDate dateCreation = ui->de_getDate->date();
    QString addressLibrary = ui->l_getAddress->text();

    bool found = false;
    for (const CardFile &document : documents)
    {
        if ((typeDocument == "All types" || document.getTypeDocument() == typeDocument) &&
            (nameDocument.isEmpty() || document.getNameDocument() == nameDocument) &&
            (author.isEmpty() || document.getAuthorDocument() == author) &&
            (dateCreation.isNull() || document.getCreationDate() == dateCreation) &&
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
                         ui->l_setAuthor->text(), ui->de_setDate->date(), ui->l_setAddress->text());

    if ((!newDocument.getTypeDocument().isEmpty()) &&
        (!newDocument.getNameDocument().isEmpty()) &&
        (!newDocument.getAuthorDocument().isEmpty()) &&
        (!newDocument.getCreationDate().isNull()) &&
        (!newDocument.getAddressLibrary().isEmpty()))
    {
        bool documentExists = false;

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

        if (!documentExists)
        {
            documents.append(newDocument);
            if (documents.contains(newDocument))
            {
                QMessageBox::information(this, "Adding document", "Document added successfully");
                secondWindow->updateDocuments(documents);
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
    QDate dateCreation = ui->de_setDate->date();
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
            secondWindow->updateDocuments(documents);
            break;
        }
    }
    if (!found)
    {
        QMessageBox::warning(this, "Delete documents", "This document does not exist");
    }
}
