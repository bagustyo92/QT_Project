#include "nominaltopupwindow.h"
#include "ui_nominaltopupwindow.h"
#include <QPixmap>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"
#define QMESSAGEBOX_STYLE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:20px; min-height:200px;} QPushButton{width:200 px; font-size:18px}"

NominalTopUpWindow::NominalTopUpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NominalTopUpWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->label_logo->setPixmap(pix.scaled(380,380, Qt::KeepAspectRatio));

    ui->pushButton_keluar->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_20rb->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_50rb->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_100rb->setStyleSheet(BUTTON_COLOR);

    getTapReader = new MainWindow(this);
    getConnection = new SocketConnectELM(this);
}

NominalTopUpWindow::~NominalTopUpWindow()
{
    delete ui;
}

char * nominal;

void NominalTopUpWindow::on_pushButton_20rb_clicked()
{
    nominal = "20000";
    getConnection->StartConnection(nominal);
    getTapReader->onStatusConnect();
}

void NominalTopUpWindow::on_pushButton_50rb_clicked()
{
    nominal = "50000";
    getConnection->StartConnection(nominal);
    getTapReader->onStatusConnect();
}

void NominalTopUpWindow::on_pushButton_100rb_clicked()
{
    nominal = "100000";
    getConnection->StartConnection(nominal);
    getTapReader->onStatusConnect();
}

void NominalTopUpWindow::on_pushButton_keluar_clicked()
{

}
