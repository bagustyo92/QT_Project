#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readerdialog.h"
#include "controlmesin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_cuciSetrika_clicked();
    void on_pushButton_cuciLipat_clicked();
    void on_pushButton_cuciKering_clicked();
    void on_pushButton_controlMesin_clicked();

private:
    Ui::MainWindow *ui;
    ReaderDialog *readerDialog;
    Ui::ReaderDialog *ui_readerDialog;
    ControlMesin *controlMesin;
    Ui::ControlMesin *ui_controlMesin;
};

#endif // MAINWINDOW_H
