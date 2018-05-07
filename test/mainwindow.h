#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controlmesin.h"
#include "socketconnectelm.h"
#include "dialogcardreader.h"
#include "pendaftaranwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void connectingToElm(char *paket);
    void onServerReply(QString);
    void onStatusConnect();
    QString getTitle();
    ~MainWindow();

private slots:
    void on_pushButton_cuciSetrika_clicked();
    void on_pushButton_cuciLipat_clicked();
    void on_pushButton_cuciKering_clicked();
    void on_pushButton_controlMesin_clicked();

    void on_pushButton_addMemberCard_clicked();

private:
    Ui::MainWindow *ui;
    SocketConnectELM *socketConnect;
    ControlMesin *controlMesin;
    DialogCardReader *cardReader;
    PendaftaranWindow *daftarWindow;
};

#endif // MAINWINDOW_H
