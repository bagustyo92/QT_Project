#ifndef READERDIALOG_H
#define READERDIALOG_H

#include <QDialog>

namespace Ui {
class ReaderDialog;
}

class ReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReaderDialog(QWidget *parent = 0);
    ~ReaderDialog();
    setLabelText(const QString text);

private:
    Ui::ReaderDialog *ui;
};

#endif // READERDIALOG_H
