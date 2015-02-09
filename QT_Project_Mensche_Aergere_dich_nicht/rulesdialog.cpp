#include "rulesdialog.h"
#include "ui_rulesdialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"

RulesDialog::RulesDialog(QWidget *parent, int language) :
    QDialog(parent),
    ui(new Ui::RulesDialog)
{
    language_id = language;
    ui->setupUi(this);
}

RulesDialog::~RulesDialog()
{
    delete ui;
}

void RulesDialog::on_BackButton_clicked()
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

void RulesDialog::on_StartButton_clicked()
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
