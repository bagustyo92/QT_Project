#ifndef PENDAFTARANWINDOW_H
#define PENDAFTARANWINDOW_H

#include <QMainWindow>
#include <dialogcardreader.h>

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
    void on_nextButton_clicked();

private:
    Ui::PendaftaranWindow *ui;
    DialogCardReader *tapCardDialog;
};

#endif // PENDAFTARANWINDOW_H
