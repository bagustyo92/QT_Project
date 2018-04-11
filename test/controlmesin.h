#ifndef CONTROLMESIN_H
#define CONTROLMESIN_H

#include <QDialog>

namespace Ui {
class ControlMesin;
}

class ControlMesin : public QDialog
{
    Q_OBJECT

public:
    explicit ControlMesin(QWidget *parent = 0);
    ~ControlMesin();


private slots:


    void on_listNomerMesin_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_kering_clicked();

    void on_pushButton_cuci_clicked();

private:
    Ui::ControlMesin *ui;
};

#endif // CONTROLMESIN_H
