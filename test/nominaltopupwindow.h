#ifndef NOMINALTOPUPWINDOW_H
#define NOMINALTOPUPWINDOW_H

#include "mainwindow.h"
#include "socketconnectelm.h"
#include <QMainWindow>

namespace Ui {
class NominalTopUpWindow;
}

class NominalTopUpWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NominalTopUpWindow(QWidget *parent = 0);
    int getNominalTopUp();
    ~NominalTopUpWindow();

private slots:
    void on_pushButton_20rb_clicked();
    void on_pushButton_50rb_clicked();
    void on_pushButton_keluar_clicked();
    void on_pushButton_100rb_clicked();
    void on_pushButton_150rb_clicked();
    void on_pushButton_200rb_clicked();
    void on_pushButton_300rb_clicked();
    void on_pushButton_500rb_clicked();

private:
    Ui::NominalTopUpWindow *ui;
    MainWindow *getTapReader;
    SocketConnectELM *getConnection;
    void konfirmasi();
};

#endif // NOMINALTOPUPWINDOW_H
