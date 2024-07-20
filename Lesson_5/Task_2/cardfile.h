#ifndef CARDFILE_H
#define CARDFILE_H

#include <QString>

class CardFile
{
public:
    CardFile();
    CardFile(const QString& type, const QString& name, const QString& author, const int& date, const QString& address);

    QString getTypeDocument() const;
    void setTypeDocument(const QString &type);

    QString getNameDocument() const;
    void setNameDocument(const QString &name);

    QString getAuthorDocument() const;
    void setAuthorDocument(const QString &author);

    QString getAddressLibrary() const;
    void setAddressLibrary(const QString &address);

    int getCreationDate() const;
    void setCreationDate(const int &date);

    bool operator==(const CardFile &other) const;
private:
    QString typeDocument;
    QString nameDocument;
    QString authorDocument;
    QString addressLibrary;
    int creationDate;
};

#endif // CARDFILE_H
