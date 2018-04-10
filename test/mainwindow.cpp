#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readerdialog.h"

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
    changeWindow();
}

void MainWindow::on_pushButton_cuciLipat_clicked()
{
    changeWindow();
}

void MainWindow::on_pushButton_cuciKering_clicked()
{
    changeWindow();
}
