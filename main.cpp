#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    HttpClient server;
    try {
        server.start();
        qDebug() << "server started";
    } catch(QString& str) {
        qDebug() << str;
        return 1;
    }
    return a.exec();
}

