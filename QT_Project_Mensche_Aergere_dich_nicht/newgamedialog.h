#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QDialog>
#include <string>
#include "game_class.h"

#include <QDebug>

namespace Ui {
class NewGameDialog;
}

class NewGameDialog : public QDialog
{
    Q_OBJECT
    QThread* game_thread;
    //QThread GUI_thread();
public:
    explicit NewGameDialog(QWidget *parent = 0);
    ~NewGameDialog();

private slots:
    void on_BackButton_clicked();

    void on_GreencomboBox_currentIndexChanged();

    void on_BluecomboBox_currentIndexChanged();

    void on_RedcomboBox_currentIndexChanged();

    void on_YellowcomboBox_currentIndexChanged();

    void on_StartButton_clicked();

private:
    bool G;
    bool B;
    bool R;
    bool Y;
    QString G_name;
    QString B_name;
    QString R_name;
    QString Y_name;

    Ui::NewGameDialog *ui;
};

#endif // NEWGAMEDIALOG_H
