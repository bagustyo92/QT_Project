#include "readerdialog.h"
#include "ui_readerdialog.h"
#include "mainwindow.h"

ReaderDialog::ReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReaderDialog)
{
    ui->setupUi(this);
    this->setFixedSize(500, 500);
}

void ReaderDialog::setLabelText(const QString text)
{
    ui->titleValue->setText(text);
}

ReaderDialog::~ReaderDialog()
{
    delete ui;
}
