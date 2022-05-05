#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Gui::on_goButton_clicked()
{
    QString host = hostEntry->text();

}

void Gui::showResult(quint16 port, bool status)
{
    qDebug() << port << status;
    QString msg = (status == true) ? "open" : "close";
    QString result = QString::number(port) + "->" + msg;
    resultBrowser->append(result);
}


