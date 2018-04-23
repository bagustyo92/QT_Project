#include "dialogcardreader.h"
#include "ui_dialogcardreader.h"
#include <QMessageBox>
#include <QPushButton>

#define BUTTON_COLOR "background-color:rgb(246, 0, 107); color:white; font-weight: bold;"

class MainWindow;

DialogCardReader::DialogCardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCardReader)
{
    ui->setupUi(this);
    ui->backButton->setStyleSheet(BUTTON_COLOR);

    QPixmap pix(":/resources/img/payment-method.png");
    int w = ui->labelPicture->width();
    int h = ui->labelPicture->height();
    ui->labelPicture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->nextButton->setEnabled(false);
}

void DialogCardReader::onServerReply(QString message){
    //    SocketConnectELM socket;
    getConnection = new SocketConnectELM(this);
    if (getConnection->getMessage() != "OK" && getConnection->getMessage() != ""){
        if (getConnection->getMessage() == "KARTU TIDAK DIKENAL"){
            QMessageBox::warning(this, "PERINGATAN..!","Kartu yang Anda TAP TIDAK DIKENAL!");
        } else {
            readerDialog = new ReaderDialog(this);
            readerDialog->setLabelText(getConnection->getMessage(), 2);
            readerDialog->exec();
        }
    }
}


DialogCardReader::~DialogCardReader()
{
    delete ui;
}
