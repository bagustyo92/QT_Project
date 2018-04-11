#include "controlmesin.h"
#include "ui_controlmesin.h"

ControlMesin::ControlMesin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlMesin)
{
    ui->setupUi(this);
    this->setFixedSize(500, 500);
    for (int i=1; i<=10; i++){
        ui->listNomerMesin->addItem("Item " + QString::number(i));
        ui->listResi->addItem("Item " + QString::number(i));
    }
    ui->pushButton_cuci->setDisabled(true);
    ui->pushButton_kering->setDisabled(true);
}



ControlMesin::~ControlMesin()
{
    delete ui;
}

void ControlMesin::on_listNomerMesin_currentIndexChanged(const QString &arg1)
{
    ui->pushButton_cuci->setDisabled(false);
    ui->pushButton_kering->setDisabled(false);
}

void ControlMesin::on_pushButton_3_clicked()
{
    ui->pushButton_cuci->setDisabled(true);
    ui->pushButton_kering->setDisabled(true);
}

void ControlMesin::on_pushButton_kering_clicked()
{
//    some Action Here
}

void ControlMesin::on_pushButton_cuci_clicked()
{
//    some action here
}
