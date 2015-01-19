#include "newgamedialog.h"
#include "ui_newgamedialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"
#include <QComboBox>

NewGameDialog::NewGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    ui->setupUi(this);

    ui->GreencomboBox->addItem("Player");
    ui->GreencomboBox->addItem("Bot1");

    ui->BluecomboBox->addItem("Player");
    ui->BluecomboBox->addItem("Bot2");

    ui->RedcomboBox->addItem("Player");
    ui->RedcomboBox->addItem("Bot3");

    ui->YellowcomboBox->addItem("Player");
    ui->YellowcomboBox->addItem("Bot4");
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::on_BackButton_clicked()
{
    PrimaryDialog primarydialog;
    primarydialog.setModal(true);
    primarydialog.exec();
}

void NewGameDialog::on_GreencomboBox_currentIndexChanged(const QString &arg1)
{
    if(ui->GreencomboBox->currentIndex()==1)
    {
        ui->GreenlineEdit->setDisabled(1);
    }
    else if(ui->GreencomboBox->currentIndex()==0)
    {
        ui->GreenlineEdit->setEnabled(1);
    }
}

void NewGameDialog::on_BluecomboBox_currentIndexChanged(const QString &arg1)
{
    if(ui->BluecomboBox->currentIndex()==1)
    {
        ui->BluelineEdit->setDisabled(1);
    }
    else if(ui->BluecomboBox->currentIndex()==0)
    {
        ui->BluelineEdit->setEnabled(1);
    }
}

void NewGameDialog::on_RedcomboBox_currentIndexChanged(const QString &arg1)
{
    if(ui->RedcomboBox->currentIndex()==1)
    {
        ui->RedlineEdit->setDisabled(1);
    }
    else if(ui->RedcomboBox->currentIndex()==0)
    {
        ui->RedlineEdit->setEnabled(1);
    }
}

void NewGameDialog::on_YellowcomboBox_currentIndexChanged(const QString &arg1)
{
    if(ui->YellowcomboBox->currentIndex()==1)
    {
        ui->YellowlineEdit->setDisabled(1);
    }
    else if(ui->YellowcomboBox->currentIndex()==0)
    {
        ui->YellowlineEdit->setEnabled(1);
    }
}

void NewGameDialog::on_StartButton_clicked()
{
    ClassicBoardDialog classicboarddialog;
    classicboarddialog.setModal(true);
    classicboarddialog.exec();
}
