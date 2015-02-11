#ifndef LOADDIALOG_H
#define LOADDIALOG_H

#include <QDialog>

namespace Ui {
class LoadDialog;
}

class LoadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadDialog(QWidget *parent = 0, int language=0);
    ~LoadDialog();

private slots:
    void on_BackButton_clicked();

    void on_StartButton_clicked();

private:
    int language_id;
    Ui::LoadDialog *ui;
};

#endif // LOADDIALOG_H
