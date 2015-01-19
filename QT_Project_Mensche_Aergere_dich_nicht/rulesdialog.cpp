#include "rulesdialog.h"
#include "ui_rulesdialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"

RulesDialog::RulesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RulesDialog)
{
    ui->setupUi(this);
}

RulesDialog::~RulesDialog()
{
    delete ui;
}

void RulesDialog::on_BackButton_clicked()
{
    PrimaryDialog primarydialog;
    primarydialog.setModal(true);
    primarydialog.exec();
}

void RulesDialog::on_StartButton_clicked()
{
    ClassicBoardDialog classicboarddialog;
    classicboarddialog.setModal(true);
    classicboarddialog.exec();
}
