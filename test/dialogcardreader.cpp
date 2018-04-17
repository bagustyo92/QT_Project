#include "dialogcardreader.h"
#include "ui_dialogcardreader.h"
#include <QPixmap>

DialogCardReader::DialogCardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCardReader)
{
    ui->setupUi(this);
    this->setFixedSize(500, 500);
    QPixmap pix(":/resources/img/payment-method.png");
    int w = ui->labelPicture->width();
    int h = ui->labelPicture->height();
    ui->labelPicture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

DialogCardReader::~DialogCardReader()
{
    delete ui;
}
