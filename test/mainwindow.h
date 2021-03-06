#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controlmesin.h"
#include "socketconnectelm.h"
#include "dialogcardreader.h"
#include "pendaftaranwindow.h"
#include "tapcard_window.h"
#include <QTimer>
#include <QVector>

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
    QVector <QString> read_database_file();
    QString getTitle();
    ~MainWindow();

private slots:
    void on_pushButton_cuciSetrika_clicked();
    void on_pushButton_cuciLipat_clicked();
    void on_pushButton_cuciKering_clicked();
    void on_pushButton_controlMesin_clicked();
    void on_pushButton_addMemberCard_clicked();
    void onTimeChanged();

    void on_pushButton_topUpSaldo_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    SocketConnectELM *socketConnect;
    ControlMesin *controlMesin;
    DialogCardReader *cardReader;
    PendaftaranWindow *daftarWindow;
    TapCard_Window *tap;
};

#endif // MAINWINDOW_H
