#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readerdialog.h"
#include "controlmesin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readerDialog = new ReaderDialog(this);
    controlMesin = new ControlMesin(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_cuciSetrika_clicked()
{
    readerDialog->setLabelText("CUCI SETRIKA");
    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    readerDialog->setLabelText("CUCI LIPAT");
    readerDialog->exec();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    readerDialog->setLabelText("CUCI KERING");
    readerDialog->exec();
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    controlMesin->exec();
}
