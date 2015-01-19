#include "loaddialog.h"
#include "ui_loaddialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"

LoadDialog::LoadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadDialog)
{
    ui->setupUi(this);
}

LoadDialog::~LoadDialog()
{
    delete ui;
}

void LoadDialog::on_BackButton_clicked()
{
    PrimaryDialog primarydialog;
    primarydialog.setModal(true);
    primarydialog.exec();
}

void LoadDialog::on_StartButton_clicked()
{
    ClassicBoardDialog classicboarddialog;
    classicboarddialog.setModal(true);
    classicboarddialog.exec();
}
