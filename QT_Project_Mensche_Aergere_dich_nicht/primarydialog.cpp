#include "primarydialog.h"
#include "ui_primarydialog.h"
#include "newgamedialog.h"
#include "loaddialog.h"
#include "settingsdialog.h"
#include "rulesdialog.h"

PrimaryDialog::PrimaryDialog(QWidget *parent, int language) :
    QDialog(parent),
    ui(new Ui::PrimaryDialog)
{
    //QString str = QString::fromUtf8 ("Neues Spiel");
    language_id = language;

    ui->setupUi(this);

    if(language == 1)
    {
        ui->NewGameButton->setText("Neues Spiel");
        ui->LoadButton->setText("Laden");
        ui->SettingsButton->setText("Einstellungen");
        ui->RulesButton->setText("Spielregeln");
        ui->ExitButton->setText("Verlassen");
    }
    else if(language == 2)
    {
        ui->NewGameButton->setText("Новая игра");
        ui->LoadButton->setText("Загрузить");
        ui->SettingsButton->setText("Настройки");
        ui->RulesButton->setText("Правила");
        ui->ExitButton->setText("Выйти");
    }

}

PrimaryDialog::~PrimaryDialog()
{
    delete ui;
}

void PrimaryDialog::on_NewGameButton_clicked()
{
    if(language_id == 0)
    {
        NewGameDialog newgamedialog(0,0);
        newgamedialog.setModal(true);
        newgamedialog.exec();
    }
    else if(language_id == 1)
    {
        NewGameDialog newgamedialog(0,1);
        newgamedialog.setModal(true);
        newgamedialog.exec();
    }
    else if(language_id == 2)
    {
        NewGameDialog newgamedialog(0,2);
        newgamedialog.setModal(true);
        newgamedialog.exec();
    }
}

void PrimaryDialog::on_LoadButton_clicked()
{

   if(language_id == 0)
   {
       LoadDialog loaddialog(0,0);
       loaddialog.setModal(true);
       loaddialog.exec();
   }
   else if(language_id == 1)
   {
       LoadDialog loaddialog(0,1);
       loaddialog.setModal(true);
       loaddialog.exec();
   }
   else if(language_id == 2)
   {
       LoadDialog loaddialog(0,2);
       loaddialog.setModal(true);
       loaddialog.exec();
   }

}

void PrimaryDialog::on_SettingsButton_clicked()
{
    if(language_id ==0)
    {
        SettingsDialog settingsdialog(0,0);
        settingsdialog.setModal(true);
        settingsdialog.exec();
    }
    else if(language_id ==1)
    {
        SettingsDialog settingsdialog(0,1);
        settingsdialog.setModal(true);
        settingsdialog.exec();
    }
    else if(language_id ==2)
    {
        SettingsDialog settingsdialog(0,2);
        settingsdialog.setModal(true);
        settingsdialog.exec();
    }
}

void PrimaryDialog::on_RulesButton_clicked()
{
    if(language_id == 0)
    {
        RulesDialog rulesdialog(0,0);
        rulesdialog.setModal(true);
        rulesdialog.exec();
    }
    else if(language_id == 1)
    {
        RulesDialog rulesdialog(0,1);
        rulesdialog.setModal(true);
        rulesdialog.exec();
    }
    else if(language_id == 2)
    {
        RulesDialog rulesdialog(0,2);
        rulesdialog.setModal(true);
        rulesdialog.exec();
    }
}
