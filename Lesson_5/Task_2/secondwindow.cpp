#include <QLabel>

#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    // Create and configure "Next" and "Previous" buttons
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
                        + "Date creation: " + QString::number(document.getCreationDate()) + "\n"
                        + "Address library: " + document.getAddressLibrary();

    QFont fontInformation("Times New Roman", 20);
    l_information->setFont(fontInformation);
    l_information->setGeometry(0, 0, 300, 200);
    l_information->setText(dataDocument);

    QFont fontPage("Times New Roman", 14);
    countPage->setFont(fontPage);
    countPage->setGeometry(350, 0, 30, 30);

    // Adding a page with document information
    ui->stackedWidget->addWidget(page);

    updateCountPage();
}

void SecondWindow::updateCountPage()
{
    int currentPage = ui->stackedWidget->currentIndex() + 1;
    int totalPages = ui->stackedWidget->count();
    QString countPageText = QString::number(currentPage) + "/" + QString::number(totalPages);;
    countPage->setText(countPageText);
}

void SecondWindow::onNextClicked()
{
    // Check for an existing next page
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
    // Check for an existing previous page
    int currentIndex = ui->stackedWidget->currentIndex();
    if (currentIndex > 0)
    {
        ui->stackedWidget->setCurrentIndex(currentIndex - 1);
        updateCountPage();
    }
}
