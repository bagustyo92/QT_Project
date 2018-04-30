#ifndef CONTROLMESIN_H
#define CONTROLMESIN_H

#include <QDialog>
#include <QtSql/QSqlDatabase>

namespace Ui {
class ControlMesin;
}

class ControlMesin : public QDialog
{
    Q_OBJECT

public:
    explicit ControlMesin(QWidget *parent = 0);
    bool database_connect();
    void database_get_list_mesin();
    void database_get_list_pending_transaksi();
    ~ControlMesin();


private slots:


    void on_listNomerMesin_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_kering_clicked();

    void on_pushButton_cuci_clicked();

private:
    void database_control_mesin_action(int);
    Ui::ControlMesin *ui;
};

#endif // CONTROLMESIN_H
