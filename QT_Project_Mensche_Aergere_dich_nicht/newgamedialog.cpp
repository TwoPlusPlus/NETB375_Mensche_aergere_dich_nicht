#include "newgamedialog.h"
#include "ui_newgamedialog.h"
#include "primarydialog.h"
#include "classicboarddialog.h"
#include <QComboBox>

NewGameDialog::NewGameDialog(QWidget *parent, int language) :
    QDialog(parent),
    ui(new Ui::NewGameDialog)
{
    language_id = language;
    ui->setupUi(this);
    if(language == 0)
    {
        ui->GreencomboBox->addItem("Player");
        ui->GreencomboBox->addItem("Bot1");

        ui->BluecomboBox->addItem("Player");
        ui->BluecomboBox->addItem("Bot2");

        ui->RedcomboBox->addItem("Player");
        ui->RedcomboBox->addItem("Bot3");

        ui->YellowcomboBox->addItem("Player");
        ui->YellowcomboBox->addItem("Bot4");
    }
    if(language == 1)
    {
        ui->BackButton->setText("Nach hiten");
        ui->StartButton->setText("Anfang");
        ui->Greenlabel->setText("Grün");
        ui->Bluelabel->setText("Blau");
        ui->Redlabel->setText("Rot");
        ui->Yellowlabel->setText("Gelb");
        ui->GreencomboBox->addItem("Sieler");
        ui->GreencomboBox->addItem("Bot1");
        ui->BluecomboBox->addItem("Spieler");
        ui->BluecomboBox->addItem("Bot2");
        ui->RedcomboBox->addItem("Spieler");
        ui->RedcomboBox->addItem("Bot3");
        ui->YellowcomboBox->addItem("Spieler");
        ui->YellowcomboBox->addItem("Bot4");
    }
    if(language == 2)
    {
        ui->BackButton->setText("Назад");
        ui->StartButton->setText("Начало");
        ui->Greenlabel->setText("Зеленый");
        ui->Bluelabel->setText("Синий");
        ui->Redlabel->setText("Красный");
        ui->Yellowlabel->setText("Желтый");
        ui->GreencomboBox->addItem("Игрок");
        ui->GreencomboBox->addItem("Бот1");
        ui->BluecomboBox->addItem("Игрок");
        ui->BluecomboBox->addItem("Бот2");
        ui->RedcomboBox->addItem("Игрок");
        ui->RedcomboBox->addItem("Бот3");
        ui->YellowcomboBox->addItem("Игрок");
        ui->YellowcomboBox->addItem("Бот4");
    }
}

NewGameDialog::~NewGameDialog()
{
    delete ui;
}

void NewGameDialog::on_BackButton_clicked()
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

void NewGameDialog::on_GreencomboBox_currentIndexChanged()
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

void NewGameDialog::on_BluecomboBox_currentIndexChanged()
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

void NewGameDialog::on_RedcomboBox_currentIndexChanged()
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

void NewGameDialog::on_YellowcomboBox_currentIndexChanged()
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

    if(ui->GreencomboBox->currentIndex() == 0)// PLAYER 1 IS GREEN
    {
        G = false;
        if(!ui->GreenlineEdit->text().isEmpty())
        {
            G_name = ui->GreenlineEdit->text();
        }
        else
        {
            G_name = "Player 1";
        }
    }
    else
    {
        G=true;
        G_name="Bot 1";
    }
    if(ui->RedcomboBox->currentIndex() == 0)// PLAYER 2 IS RED!
    {
        R = false;
        if(!ui->RedlineEdit->text().isEmpty())
        {
            R_name = ui->RedlineEdit->text();
        }
        else
        {
            R_name = "Player 2";
        }
    }
    else
    {
        R=true;
        R_name="Bot 2";
    }
    if(ui->BluecomboBox->currentIndex() == 0)//Player 3 is Blue
    {
        B = false;
        if(!ui->BluelineEdit->text().isEmpty())
        {
            B_name = ui->BluelineEdit->text();
        }
        else
        {
            B_name = "Player 3";
        }
    }
    else
    {
        B=true;
        B_name="Bot 3";
    }
    if(ui->YellowcomboBox->currentIndex() == 0)// 4 is Yellow
    {
        Y = false;
        if(!ui->YellowlineEdit->text().isEmpty())
        {
            Y_name = ui->YellowlineEdit->text();
        }
        else
        {
            Y_name = "Player 4";
        }
    }
    else
    {
        Y=true;
        Y_name="Bot 4";
    }



    ClassicBoardDialog classicboarddialog(0,G,G_name,B,B_name,R,R_name,Y,Y_name);

    qDebug() <<"from main thread" << QThread::currentThreadId();
    classicboarddialog.setModal(true);
    //game_thread->run();
    classicboarddialog.exec();

}
