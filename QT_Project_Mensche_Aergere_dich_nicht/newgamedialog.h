#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();

private slots:
    void on_BackButton_clicked();

    void on_GreencomboBox_currentIndexChanged(const QString &arg1);

    void on_BluecomboBox_currentIndexChanged(const QString &arg1);

    void on_RedcomboBox_currentIndexChanged(const QString &arg1);

    void on_YellowcomboBox_currentIndexChanged(const QString &arg1);

    void on_StartButton_clicked();

private:
    Ui::NewGameDialog *ui;
};

#endif // NEWGAMEDIALOG_H
