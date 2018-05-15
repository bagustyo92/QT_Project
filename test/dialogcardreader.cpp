#include "dialogcardreader.h"
#include "ui_dialogcardreader.h"
#include "mainwindow.h"
#include "controlmesin.h"
#include <pendaftaranwindow.h>
#include <QMessageBox>
#include <QPushButton>
#include <QPixmap>
#include <QMovie>
#include <QThread>
#include <QVector>

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

    ui->labelPicture->setText("SILAHKAN TEMPELKAN KARTU ANDA!");

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

        if (getConnection->getMessage() == "ADD MEMBER SUKSES"){
            ControlMesin *database = new ControlMesin(this);
            MainWindow *mainWindow = new MainWindow(this);
            PendaftaranWindow *memberData = new PendaftaranWindow(this);

            QVector <QString> db_setup;
            QVector <QString> new_member;
            QString uid_card;
//            QString nama,tglLahir, alamat, kelurahan, kecamatan, email, noHape;

            new_member = memberData->get_member_data();
            uid_card = getConnection->getMessage();
            if (uid_card != ""){
                new_member.append(uid_card);
            } else {
                qDebug() << "Failed get UID_CARD from the server";
                QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Kartu GAGAL ditambahkan! Silahkan coba lagi!",
                                   QMessageBox::Ok, this, Qt::FramelessWindowHint);
                msgBox.exec();
                this->close();
            }

            db_setup = mainWindow->read_database_file();
            if (!database->database_connect(db_setup[0], db_setup[1], db_setup[3], db_setup[4], db_setup[2])){
        //        QMessageBox::warning(this, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke DATABASE");
                QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "GAGAL Menghubungkan GUI ke DATABASE!",
                                   QMessageBox::Ok, this, Qt::FramelessWindowHint);
                msgBox.exec();
            } else {
                database->database_set_new_member(new_member);
//                controlMesin->showFullScreen();
            }
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
//    QMovie *movie = new QMovie(":/resources/img/Spinner-black.gif");
//    ui->loadingGIF->setMovie(movie);
//    movie->start();
//    qApp->processEvents();
//    QThread::sleep(2);
    char *val = "cancel";
    getConnection = new SocketConnectELM(this);
    getConnection->StartConnection(val);
    qDebug() << "cancel choosing packet";
}
