#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QByteArray>

bool TextNumberCheck(const QString &data, int index)
{
    return data[index].isLetter();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString word;
    QString text;
    QList<QString> swearWords;
    bool middle = false;

    QFile file("inputFile.txt");
    QFile outfile("outputFile.txt");
    QFile swearWordsFile("swearWordsFile.txt");

    if (!file.exists() || !swearWordsFile.exists())
    {
        qDebug() << "Files does not exist, there is nothing to read";
        return 0;
    }
    else if (file.open(QIODevice::ReadOnly | QIODevice::Text) && swearWordsFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Files successfully opened";
    }
    else
    {
        qDebug() << "Files do not open";
        return 0;
    }

    text = file.readAll();

    while (!swearWordsFile.atEnd())
    {
        QString line = swearWordsFile.readLine().trimmed();
        if (!line.isEmpty())
        {
            swearWords.append(line.toLower());
        }
    }
    file.close();
    swearWordsFile.close();

    for (int index = 0; index < text.length(); index++)
    {
        if (TextNumberCheck(text, index))
        {
            word.append(text[index]);
            if (!middle)
            {
                middle = true;
            }
        }
        else
        {
            if (middle)
            {
                middle = false;
                QString lowerWord = word.toLower();
                if (swearWords.contains(lowerWord))
                {
                    int countStar = word.length();
                    QString star;
                    for (int index = countStar; index > 0; index--)
                    {
                        star += "*";
                    }
                    text.replace(word, star);
                }
                word.clear();
            }
        }
    }

    if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "File does not open to writing";
    }
    else
    {
        qDebug() << "File successfully opened for writing";

        QByteArray byteArray = text.toUtf8();

        outfile.write(byteArray);

        outfile.close();
    }

    return a.exec();
}
