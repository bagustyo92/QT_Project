#include "dialogcardreader.h"
#include "ui_dialogcardreader.h"

class MainWindow;

DialogCardReader::DialogCardReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCardReader)
{
    ui->setupUi(this);
//    this->setFixedSize(500, 500);

    QPixmap pix(":/resources/img/payment-method.png");
    int w = ui->labelPicture->width();
    int h = ui->labelPicture->height();
    ui->labelPicture->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->nextButton->setEnabled(false);

}

void DialogCardReader::onServerReply(QString message){
    //    SocketConnectELM socket;
    getConnection = new SocketConnectELM(this);
    if (getConnection->getMessage() != "OK" && getConnection->getMessage() != ""){
        readerDialog = new ReaderDialog(this);
//        mainWindow = new MainWindow(this);
//        readerDialog->setLabelText(QString(mainWindow->getTitle()), 1);
        readerDialog->setLabelText(getConnection->getMessage(), 2);
        readerDialog->exec();
    }
}


DialogCardReader::~DialogCardReader()
{
    delete ui;
}
