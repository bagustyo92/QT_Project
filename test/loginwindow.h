#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    QString getUserName();
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_lineEdit_password_returnPressed();

private:
    Ui::LoginWindow *ui;
    QString encrypt_password();
};

#endif // LOGINWINDOW_H
