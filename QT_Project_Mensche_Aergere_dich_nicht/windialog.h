#ifndef WINDIALOG_H
#define WINDIALOG_H

#include <QDialog>

namespace Ui {
class WinDialog;
}

class WinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinDialog(QWidget *parent = 0);
    ~WinDialog();

private slots:
    void on_Back_to_menu_Button_clicked();

private:
    Ui::WinDialog *ui;
};

#endif // WINDIALOG_H
