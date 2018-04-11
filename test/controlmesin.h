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


    void on_listNomerMesin_currentIndexChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::ControlMesin *ui;
};

#endif // CONTROLMESIN_H
