#include "readerdialog.h"
#include "ui_readerdialog.h"
#include "mainwindow.h"

ReaderDialog::ReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReaderDialog)
{
    ui->setupUi(this);
}

ReaderDialog::~ReaderDialog()
{
    delete ui;
}
