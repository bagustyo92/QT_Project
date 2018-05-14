#include "pendaftaranwindow.h"
#include "ui_pendaftaranwindow.h"
#include <QDateEdit>
#include <QDebug>
#include <QMessageBox>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:white; font-weight: bold;"

PendaftaranWindow::PendaftaranWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PendaftaranWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->pictureLabel->setPixmap(pix.scaled(380, 380, Qt::KeepAspectRatio));

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

void PendaftaranWindow::on_nextButton_clicked()
{
    QString nama = ui->lineEdit_Name->text();
    QString tglLahir = ui->dateEdit->text();
    QString alamat = ui->lineEdit_Alamat->text();
    QString kelurahan = ui->lineEdit_kelurahan->text();
    QString kecamatan = ui->lineEdit_kecamatan->text();
    QString email = ui->lineEdit_email->text();
    QString noHape = ui->lineEdit_nohape->text();
    QRegExp regExp("\\d*");
    bool emailStat = false;

    if (nama == "" || tglLahir == "" || alamat == "" || kelurahan == "" || kecamatan == "" || email == "" || noHape == ""){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "All field must be NOT EMPTY!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "All field must be NOT EMPTY!";
        emailStat = true;
    } else if (!email.contains("@") && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Email field format is WRONG!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "email field is wrong!";
    } else if (!email.contains(".") && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Email field format is WRONG!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "email field is wrong2!";
    } else if (!regExp.exactMatch(noHape) && emailStat == false){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "Number HP field is must be NUMBERS!",
                           QMessageBox::Ok, this, Qt::FramelessWindowHint);
        msgBox.exec();
        qDebug() << "number field is wrong";
    } else {
        tapCardDialog = new DialogCardReader(this);
        tapCardDialog->showFullScreen();
        qDebug() << "Data Correct!";
    }
}
