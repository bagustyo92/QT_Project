#include "controlmesin.h"
#include "ui_controlmesin.h"

ControlMesin::ControlMesin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlMesin)
{
    ui->setupUi(this);

    for (int i=1; i<=10; i++){
        ui->listNomerMesin->addItem("Item " + QString::number(i));
        ui->listResi->addItem("Item " + QString::number(i));
    }
}

ControlMesin::~ControlMesin()
{
    delete ui;
}
