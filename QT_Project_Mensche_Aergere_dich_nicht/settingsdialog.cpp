#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"

SettingsDialog::SettingsDialog(QWidget *parent, int language) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    if(language == 0)
    {
        ui->ThemescomboBox->addItem("Classic");
        ui->ThemescomboBox->addItem("Cristmas");
        ui->ThemescomboBox->addItem("Other");

        ui->SoundscomboBox->addItem("Off");
        ui->SoundscomboBox->addItem("On");
    }
    if(language == 1)
    {
        ui->BackButton->setText("Nach hinten");
        ui->StartButton->setText("Anfang");
        ui->Soundslabel->setText("Klang");
        ui->Themeslabel->setText("Hintergrund");
        ui->SoundscomboBox->addItem("Ab");
        ui->SoundscomboBox->addItem("Aus");
        ui->ThemescomboBox->addItem("");
        ui->ThemescomboBox->addItem("");
    }
    else if(language == 2)
    {
        ui->BackButton->setText("Назад");
        ui->StartButton->setText("Начать");
        ui->Soundslabel->setText("Звуки");
        ui->Themeslabel->setText("Фон");
        ui->SoundscomboBox->addItem("Включить");
        ui->SoundscomboBox->addItem("Выключить");
        ui->ThemescomboBox->addItem("");
        ui->ThemescomboBox->addItem("");
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_BackButton_clicked()
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

void SettingsDialog::on_StartButton_clicked()
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
