#include "cardfile.h"

CardFile::CardFile() {}

CardFile::CardFile(const QString &type, const QString &name, const QString &author, const QDate &date, const QString &address)
{
    setTypeDocument(type);
    setNameDocument(name);
    setAuthorDocument(author);
    setCreationDate(date);
    setAddressLibrary(address);
}

QString CardFile::getTypeDocument() const
{
    return typeDocument;
}

void CardFile::setTypeDocument(const QString &type)
{
    typeDocument = type;
}

QString CardFile::getNameDocument() const
{
    return nameDocument;
}

void CardFile::setNameDocument(const QString &name)
{
    nameDocument = name;
}

QString CardFile::getAuthorDocument() const
{
    return authorDocument;
}

void CardFile::setAuthorDocument(const QString &author)
{
    authorDocument = author;
}

QString CardFile::getAddressLibrary() const
{
    return addressLibrary;
}

void CardFile::setAddressLibrary(const QString &address)
{
    addressLibrary = address;
}

QDate CardFile::getCreationDate() const
{
    return creationDate;
}

void CardFile::setCreationDate(const QDate &date)
{
    creationDate = date;
}

bool CardFile::operator==(const CardFile &other) const
{
    return typeDocument == other.typeDocument &&
           nameDocument == other.nameDocument &&
           authorDocument == other.authorDocument &&
           creationDate == other.creationDate &&
           addressLibrary == other.addressLibrary;
}
