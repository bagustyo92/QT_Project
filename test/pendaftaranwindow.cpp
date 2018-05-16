#include "pendaftaranwindow.h"
#include "ui_pendaftaranwindow.h"
#include "mainwindow.h"
#include <QDateEdit>
#include <QDebug>
#include <QMessageBox>
#include <WidgetKeyboard.h>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"

PendaftaranWindow::PendaftaranWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PendaftaranWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->pictureLabel->setPixmap(pix.scaled(250, 250, Qt::KeepAspectRatio));

    ui->backButton->setStyleSheet(BUTTON_COLOR);
    ui->nextButton->setStyleSheet(BUTTON_COLOR);

    QDateTime dt = QDateTime::currentDateTime();

    ui->dateEdit->setDisplayFormat("yyyy/MM/dd");
    ui->dateEdit->setDateTime(dt);
}

PendaftaranWindow::~PendaftaranWindow()
{
    delete ui;
}

QVector <QString> new_member;
QString nama,tglLahir, alamat, kelurahan, kecamatan, email, noHape;

void PendaftaranWindow::on_nextButton_clicked()
{
    nama = ui->lineEdit_Name->text();
    new_member.append(nama);
    tglLahir = ui->dateEdit->text();
    new_member.append(tglLahir);
    alamat = ui->lineEdit_Alamat->text();
    new_member.append(alamat);
    kelurahan = ui->lineEdit_kelurahan->text();
    new_member.append(kelurahan);
    kecamatan = ui->lineEdit_kecamatan->text();
    new_member.append(kecamatan);
    email = ui->lineEdit_email->text();
    new_member.append(email);
    noHape = ui->lineEdit_nohape->text();
    new_member.append(noHape);

    QRegExp regExp("\\d*");
    bool emailStat = false;

    if (nama == "" || tglLahir == "" || alamat == "" || kelurahan == "" || kecamatan == "" || email == "" || noHape == ""){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Seluruh kolom TIDAK BOLEH KOSONG!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "All field must be NOT EMPTY!";
        emailStat = true;
    } else if (!email.contains("@") && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format E-MAIL yang anda masukan SALAH!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "email field is wrong!";
    } else if (!email.contains(".") && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format E-MAIL yang anda masukan SALAH!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "email field is wrong2!";
    } else if (!regExp.exactMatch(noHape) && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Format NOMER HP yang anda masukan SALAH!\nFormat masukan HARUS ANGKA!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "number field is wrong";
    } else {
        qDebug() << "Data Correct!";

        char *msg = "ADD_MEMBER";
        connectingElm = new SocketConnectELM(this);
        MainWindow *mainWindow = new MainWindow(this);

        connectingElm->StartConnection(msg);
        mainWindow->onStatusConnect();
    }
}

QVector <QString> PendaftaranWindow::get_member_data(){
    return new_member;
}

