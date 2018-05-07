#include "pendaftaranwindow.h"
#include "ui_pendaftaranwindow.h"

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

}

PendaftaranWindow::~PendaftaranWindow()
{
    delete ui;
}
