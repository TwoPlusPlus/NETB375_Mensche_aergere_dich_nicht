#include "windialog.h"
#include "ui_windialog.h"
#include "primarydialog.h"

WinDialog::WinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
}

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::on_Back_to_menu_Button_clicked()
{
    PrimaryDialog primarydialog;
    primarydialog.setModal(true);
    primarydialog.exec();
}
