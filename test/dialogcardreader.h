#ifndef DIALOGCARDREADER_H
#define DIALOGCARDREADER_H

#include <QDialog>
#include "socketconnectelm.h"
#include <QPixmap>
#include "readerdialog.h"
#include "QDebug"


namespace Ui {
class DialogCardReader;
}

class DialogCardReader : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCardReader(QWidget *parent = 0);
    void onServerReply();
    ~DialogCardReader();

private slots:
    void on_backButton_clicked();

private:
    Ui::DialogCardReader *ui;
    void show_server_reply();
    SocketConnectELM *getConnection;
    ReaderDialog *readerDialog;
};

#endif // DIALOGCARDREADER_H
