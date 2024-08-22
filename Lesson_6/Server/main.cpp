#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server myserver;
    myserver.start(8081);
    return a.exec();
}
