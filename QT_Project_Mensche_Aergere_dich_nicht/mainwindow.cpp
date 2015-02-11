#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "primarydialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_EnglishButton_clicked()
{
    PrimaryDialog primarydialog(0,0);
    //primarydialog = new PrimaryDialog(0,0);
    primarydialog.setModal(true);
    primarydialog.exec();
}

void MainWindow::on_GermanButton_clicked()
{
    PrimaryDialog primarydialog(0,1);
   // primarydialog = new PrimaryDialog(0,1);
    primarydialog.setModal(true);
    primarydialog.exec();
}

void MainWindow::on_RussianButton_clicked()
{
    PrimaryDialog primarydialog(0,2);
    //primarydialog = new PrimaryDialog(0,2);
    primarydialog.setModal(true);
    primarydialog.exec();
}
