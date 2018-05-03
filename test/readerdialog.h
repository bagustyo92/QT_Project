#ifndef READERDIALOG_H
#define READERDIALOG_H

#include <QDialog>
#include <QWidget>
#include "socketconnectelm.h"

namespace Ui {
class ReaderDialog;
}

class ReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReaderDialog(QWidget *parent = 0);

    ~ReaderDialog();

public slots :
    void setLabelText(QString val, int label);


private slots:
    void on_backButton_clicked();

    void on_reprint_button_clicked();

private:
    Ui::ReaderDialog *ui;
    SocketConnectELM *getConnection;
};

#endif // READERDIALOG_H
