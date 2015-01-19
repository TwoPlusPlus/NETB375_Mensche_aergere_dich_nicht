#include "classicboarddialog.h"
#include "ui_classicboarddialog.h"

ClassicBoardDialog::ClassicBoardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassicBoardDialog)
{
    ui->setupUi(this);
}

ClassicBoardDialog::~ClassicBoardDialog()
{
    delete ui;
}
