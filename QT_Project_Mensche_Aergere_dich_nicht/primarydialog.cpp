#include "primarydialog.h"
#include "ui_primarydialog.h"
#include "newgamedialog.h"
#include "loaddialog.h"
#include "settingsdialog.h"
#include "rulesdialog.h"

PrimaryDialog::PrimaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimaryDialog)
{
    ui->setupUi(this);
}

PrimaryDialog::~PrimaryDialog()
{
    delete ui;
}

void PrimaryDialog::on_NewGameButton_clicked()
{
    NewGameDialog newgamedialog;
    newgamedialog.setModal(true);
    newgamedialog.exec();
}

void PrimaryDialog::on_LoadButton_clicked()
{
   LoadDialog loaddialog;
   loaddialog.setModal(true);
   loaddialog.exec();
}

void PrimaryDialog::on_SettingsButton_clicked()
{
    SettingsDialog settingsdialog;
    settingsdialog.setModal(true);
    settingsdialog.exec();
}

void PrimaryDialog::on_RulesButton_clicked()
{
    RulesDialog rulesdialog;
    rulesdialog.setModal(true);
    rulesdialog.exec();
}
