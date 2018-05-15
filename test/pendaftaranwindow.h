#ifndef PENDAFTARANWINDOW_H
#define PENDAFTARANWINDOW_H

#include <QMainWindow>
#include <dialogcardreader.h>
#include <socketconnectelm.h>

namespace Ui {
class PendaftaranWindow;
}

class PendaftaranWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PendaftaranWindow(QWidget *parent = 0);
    QVector <QString> get_member_data();
    ~PendaftaranWindow();

private slots:
    void on_nextButton_clicked();

private:
    Ui::PendaftaranWindow *ui;
    DialogCardReader *tapCardDialog;
    SocketConnectELM *connectingElm;
};

#endif // PENDAFTARANWINDOW_H
