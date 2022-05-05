#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"
#include "httpclient.h"

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
private slots:
    void goButton(); //from GUI-widget
    void showResult(quint16 port, bool status); //from Scanner
    void on_goButton_clicked();
};

#endif // GUI_H


