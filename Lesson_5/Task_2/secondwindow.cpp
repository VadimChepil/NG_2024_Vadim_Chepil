#include <QLabel>
#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    nextButton = new QPushButton("Next", this);
    previousButton = new QPushButton("Previous", this);
    countPage = new QLabel(this);

    connect(nextButton, &QPushButton::clicked, this, &SecondWindow::onNextClicked);
    connect(previousButton, &QPushButton::clicked, this, &SecondWindow::onPreviousClicked);

    ui->verticalLayout->addWidget(previousButton);
    ui->verticalLayout->addWidget(nextButton);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::addPageDocument(const CardFile &document)
{
    QWidget *page = new QWidget;
    QLabel *l_information = new QLabel(page);

    QString dataDocument = "Type document: " + document.getTypeDocument() + "\n"
                           + "Name document: " + document.getNameDocument() + "\n"
                           + "Author document: " + document.getAuthorDocument() + "\n"
                           + "Date creation: " + document.getCreationDate().toString("dd.MM.yyyy") + "\n"
                           + "Address library: " + document.getAddressLibrary();

    QFont fontInformation("Times New Roman", 18);
    l_information->setFont(fontInformation);
    l_information->setGeometry(0, 0, 300, 200);
    l_information->setText(dataDocument);

    QFont fontPage("Times New Roman", 14);
    countPage->setFont(fontPage);
    countPage->setGeometry(350, 0, 30, 30);

    ui->stackedWidget->addWidget(page);

    updateCountPage();
}

void SecondWindow::updateDocuments(const QList<CardFile> &documents)
{
    // Removing all documents from the window
    while (ui->stackedWidget->count() > 0)
    {
        QWidget *widget = ui->stackedWidget->widget(0);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }

    // Added documents
    for (const CardFile &document : documents)
    {
        addPageDocument(document);
    }

    // Moves to the last page if there are at least 2 pages
    if (ui->stackedWidget->count() > 0)
    {
        ui->stackedWidget->setCurrentIndex((ui->stackedWidget->count() - 1));
    }

    updateCountPage();
}

void SecondWindow::updateCountPage()
{
    int currentPage = ui->stackedWidget->currentIndex() + 1;
    int totalPages = ui->stackedWidget->count();
    QString countPageText = QString::number(currentPage) + "/" + QString::number(totalPages);
    countPage->setText(countPageText);
}

void SecondWindow::onNextClicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int pageCount = ui->stackedWidget->count();
    if (currentIndex < pageCount - 1)
    {
        ui->stackedWidget->setCurrentIndex(currentIndex + 1);
        updateCountPage();
    }
}

void SecondWindow::onPreviousClicked()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0)
    {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
        updateCountPage();
    }
}
