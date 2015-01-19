#ifndef CLASSICBOARDDIALOG_H
#define CLASSICBOARDDIALOG_H

#include <QDialog>

namespace Ui {
class ClassicBoardDialog;
}

class ClassicBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClassicBoardDialog(QWidget *parent = 0);
    ~ClassicBoardDialog();

private:
    Ui::ClassicBoardDialog *ui;
};

#endif // CLASSICBOARDDIALOG_H
