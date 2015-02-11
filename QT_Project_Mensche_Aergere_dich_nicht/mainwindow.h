#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_EnglishButton_clicked();

    void on_GermanButton_clicked();

    void on_RussianButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
