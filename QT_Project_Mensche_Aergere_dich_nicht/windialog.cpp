#include "windialog.h"
#include "ui_windialog.h"
#include "primarydialog.h"

WinDialog::WinDialog(QWidget *parent, int language) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    language_id = language;
    ui->setupUi(this);
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_Back_to_menu_Button_clicked()
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
