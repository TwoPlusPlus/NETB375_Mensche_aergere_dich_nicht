#ifndef PRIMARYDIALOG_H
#define PRIMARYDIALOG_H

#include <QDialog>

namespace Ui {
class PrimaryDialog;
}

class PrimaryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrimaryDialog(QWidget *parent = 0);
    ~PrimaryDialog();

private slots:
    void on_NewGameButton_clicked();

    void on_LoadButton_clicked();

    void on_SettingsButton_clicked();

    void on_RulesButton_clicked();

private:
    Ui::PrimaryDialog *ui;
};

#endif // PRIMARYDIALOG_H
