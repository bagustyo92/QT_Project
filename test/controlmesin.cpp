#include "controlmesin.h"
#include "ui_controlmesin.h"
#include <QMessageBox>
#include <QDebug>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:white; font-weight: bold;"

ControlMesin::ControlMesin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlMesin)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    for (int i=1; i<=10; i++){
        ui->listNomerMesin->addItem("Mesin " + QString::number(i));
        ui->listResi->addItem("Mesin " + QString::number(i));
    }
    ui->pushButton_cuci->setDisabled(true);
    ui->pushButton_kering->setDisabled(true);

    ui->listNomerMesin->setStyleSheet(BUTTON_COLOR);
    ui->listResi->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_3->setStyleSheet(BUTTON_COLOR);
}



ControlMesin::~ControlMesin()
{
    delete ui;
}


void ControlMesin::on_listNomerMesin_activated(const QString &arg1)
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
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Konfirmasi Pengeringan " +
                                                              ui->listNomerMesin->currentText(),
                                                              "Apakah anda yakin ingin melakukan \nPENGERINGAN pada "
                                                              + ui->listNomerMesin->currentText() + "?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply==QMessageBox::Yes){
        //Some Action Here
    } else {
        //Some Action Here
        qDebug() << "Cancel on button kering";
    }
}

void ControlMesin::on_pushButton_cuci_clicked()
{
//    some action here
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Konfirmasi Pencucian " +
                                                              ui->listNomerMesin->currentText(),
                                                              "Apakah anda yakin ingin melakukan \nPENCUCIAN pada "
                                                              + ui->listNomerMesin->currentText() + "?",
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes){
        //Some Action Here
    } else {
        //Some Action Here
        qDebug() << "Cancel on button cuci";
    }
}
