#ifndef CARDFILE_H
#define CARDFILE_H

#include <QString>
#include <QDate>

class CardFile
{
public:
    CardFile();
    CardFile(const QString& type, const QString& name, const QString& author, const QDate& date, const QString& address);

    QString getTypeDocument() const;
    void setTypeDocument(const QString &type);

    QString getNameDocument() const;
    void setNameDocument(const QString &name);

    QString getAuthorDocument() const;
    void setAuthorDocument(const QString &author);

    QString getAddressLibrary() const;
    void setAddressLibrary(const QString &address);

    QDate getCreationDate() const;
    void setCreationDate(const QDate &date);

    bool operator==(const CardFile &other) const;
private:
    QString typeDocument;
    QString nameDocument;
    QString authorDocument;
    QString addressLibrary;
    QDate creationDate;
};

#endif // CARDFILE_H
