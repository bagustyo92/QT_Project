#ifndef DIALOGCARDREADER_H
#define DIALOGCARDREADER_H

#include <QDialog>

namespace Ui {
class DialogCardReader;
}

class DialogCardReader : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCardReader(QWidget *parent = 0);
    ~DialogCardReader();

private:
    Ui::DialogCardReader *ui;
    void onServerReply(QString message);
};

#endif // DIALOGCARDREADER_H
