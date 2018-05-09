#ifndef PENDAFTARANWINDOW_H
#define PENDAFTARANWINDOW_H

#include <QMainWindow>

namespace Ui {
class PendaftaranWindow;
}

class PendaftaranWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PendaftaranWindow(QWidget *parent = 0);
    ~PendaftaranWindow();

private slots:
    void on_lineEdit_Name_returnPressed();

private:
    Ui::PendaftaranWindow *ui;
};

#endif // PENDAFTARANWINDOW_H