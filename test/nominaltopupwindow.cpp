#include "nominaltopupwindow.h"
#include "ui_nominaltopupwindow.h"
#include <QMessageBox>
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
    ui->pushButton_150rb->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_200rb->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_300rb->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_500rb->setStyleSheet(BUTTON_COLOR);

    getTapReader = new MainWindow(this);
    getConnection = new SocketConnectELM(this);
}

NominalTopUpWindow::~NominalTopUpWindow()
{
    delete ui;
}

int nominal_topUp;

void NominalTopUpWindow::konfirmasi(){
    QString str_nominal = QString::number(nominal_topUp);
    if (str_nominal.size() == 5){
        str_nominal.insert(2, ".");
    } else {
        str_nominal.insert(3, ".");
    }
    QMessageBox *msgBoxKonfirmasi = new QMessageBox (QMessageBox::Question, "Title", "Apakah anda yakin ingin melakukan\nTOP-UP SEBESAR Rp " + str_nominal + ",- ?",
                                                     QMessageBox::Yes | QMessageBox::No, this, Qt::FramelessWindowHint);
    msgBoxKonfirmasi->setStyleSheet(QMESSAGEBOX_STYLE);
    if (msgBoxKonfirmasi->exec() == QMessageBox::Yes){
        //sent MESSAGE TO SERVER
        char * msg = "TOP_UP";
        getConnection->StartConnection(msg);
        getTapReader->onStatusConnect();
        close();
    } else {
        qDebug() << "No Confirmation Data New Memeber";
    }
}

void NominalTopUpWindow::on_pushButton_20rb_clicked()
{
    nominal_topUp = 20000;
    konfirmasi();
}

void NominalTopUpWindow::on_pushButton_50rb_clicked()
{
    nominal_topUp = 50000;
    konfirmasi();
}

void NominalTopUpWindow::on_pushButton_100rb_clicked()
{
    nominal_topUp = 100000;
    konfirmasi();
}

void NominalTopUpWindow::on_pushButton_150rb_clicked()
{
    nominal_topUp = 150000;
    konfirmasi();
}

void NominalTopUpWindow::on_pushButton_200rb_clicked()
{
    nominal_topUp = 200000;
    konfirmasi();
}

void NominalTopUpWindow::on_pushButton_300rb_clicked()
{
    nominal_topUp = 300000;
    konfirmasi();
}

void NominalTopUpWindow::on_pushButton_500rb_clicked()
{
    nominal_topUp = 500000;
    konfirmasi();
}

int NominalTopUpWindow::getNominalTopUp(){
    return nominal_topUp;
}


void NominalTopUpWindow::on_pushButton_keluar_clicked()
{

}
