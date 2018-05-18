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
    ~NominalTopUpWindow();

private slots:
    void on_pushButton_20rb_clicked();
    void on_pushButton_50rb_clicked();
    void on_pushButton_100rb_clicked();
    void on_pushButton_keluar_clicked();

private:
    Ui::NominalTopUpWindow *ui;
    MainWindow *getTapReader;
    SocketConnectELM *getConnection;
};

#endif // NOMINALTOPUPWINDOW_H
