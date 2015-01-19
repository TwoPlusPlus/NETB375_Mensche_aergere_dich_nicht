#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->DieThrowcomboBox->addItem("Auto");
    ui->DieThrowcomboBox->addItem("Manual");

    ui->RulescomboBox->addItem("Classic");
    ui->RulescomboBox->addItem("Alternative");

    ui->ThemescomboBox->addItem("Classic");
    ui->ThemescomboBox->addItem("Cristmas");
    ui->ThemescomboBox->addItem("Other");


    ui->SoundscomboBox->addItem("Off");
    ui->SoundscomboBox->addItem("On");
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_BackButton_clicked()
{
    PrimaryDialog primarydialog;
    primarydialog.setModal(true);
    primarydialog.exec();
}

void SettingsDialog::on_StartButton_clicked()
{
    ClassicBoardDialog classicboarddialog;
    classicboarddialog.setModal(true);
    classicboarddialog.exec();
}
