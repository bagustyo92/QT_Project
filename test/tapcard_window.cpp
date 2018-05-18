#include "tapcard_window.h"
#include "ui_tapcard_window.h"
#include <socketconnectelm.h>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"

TapCard_Window::TapCard_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TapCard_Window)
{
//    SocketConnectELM *getConnection = new SocketConnectELM(this);

    ui->setupUi(this);
    ui->back_button->setStyleSheet(BUTTON_COLOR);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->label_logo->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    ui->label_action->setText("SILAHKAN TEMPELKAN KARTU ANDA!");

    getConnection = new SocketConnectELM(this);
}

void TapCard_Window::onServerReplying(){
    if (getConnection->getMessage() != "OK" && getConnection->getMessage() != ""){
        if (getConnection->getMessage() == "KARTU TIDAK DIKENAL"){
//            QMessageBox reply (QMessageBox::Warning, "PERINGATAN..!", "Kartu yang Anda TAP TIDAK DIKENAL!",
//                               QMessageBox::Ok, this, Qt::FramelessWindowHint);
//            reply.exec();
            qDebug() << "INI HALLO";
            QMessageBox *msgBoxKonfirmasi = new QMessageBox (QMessageBox::Information, "Title", "Kartu yang anda TAP TIDAK DIKENAL!",
                                                             QMessageBox::Ok, this, Qt::FramelessWindowHint);
            if (msgBoxKonfirmasi->exec() == QMessageBox::Ok){
                close();
            }
        } else {
//            status_close = true;
//            readerDialog = new ReaderDialog(this);
//            readerDialog->setLabelText(getConnection->getMessage(), 2);
//            readerDialog->exec();
        }
    }
}

void TapCard_Window::on_back_button_clicked()
{
    char *msg = "cancel";
    getConnection->StartConnection(msg);
    qDebug() << "Cancel Choosing Packet!";
}

TapCard_Window::~TapCard_Window()
{
    delete ui;
}
