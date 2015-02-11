#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0, int language=0);
    ~SettingsDialog();

private slots:
    void on_BackButton_clicked();

    void on_StartButton_clicked();

private:
    int language_id;
    Ui::SettingsDialog *ui;

};

#endif // SETTINGSDIALOG_H
