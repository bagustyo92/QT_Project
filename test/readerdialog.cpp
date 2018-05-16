#include "readerdialog.h"
#include "ui_readerdialog.h"
#include "mainwindow.h"

#define BUTTON_BACK "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"

ReaderDialog::ReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReaderDialog)
{
    ui->setupUi(this);

    ui->backButton->setStyleSheet(BUTTON_BACK);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    getConnection = new SocketConnectELM(this);
    qDebug() << "read : " << getConnection->getMessage();
    if (getConnection->getMessage() != "OK" && getConnection->getMessage() != ""){
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
        ui->paymentStatusLabel->setText("STATUS TRANSAKSI PAKET " + val + " : ");
        break;
    case 2:
        ui->labelCurrentBalance->setText(val);
        break;
    default:
        break;
    }
}

ReaderDialog::~ReaderDialog()
{
    delete ui;
}
