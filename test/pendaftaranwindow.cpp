#include "pendaftaranwindow.h"
#include "ui_pendaftaranwindow.h"
#include <QDateEdit>
#include <QProcess>

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
void PendaftaranWindow::on_lineEdit_Name_returnPressed()
{
    QProcess *process = new QProcess();
    process->start("/var/kainwangi/start_keyboard.sh");
    process->waitForFinished();
    delete process;
}
