#include "dialogcardreader.h"
#include "ui_dialogcardreader.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QPixmap>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:white; font-weight: bold;"

// TODO : Back Button sent "cancel"                     << DONE
//        Close CardDialogReader
//        Button Home Diperkecil                        << DONE
//        Logo Semua Window                             << DONE
//        Size Font Menyesuaikan                        << DONE
//        Kasih margin kiri kanan home                  << DONE
//        Current Balance dll Rata tengah dipercantik   << DONE

class MainWindow;

DialogCardReader::DialogCardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCardReader)
{
    ui->setupUi(this);
    ui->backButton->setStyleSheet(BUTTON_COLOR);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->image_label->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

    ui->labelPicture->setText("SILAHKAN TAP KARTU ANDA!");

    ui->nextButton->setEnabled(false);
}

//SocketConnectELM *getConnection = new SocketConnectELM;

bool status_close = false;
void DialogCardReader::onServerReply(){
    getConnection = new SocketConnectELM(this);
    if (getConnection->getMessage() != "OK" && getConnection->getMessage() != ""){
        if (getConnection->getMessage() == "KARTU TIDAK DIKENAL"){
            QMessageBox reply (QMessageBox::Warning, "PERINGATAN..!", "Kartu yang Anda TAP TIDAK DIKENAL!",
                               QMessageBox::Ok, this, Qt::FramelessWindowHint);
            reply.exec();
//            if (QMessageBox::Ok){
//                char *message;
//                message = "cancel";
//                getConnection->StartConnection(message);
//            }
        } else {
            status_close = true;
            readerDialog = new ReaderDialog(this);
            readerDialog->setLabelText(getConnection->getMessage(), 2);
            readerDialog->exec();
        }
    }
}

void DialogCardReader::closeDialog(){
    if (status_close){
        this->close();
    }
}

DialogCardReader::~DialogCardReader()
{
    delete ui;
}

void DialogCardReader::on_backButton_clicked()
{
    char *val = "cancel";
    getConnection = new SocketConnectELM(this);
    getConnection->StartConnection(val);
    qDebug() << "cancel choosing packet";
}
