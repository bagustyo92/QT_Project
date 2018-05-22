#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "nominaltopupwindow.h"
#include "controlmesin.h"
#include "mainwindow.h"
#include <QCryptographicHash>
#include <QPixmap>
#include <QMessageBox>

#define BUTTON_COLOR "background-color:rgb(191, 210, 214); color:rgb(108, 167, 191); font-weight: bold;"
#define QMESSAGEBOX_STYLE "QLabel{color:rgb(108,167,191); font-weight:bold; font-size:20px; min-height:200px;} QPushButton{width:200 px; font-size:18px}"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/resources/img/Kain Wangi logo.png");
    ui->label_logo->setPixmap(pix.scaled(380,380, Qt::KeepAspectRatio));

    ui->pushButton_back->setStyleSheet(BUTTON_COLOR);
    ui->pushButton_login->setStyleSheet(BUTTON_COLOR);
    ui->lineEdit_username->setPlaceholderText("username");
    ui->lineEdit_password->setPlaceholderText("password");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

QString username, login_status;

void LoginWindow::on_pushButton_login_clicked()
{

    MainWindow *getMainWindow = new MainWindow(this);
    ControlMesin *getDatabase = new ControlMesin(this);
    QVector <QString> username_pwd, db_setup;

    username = ui->lineEdit_username->text();
    username_pwd.append(username);
    username_pwd.append(encrypt_password());

    db_setup = getMainWindow->read_database_file();
    if (!getDatabase->database_connect(db_setup[0], db_setup[1], db_setup[3], db_setup[4], db_setup[2])){
        QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "DATABASE TIDAK TERHUBUNG!\n\nSilahkan matikan dan nyalakan kembali CASHIER!",
                           QMessageBox::Ok, 0, Qt::FramelessWindowHint);
        msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
        msgBox.exec();
    } else {
        login_status = getDatabase->database_user_login(username_pwd);
        if (login_status == "OK LOGIN"){
            NominalTopUpWindow *getNominalTopUpWindow = new NominalTopUpWindow(this);
            getNominalTopUpWindow->showFullScreen();
            close();
        } else if (login_status == "GAGAL LOGIN"){
            QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "USERNAME atau PASSWORD yang anda masukan SALAH!\nSilahkan cek kembali USERNAME atau PASSWORD anda!",
                               QMessageBox::Ok, 0, Qt::FramelessWindowHint);
            msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
            msgBox.exec();
        } else {
            QMessageBox msgBox(QMessageBox::Warning, "PERINGATAN..!", "GAGAL melakukan LOGIN!\nSilahkan COBA LAGI atau MATIKAN dan NYALAKAN KEMBALI CASHIER!",
                               QMessageBox::Ok, 0, Qt::FramelessWindowHint);
            msgBox.setStyleSheet(QMESSAGEBOX_STYLE);
            msgBox.exec();
        }
    }
}

QString LoginWindow::encrypt_password(){
    QCryptographicHash hasher (QCryptographicHash::Sha256);
    QByteArray password = ui->lineEdit_password->text().toLocal8Bit();
    hasher.addData(password);
    QString result = hasher.result().toHex();
    return result;
}

QString LoginWindow::getUserName(){
    return username;
}

void LoginWindow::on_lineEdit_password_returnPressed()
{
    on_pushButton_login_clicked();
}
