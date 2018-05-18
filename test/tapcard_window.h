#ifndef TAPCARD_WINDOW_H
#define TAPCARD_WINDOW_H

#include <QMainWindow>
#include "socketconnectelm.h"

namespace Ui {
class TapCard_Window;
}

class TapCard_Window : public QMainWindow
{
    Q_OBJECT

public:
    void onServerReplying();
    explicit TapCard_Window(QWidget *parent = 0);
    ~TapCard_Window();

private slots:
    void on_back_button_clicked();

private:
    Ui::TapCard_Window *ui;
    SocketConnectELM *getConnection;
};

#endif // TAPCARD_WINDOW_H
