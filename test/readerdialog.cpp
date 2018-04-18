#include "readerdialog.h"
#include "ui_readerdialog.h"
#include "mainwindow.h"

ReaderDialog::ReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReaderDialog)
{
    ui->setupUi(this);
    getConnection = new SocketConnectELM(this);
    qDebug() << "read : " << getConnection->getMessage();
    if (getConnection->getMessage() == "NO"){
        this->showFullScreen();
    }
    MainWindow mainWindow;
    setLabelText(QString(mainWindow.getTitle()), 1);
}

/*
 * Label Documentation
 * 1. title
 * 2. ballance
 * 3. paket
 */
void ReaderDialog::setLabelText(QString val, int label)
{
    if (val == ""){
        val = "SILAHKAN TAP KARTU!";
    }
    switch (label) {
    case 1:
        ui->labelTitle->setText(val);
        break;
    case 2:
        ui->labelCurrentBalance->setText(val);
        break;
    case 3:
        ui->labelPaket->setText(val);
        break;
    default:
        break;
    }
}

ReaderDialog::~ReaderDialog()
{
    delete ui;
}
