#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readerdialog.h"
#include "controlmesin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void changeWindow()
{
    ReaderDialog readerDialog;
    readerDialog.setModal(true);
    readerDialog.exec();
}

void MainWindow::on_pushButton_cuciSetrika_clicked()
{
//    ReaderDialog readerDialog;
    changeWindow();
//    connect(ui->pushButton_cuciSetrika, SIGNAL(clicked(bool)), readerDialog
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    changeWindow();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    changeWindow();
}

void MainWindow::on_pushButton_controlMesin_clicked()
{
    ControlMesin controlMesin;
    controlMesin.setModal(true);
    controlMesin.exec();

}
