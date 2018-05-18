#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "dialogcardreader.h"
#include "socketconnectelm.h"
#include "mainwindow.h"
#include <QPixmap>

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

void LoginWindow::on_pushButton_login_clicked()
{
    SocketConnectELM *getConnection = new SocketConnectELM(this);
    MainWindow *getMainWindow = new MainWindow(this);

    char * msg = "LOGIN";

    getConnection->StartConnection(msg);
    getMainWindow->onStatusConnect();
    close();
}
