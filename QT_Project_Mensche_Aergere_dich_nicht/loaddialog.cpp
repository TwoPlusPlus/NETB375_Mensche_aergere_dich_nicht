#include "loaddialog.h"
#include "ui_loaddialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"

LoadDialog::LoadDialog(QWidget *parent, int language) :
    QDialog(parent),
    ui(new Ui::LoadDialog)
{
    ui->setupUi(this);
    language_id = language;
    if(language_id == 1)
    {
        ui->BackButton->setText("Nach hinten");
        ui->StartButton->setText("Anfang");
        ui->label->setText("Wählen Sie ein Spiel");
    }
    else if(language_id == 2)
    {
        ui->BackButton->setText("Назад");
        ui->StartButton->setText("Начать");
        ui->label->setText("Выбрать игру");
    }
}

LoadDialog::~LoadDialog()
{
    delete ui;
}

void LoadDialog::on_BackButton_clicked()
{
    if(language_id == 0)
    {
        PrimaryDialog primarydialog(0,0);
        primarydialog.setModal(true);
        primarydialog.exec();
    }
    else if(language_id == 1)
    {
        PrimaryDialog primarydialog(0,1);
        primarydialog.setModal(true);
        primarydialog.exec();
    }
    else if(language_id == 2)
    {
        PrimaryDialog primarydialog(0,2);
        primarydialog.setModal(true);
        primarydialog.exec();
    }
}

void LoadDialog::on_StartButton_clicked()
{
    if(language_id == 0)
    {
        ClassicBoardDialog classicboarddialog(0,0);
        classicboarddialog.setModal(true);
        classicboarddialog.exec();
    }
    else if(language_id == 1)
    {
        ClassicBoardDialog classicboarddialog(0,1);
        classicboarddialog.setModal(true);
        classicboarddialog.exec();
    }
    else if(language_id == 2)
    {
        ClassicBoardDialog classicboarddialog(0,2);
        classicboarddialog.setModal(true);
        classicboarddialog.exec();
    }
}
