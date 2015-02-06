#include "classicboarddialog.h"
#include "ui_classicboarddialog.h"

ClassicBoardDialog::ClassicBoardDialog(QWidget *parent ,bool G,QString G_name,bool R,QString R_name,bool B,QString B_name,bool Y,QString Y_name) :
    QDialog(parent),
    ui(new Ui::ClassicBoardDialog)
{
    game = new Game(G, G_name, R, R_name, B, B_name, Y, Y_name);

    QObject::connect(this, &ClassicBoardDialog::roll_dice, game, &Game::dice_slot);
    QObject::connect(game, &Game::show_dice, this, &ClassicBoardDialog::Show_Dice);
    QObject::connect(game, &Game::set_dice_player, this, &ClassicBoardDialog::set_Dice_Player);

    QObject::connect(this, & ClassicBoardDialog::GBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_1_set_state, this, &ClassicBoardDialog::GBase1);
    QObject::connect(this, & ClassicBoardDialog::GBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_2_set_state, this, &ClassicBoardDialog::GBase2);
    QObject::connect(this, & ClassicBoardDialog::GBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_3_set_state, this, &ClassicBoardDialog::GBase3);
    QObject::connect(this, & ClassicBoardDialog::GBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_4_set_state, this, &ClassicBoardDialog::GBase4);

    QObject::connect(this, & ClassicBoardDialog::BBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_1_set_state, this, &ClassicBoardDialog::BBase1);
    QObject::connect(this, & ClassicBoardDialog::BBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_2_set_state, this, &ClassicBoardDialog::BBase2);
    QObject::connect(this, & ClassicBoardDialog::BBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_3_set_state, this, &ClassicBoardDialog::BBase3);
    QObject::connect(this, & ClassicBoardDialog::BBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_4_set_state, this, &ClassicBoardDialog::BBase4);

    QObject::connect(this, & ClassicBoardDialog::RBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_1_set_state, this, &ClassicBoardDialog::RBase1);
    QObject::connect(this, & ClassicBoardDialog::RBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_2_set_state, this, &ClassicBoardDialog::RBase2);
    QObject::connect(this, & ClassicBoardDialog::RBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_3_set_state, this, &ClassicBoardDialog::RBase3);
    QObject::connect(this, & ClassicBoardDialog::RBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_4_set_state, this, &ClassicBoardDialog::RBase4);

    QObject::connect(this, & ClassicBoardDialog::YBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_1_set_state, this, &ClassicBoardDialog::YBase1);
    QObject::connect(this, & ClassicBoardDialog::YBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_2_set_state, this, &ClassicBoardDialog::YBase2);
    QObject::connect(this, & ClassicBoardDialog::YBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_3_set_state, this, &ClassicBoardDialog::YBase3);
    QObject::connect(this, & ClassicBoardDialog::YBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_4_set_state, this, &ClassicBoardDialog::YBase4);

    //board connections
    QObject::connect(this, &ClassicBoardDialog::node_0_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_0_set_player, this, &ClassicBoardDialog::node_0_set_player);
    QObject::connect(game, &Game::signal_node_0_set_state, this, &ClassicBoardDialog::node_0_set_state);


    ui->setupUi(this);
    ui->green_player_name->setText(G_name);
    ui->blue_player_name->setText(B_name);
    ui->red_player_name->setText(R_name);
    ui->yellow_player_name->setText(Y_name);
}

ClassicBoardDialog::~ClassicBoardDialog()
{
    //play_thread.quit();
   // play_thread.wait();
    delete ui;
}


//DICE
void ClassicBoardDialog::on_Dice_Button_clicked()
{
    ui->Dice_Button->setEnabled(false);
    emit roll_dice();
}
void ClassicBoardDialog::Show_Dice(int N)
{
    if(N==1)
        ui->Dice_Button->setText("1");
    else if(N==2)
        ui->Dice_Button->setText("2");
    else if(N==3)
        ui->Dice_Button->setText("3");
    else if(N==4)
        ui->Dice_Button->setText("4");
    else if(N==5)
        ui->Dice_Button->setText("5");
    else if(N==6)
        ui->Dice_Button->setText("6");
}

void ClassicBoardDialog::set_Dice_Player(bool state, int player)
{
    if(state == true)
        ui->Dice_Button->setEnabled(state);
}

//------------------------------------------------------------------------
// GREEN LIMBO
//------------------------------------------------------------------------

void ClassicBoardDialog::on_GBase1_clicked()
{
    emit GBase_1_clicked(0);
}
void ClassicBoardDialog::GBase1(bool checked)
{
    if(!checked)
    {
        ui->GBase1->setStyleSheet("background-color: green");
    }
    else
        ui->GBase1->setStyleSheet("background-color: green");
        ui->GBase1->setEnabled(false);
}


void ClassicBoardDialog::on_GBase2_clicked()
{
    emit GBase_2_clicked(1);
}
void ClassicBoardDialog::GBase2(bool checked)
{
    if(!checked)
        ui->GBase2->setStyleSheet("background-color: green");
    else
        ui->GBase2->setStyleSheet("background-color: white");
        ui->GBase2->setEnabled(false);
}


void ClassicBoardDialog::on_GBase3_clicked()
{
    emit GBase_3_clicked(2);
}
void ClassicBoardDialog::GBase3(bool checked)
{
    if(!checked)
        ui->GBase3->setStyleSheet("background-color: green");
    else
        ui->GBase3->setStyleSheet("background-color: white");
        ui->GBase3->setEnabled(false);
}


void ClassicBoardDialog::on_GBase4_clicked()
{
    emit GBase_4_clicked(3);
}
void ClassicBoardDialog::GBase4(bool checked)
{
    if(!checked)
        ui->GBase4->setStyleSheet("background-color: green");
    else
        ui->GBase4->setStyleSheet("background-color: white");
        ui->GBase4->setEnabled(false);
}


//------------------------------------------------------------------------
// BLUE LIMBO
//------------------------------------------------------------------------
void ClassicBoardDialog::on_BBase1_clicked()
{
    emit BBase_1_clicked(0);
}
void ClassicBoardDialog::BBase1(bool checked)
{
    if(!checked)
        ui->BBase1->setStyleSheet("background-color: blue");
    else
        ui->BBase1->setStyleSheet("background-color: white");ui->BBase1->setEnabled(false);
}


void ClassicBoardDialog::on_BBase2_clicked()
{
    emit BBase_2_clicked(1);
}
void ClassicBoardDialog::BBase2(bool checked)
{
    if(!checked)
        ui->BBase2->setStyleSheet("background-color: blue");
    else
        ui->BBase2->setStyleSheet("background-color: white");ui->BBase2->setEnabled(false);
}


void ClassicBoardDialog::on_BBase3_clicked()
{
    emit BBase_3_clicked(2);
}
void ClassicBoardDialog::BBase3(bool checked)
{
    if(!checked)
        ui->BBase3->setStyleSheet("background-color: blue");
    else
        ui->BBase3->setStyleSheet("background-color: white");ui->BBase3->setEnabled(false);
}


void ClassicBoardDialog::on_BBase4_clicked()
{
    emit BBase_4_clicked(3);
}
void ClassicBoardDialog::BBase4(bool checked)
{
    if(!checked)
        ui->BBase4->setStyleSheet("background-color: blue");
    else
        ui->BBase4->setStyleSheet("background-color: white");ui->BBase4->setEnabled(false);
}

//------------------------------------------------------------------------
// RED LIMBO
//------------------------------------------------------------------------
void ClassicBoardDialog::on_RBase1_clicked()
{
    emit RBase_1_clicked(0);
}
void ClassicBoardDialog::RBase1(bool checked)
{
    if(!checked)
        ui->RBase1->setStyleSheet("background-color: red");
    else
        ui->RBase1->setStyleSheet("background-color: white");ui->RBase1->setEnabled(false);
}


void ClassicBoardDialog::on_RBase2_clicked()
{
    emit RBase_2_clicked(1);
}
void ClassicBoardDialog::RBase2(bool checked)
{
    if(!checked)
        ui->RBase2->setStyleSheet("background-color: red");
    else
        ui->RBase2->setStyleSheet("background-color: white");ui->RBase2->setEnabled(false);
}

void ClassicBoardDialog::on_RBase3_clicked()
{
    emit RBase_3_clicked(2);
}
void ClassicBoardDialog::RBase3(bool checked)
{
    if(!checked)
        ui->RBase3->setStyleSheet("background-color: red");
    else
        ui->RBase3->setStyleSheet("background-color: white");ui->RBase3->setEnabled(false);
}

void ClassicBoardDialog::on_RBase4_clicked()
{
    emit RBase_4_clicked(3);
}
void ClassicBoardDialog::RBase4(bool checked)
{
    if(!checked)
        ui->RBase4->setStyleSheet("background-color: red");
    else
        ui->RBase4->setStyleSheet("background-color: white");ui->RBase4->setEnabled(false);
}
//------------------------------------------------------------------------
// YELLOW LIMBO
//------------------------------------------------------------------------
void ClassicBoardDialog::on_YBase1_clicked()
{
    emit YBase_1_clicked(0);
}
void ClassicBoardDialog::YBase1(bool checked)
{
    if(!checked)
        ui->YBase1->setStyleSheet("background-color: yellow");
    else
        ui->YBase1->setStyleSheet("background-color: white");ui->YBase1->setEnabled(false);
}

void ClassicBoardDialog::on_YBase2_clicked()
{
    emit YBase_2_clicked(1);
}
void ClassicBoardDialog::YBase2(bool checked)
{
    if(!checked)
        ui->YBase2->setStyleSheet("background-color: yellow");
    else
        ui->YBase2->setStyleSheet("background-color: white");ui->YBase2->setEnabled(false);
}


void ClassicBoardDialog::on_YBase3_clicked()
{
    emit YBase_3_clicked(2);
}
void ClassicBoardDialog::YBase3(bool checked)
{
    if(!checked)
        ui->YBase3->setStyleSheet("background-color: yellow");
    else
        ui->YBase3->setStyleSheet("background-color: white");ui->YBase3->setEnabled(false);
}


void ClassicBoardDialog::on_YBase4_clicked()
{
    emit YBase_4_clicked(3);
}
void ClassicBoardDialog::YBase4(bool checked)
{
    if(!checked)
        ui->YBase4->setStyleSheet("background-color: yellow");
    else
        ui->YBase4->setStyleSheet("background-color: white");ui->YBase4->setEnabled(false);
}

//------------------------------------------------------------------------
// BOARD
//------------------------------------------------------------------------
void ClassicBoardDialog::on_node_0_clicked()
{
    emit node_0_clicked(0);
}
void ClassicBoardDialog::node_0_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_0->setStyleSheet("background-color: white");
        ui->node_0->setEnabled(false);
    case 0:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: green");

    case 1:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: red");

    case 2:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: blue");

    case 3:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_0_set_state(bool checked)
{
    if(checked==true)
        ui->node_0->setEnabled(true);
    else
        ui->node_0->setEnabled(false);
}


void ClassicBoardDialog::on_node_1_clicked()
{
    emit node_1_clicked(1);
}
void ClassicBoardDialog::node_1_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_1->setStyleSheet("background-color: white");
        ui->node_1->setEnabled(false);
    case 0:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: green");

    case 1:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: red");

    case 2:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: blue");

    case 3:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_1_set_state(bool checked)
{
    if(checked==true)
        ui->node_1->setEnabled(true);
    else
        ui->node_1->setEnabled(false);
}


void ClassicBoardDialog::on_node_2_clicked()
{
    emit node_2_clicked(2);
}

void ClassicBoardDialog::node_2_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_2->setStyleSheet("background-color: white");
        ui->node_2->setEnabled(false);
    case 0:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: green");

    case 1:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: red");

    case 2:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: blue");

    case 3:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_2_set_state(bool checked)
{
    if(checked==true)
        ui->node_2->setEnabled(true);
    else
        ui->node_2->setEnabled(false);
}


void ClassicBoardDialog::on_node_3_clicked()
{
    emit node_3_clicked(3);
}
void ClassicBoardDialog::node_3_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_3->setStyleSheet("background-color: white");
        ui->node_3->setEnabled(false);
    case 0:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: green");

    case 1:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: red");

    case 2:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: blue");

    case 3:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_3_set_state(bool checked)
{
    if(checked==true)
        ui->node_3->setEnabled(true);
    else
        ui->node_3->setEnabled(false);
}


void ClassicBoardDialog::on_node_4_clicked()
{
    emit node_4_clicked(4);
}
void ClassicBoardDialog::node_4_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_4->setStyleSheet("background-color: white");
        ui->node_4->setEnabled(false);
    case 0:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: green");

    case 1:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: red");

    case 2:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: blue");

    case 3:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_4_set_state(bool checked)
{
    if(checked==true)
        ui->node_4->setEnabled(true);
    else
        ui->node_4->setEnabled(false);
}



void ClassicBoardDialog::on_node_5_clicked()
{
    emit node_5_clicked(5);
}
void ClassicBoardDialog::node_5_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_5->setStyleSheet("background-color: white");
        ui->node_5->setEnabled(false);
    case 0:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: green");

    case 1:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: red");

    case 2:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: blue");

    case 3:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_5_set_state(bool checked)
{
    if(checked==true)
        ui->node_5->setEnabled(true);
    else
        ui->node_5->setEnabled(false);
}



void ClassicBoardDialog::on_node_6_clicked()
{
    emit node_6_clicked(6);
}
void ClassicBoardDialog::node_6_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_6->setStyleSheet("background-color: white");
        ui->node_6->setEnabled(false);
    case 0:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: green");

    case 1:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: red");

    case 2:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: blue");

    case 3:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_6_set_state(bool checked)
{
    if(checked==true)
        ui->node_6->setEnabled(true);
    else
        ui->node_6->setEnabled(false);
}



void ClassicBoardDialog::on_node_7_clicked()
{
    emit node_7_clicked(7);
}
void ClassicBoardDialog::node_7_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_7->setStyleSheet("background-color: white");
        ui->node_7->setEnabled(false);
    case 0:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: green");

    case 1:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: red");

    case 2:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: blue");

    case 3:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_7_set_state(bool checked)
{
    if(checked==true)
        ui->node_7->setEnabled(true);
    else
        ui->node_7->setEnabled(false);
}



void ClassicBoardDialog::on_node_8_clicked()
{
    emit node_8_clicked(8);
}
void ClassicBoardDialog::node_8_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_8->setStyleSheet("background-color: white");
        ui->node_8->setEnabled(false);
    case 0:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: green");

    case 1:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: red");

    case 2:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: blue");

    case 3:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_8_set_state(bool checked)
{
    if(checked==true)
        ui->node_8->setEnabled(true);
    else
        ui->node_8->setEnabled(false);
}



void ClassicBoardDialog::on_node_9_clicked()
{
    emit node_9_clicked(9);
}
void ClassicBoardDialog::node_9_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_9->setStyleSheet("background-color: white");
        ui->node_9->setEnabled(false);
    case 0:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: green");

    case 1:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: red");

    case 2:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: blue");

    case 3:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_9_set_state(bool checked)
{
    if(checked==true)
        ui->node_9->setEnabled(true);
    else
        ui->node_9->setEnabled(false);
}



void ClassicBoardDialog::on_node_10_clicked()
{
    emit node_10_clicked(10);
}
void ClassicBoardDialog::node_10_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_10->setStyleSheet("background-color: white");
        ui->node_10->setEnabled(false);
    case 0:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: green");

    case 1:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: red");

    case 2:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: blue");

    case 3:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_10_set_state(bool checked)
{
    if(checked==true)
        ui->node_10->setEnabled(true);
    else
        ui->node_10->setEnabled(false);
}



void ClassicBoardDialog::on_node_11_clicked()
{
    emit node_11_clicked(11);
}
void ClassicBoardDialog::node_11_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_11->setStyleSheet("background-color: white");
        ui->node_11->setEnabled(false);
    case 0:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: green");

    case 1:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: red");

    case 2:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: blue");

    case 3:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_11_set_state(bool checked)
{
    if(checked==true)
        ui->node_11->setEnabled(true);
    else
        ui->node_11->setEnabled(false);
}



void ClassicBoardDialog::on_node_12_clicked()
{
    emit node_12_clicked(12);
}
void ClassicBoardDialog::node_12_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_12->setStyleSheet("background-color: white");
        ui->node_12->setEnabled(false);
    case 0:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: green");

    case 1:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: red");

    case 2:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: blue");

    case 3:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_12_set_state(bool checked)
{
    if(checked==true)
        ui->node_12->setEnabled(true);
    else
        ui->node_12->setEnabled(false);
}



void ClassicBoardDialog::on_node_13_clicked()
{
    emit node_13_clicked(13);
}
void ClassicBoardDialog::node_13_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_13->setStyleSheet("background-color: white");
        ui->node_13->setEnabled(false);
    case 0:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: green");

    case 1:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: red");

    case 2:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: blue");

    case 3:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_13_set_state(bool checked)
{
    if(checked==true)
        ui->node_13->setEnabled(true);
    else
        ui->node_13->setEnabled(false);
}



void ClassicBoardDialog::on_node_14_clicked()
{
    emit node_14_clicked(14);
}
void ClassicBoardDialog::node_14_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_14->setStyleSheet("background-color: white");
        ui->node_14->setEnabled(false);
    case 0:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: green");

    case 1:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: red");

    case 2:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: blue");

    case 3:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_14_set_state(bool checked)
{
    if(checked==true)
        ui->node_14->setEnabled(true);
    else
        ui->node_14->setEnabled(false);
}



void ClassicBoardDialog::on_node_15_clicked()
{
    emit node_15_clicked(15);
}
void ClassicBoardDialog::node_15_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_15->setStyleSheet("background-color: white");
        ui->node_15->setEnabled(false);
    case 0:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: green");

    case 1:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: red");

    case 2:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: blue");

    case 3:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_15_set_state(bool checked)
{
    if(checked==true)
        ui->node_15->setEnabled(true);
    else
        ui->node_15->setEnabled(false);
}



void ClassicBoardDialog::on_node_16_clicked()
{
    emit node_16_clicked(16);
}
void ClassicBoardDialog::node_16_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_16->setStyleSheet("background-color: white");
        ui->node_16->setEnabled(false);
    case 0:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: green");

    case 1:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: red");

    case 2:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: blue");

    case 3:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_16_set_state(bool checked)
{
    if(checked==true)
        ui->node_16->setEnabled(true);
    else
        ui->node_16->setEnabled(false);
}



void ClassicBoardDialog::on_node_17_clicked()
{
    emit node_17_clicked(17);
}
void ClassicBoardDialog::node_17_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_17->setStyleSheet("background-color: white");
        ui->node_17->setEnabled(false);
    case 0:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: green");

    case 1:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: red");

    case 2:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: blue");

    case 3:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_17_set_state(bool checked)
{
    if(checked==true)
        ui->node_17->setEnabled(true);
    else
        ui->node_17->setEnabled(false);
}



void ClassicBoardDialog::on_node_18_clicked()
{
    emit node_18_clicked(18);
}
void ClassicBoardDialog::node_18_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_18->setStyleSheet("background-color: white");
        ui->node_18->setEnabled(false);
    case 0:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: green");

    case 1:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: red");

    case 2:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: blue");

    case 3:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_18_set_state(bool checked)
{
    if(checked==true)
        ui->node_18->setEnabled(true);
    else
        ui->node_18->setEnabled(false);
}



void ClassicBoardDialog::on_node_19_clicked()
{
    emit node_19_clicked(19);
}
void ClassicBoardDialog::node_19_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_19->setStyleSheet("background-color: white");
        ui->node_19->setEnabled(false);
    case 0:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: green");

    case 1:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: red");

    case 2:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: blue");

    case 3:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_19_set_state(bool checked)
{
    if(checked==true)
        ui->node_19->setEnabled(true);
    else
        ui->node_19->setEnabled(false);
}



void ClassicBoardDialog::on_node_20_clicked()
{
    emit node_20_clicked(20);
}
void ClassicBoardDialog::node_20_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_20->setStyleSheet("background-color: white");
        ui->node_20->setEnabled(false);
    case 0:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: green");

    case 1:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: red");

    case 2:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: blue");

    case 3:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_20_set_state(bool checked)
{
    if(checked==true)
        ui->node_20->setEnabled(true);
    else
        ui->node_20->setEnabled(false);
}



void ClassicBoardDialog::on_node_21_clicked()
{
    emit node_21_clicked(21);
}
void ClassicBoardDialog::node_21_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_21->setStyleSheet("background-color: white");
        ui->node_21->setEnabled(false);
    case 0:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: green");

    case 1:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: red");

    case 2:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: blue");

    case 3:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_21_set_state(bool checked)
{
    if(checked==true)
        ui->node_21->setEnabled(true);
    else
        ui->node_21->setEnabled(false);
}



void ClassicBoardDialog::on_node_22_clicked()
{
    emit node_22_clicked(22);
}
void ClassicBoardDialog::node_22_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_22->setStyleSheet("background-color: white");
        ui->node_22->setEnabled(false);
    case 0:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: green");

    case 1:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: red");

    case 2:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: blue");

    case 3:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_22_set_state(bool checked)
{
    if(checked==true)
        ui->node_22->setEnabled(true);
    else
        ui->node_22->setEnabled(false);
}



void ClassicBoardDialog::on_node_23_clicked()
{
    emit node_23_clicked(23);
}
void ClassicBoardDialog::node_23_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_23->setStyleSheet("background-color: white");
        ui->node_23->setEnabled(false);
    case 0:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: green");

    case 1:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: red");

    case 2:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: blue");

    case 3:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_23_set_state(bool checked)
{
    if(checked==true)
        ui->node_23->setEnabled(true);
    else
        ui->node_23->setEnabled(false);
}



void ClassicBoardDialog::on_node_24_clicked()
{
    emit node_24_clicked(24);
}
void ClassicBoardDialog::node_24_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_24->setStyleSheet("background-color: white");
        ui->node_24->setEnabled(false);
    case 0:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: green");

    case 1:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: red");

    case 2:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: blue");

    case 3:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_24_set_state(bool checked)
{
    if(checked==true)
        ui->node_24->setEnabled(true);
    else
        ui->node_24->setEnabled(false);
}



void ClassicBoardDialog::on_node_25_clicked()
{
    emit node_25_clicked(25);
}
void ClassicBoardDialog::node_25_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_25->setStyleSheet("background-color: white");
        ui->node_25->setEnabled(false);
    case 0:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: green");

    case 1:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: red");

    case 2:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: blue");

    case 3:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_25_set_state(bool checked)
{
    if(checked==true)
        ui->node_25->setEnabled(true);
    else
        ui->node_25->setEnabled(false);
}



void ClassicBoardDialog::on_node_26_clicked()
{
    emit node_26_clicked(26);
}
void ClassicBoardDialog::node_26_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_26->setStyleSheet("background-color: white");
        ui->node_26->setEnabled(false);
    case 0:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: green");

    case 1:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: red");

    case 2:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: blue");

    case 3:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_26_set_state(bool checked)
{
    if(checked==true)
        ui->node_26->setEnabled(true);
    else
        ui->node_26->setEnabled(false);
}



void ClassicBoardDialog::on_node_27_clicked()
{
    emit node_27_clicked(27);
}
void ClassicBoardDialog::node_27_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_27->setStyleSheet("background-color: white");
        ui->node_27->setEnabled(false);
    case 0:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: green");

    case 1:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: red");

    case 2:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: blue");

    case 3:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_27_set_state(bool checked)
{
    if(checked==true)
        ui->node_27->setEnabled(true);
    else
        ui->node_27->setEnabled(false);
}



void ClassicBoardDialog::on_node_28_clicked()
{
    emit node_28_clicked(28);
}
void ClassicBoardDialog::node_28_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_28->setStyleSheet("background-color: white");
        ui->node_28->setEnabled(false);
    case 0:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: green");

    case 1:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: red");

    case 2:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: blue");

    case 3:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_28_set_state(bool checked)
{
    if(checked==true)
        ui->node_28->setEnabled(true);
    else
        ui->node_28->setEnabled(false);
}



void ClassicBoardDialog::on_node_29_clicked()
{
    emit node_29_clicked(29);
}
void ClassicBoardDialog::node_29_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_29->setStyleSheet("background-color: white");
        ui->node_29->setEnabled(false);
    case 0:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: green");

    case 1:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: red");

    case 2:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: blue");

    case 3:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_29_set_state(bool checked)
{
    if(checked==true)
        ui->node_29->setEnabled(true);
    else
        ui->node_29->setEnabled(false);
}



void ClassicBoardDialog::on_node_30_clicked()
{
    emit node_30_clicked(30);
}
void ClassicBoardDialog::node_30_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_30->setStyleSheet("background-color: white");
        ui->node_30->setEnabled(false);
    case 0:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: green");

    case 1:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: red");

    case 2:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: blue");

    case 3:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_30_set_state(bool checked)
{
    if(checked==true)
        ui->node_30->setEnabled(true);
    else
        ui->node_30->setEnabled(false);
}



void ClassicBoardDialog::on_node_31_clicked()
{
    emit node_31_clicked(31);
}
void ClassicBoardDialog::node_31_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_31->setStyleSheet("background-color: white");
        ui->node_31->setEnabled(false);
    case 0:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: green");

    case 1:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: red");

    case 2:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: blue");

    case 3:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_31_set_state(bool checked)
{
    if(checked==true)
        ui->node_31->setEnabled(true);
    else
        ui->node_31->setEnabled(false);
}



void ClassicBoardDialog::on_node_32_clicked()
{
    emit node_32_clicked(32);
}
void ClassicBoardDialog::node_32_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_32->setStyleSheet("background-color: white");
        ui->node_32->setEnabled(false);
    case 0:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: green");

    case 1:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: red");

    case 2:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: blue");

    case 3:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_32_set_state(bool checked)
{
    if(checked==true)
        ui->node_32->setEnabled(true);
    else
        ui->node_32->setEnabled(false);
}



void ClassicBoardDialog::on_node_33_clicked()
{
    emit node_33_clicked(33);
}
void ClassicBoardDialog::node_33_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_33->setStyleSheet("background-color: white");
        ui->node_33->setEnabled(false);
    case 0:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: green");

    case 1:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: red");

    case 2:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: blue");

    case 3:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_33_set_state(bool checked)
{
    if(checked==true)
        ui->node_33->setEnabled(true);
    else
        ui->node_33->setEnabled(false);
}



void ClassicBoardDialog::on_node_34_clicked()
{
    emit node_34_clicked(34);
}
void ClassicBoardDialog::node_34_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_34->setStyleSheet("background-color: white");
        ui->node_34->setEnabled(false);
    case 0:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: green");

    case 1:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: red");

    case 2:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: blue");

    case 3:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_34_set_state(bool checked)
{
    if(checked==true)
        ui->node_34->setEnabled(true);
    else
        ui->node_34->setEnabled(false);
}



void ClassicBoardDialog::on_node_35_clicked()
{
    emit node_35_clicked(35);
}
void ClassicBoardDialog::node_35_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_35->setStyleSheet("background-color: white");
        ui->node_35->setEnabled(false);
    case 0:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: green");

    case 1:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: red");

    case 2:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: blue");

    case 3:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_35_set_state(bool checked)
{
    if(checked==true)
        ui->node_35->setEnabled(true);
    else
        ui->node_35->setEnabled(false);
}



void ClassicBoardDialog::on_node_36_clicked()
{
    emit node_36_clicked(36);
}
void ClassicBoardDialog::node_36_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_36->setStyleSheet("background-color: white");
        ui->node_36->setEnabled(false);
    case 0:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: green");

    case 1:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: red");

    case 2:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: blue");

    case 3:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_36_set_state(bool checked)
{
    if(checked==true)
        ui->node_36->setEnabled(true);
    else
        ui->node_36->setEnabled(false);
}



void ClassicBoardDialog::on_node_37_clicked()
{
    emit node_37_clicked(37);
}
void ClassicBoardDialog::node_37_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_37->setStyleSheet("background-color: white");
        ui->node_37->setEnabled(false);
    case 0:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: green");

    case 1:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: red");

    case 2:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: blue");

    case 3:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_37_set_state(bool checked)
{
    if(checked==true)
        ui->node_37->setEnabled(true);
    else
        ui->node_37->setEnabled(false);
}



void ClassicBoardDialog::on_node_38_clicked()
{
    emit node_38_clicked(38);
}
void ClassicBoardDialog::node_38_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_38->setStyleSheet("background-color: white");
        ui->node_38->setEnabled(false);
    case 0:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: green");

    case 1:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: red");

    case 2:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: blue");

    case 3:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_38_set_state(bool checked)
{
    if(checked==true)
        ui->node_38->setEnabled(true);
    else
        ui->node_38->setEnabled(false);
}



void ClassicBoardDialog::on_node_39_clicked()
{
    emit node_39_clicked(39);
}
void ClassicBoardDialog::node_39_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_39->setStyleSheet("background-color: white");
        ui->node_39->setEnabled(false);
    case 0:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: green");

    case 1:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: red");

    case 2:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: blue");

    case 3:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: yellow");
    }
}
void ClassicBoardDialog::node_39_set_state(bool checked)
{
    if(checked==true)
        ui->node_39->setEnabled(true);
    else
        ui->node_39->setEnabled(false);
}

//GREEN HOME
void ClassicBoardDialog::GH4_set_state(bool checked)
{
    if(checked)
    {
        ui->GH4->setStyleSheet("background-color: green");
        ui->GH4->setEnabled(checked);
    }
    else
        ui->GH4->setEnabled(checked);
}
void ClassicBoardDialog::on_GH4_clicked()
{

}

void ClassicBoardDialog::GH3_set_state(bool checked)
{
    if(checked)
    {
        ui->GH3->setStyleSheet("background-color: green");
        ui->GH3->setEnabled(checked);
    }
    else
        ui->GH3->setEnabled(checked);
}
void ClassicBoardDialog::on_GH3_clicked()
{

}

void ClassicBoardDialog::GH2_set_state(bool checked)
{
    if(checked)
    {
        ui->GH2->setStyleSheet("background-color: green");
        ui->GH2->setEnabled(checked);
    }
    else
        ui->GH2->setEnabled(checked);
}
void ClassicBoardDialog::on_GH2_clicked()
{

}

void ClassicBoardDialog::GH1_set_state(bool checked)
{
    if(checked)
    {
        ui->GH1->setStyleSheet("background-color: green");
        ui->GH1->setEnabled(checked);
    }
    else
        ui->GH1->setEnabled(checked);
}
void ClassicBoardDialog::on_GH1_clicked()
{

}
//BLUE HOME
void ClassicBoardDialog::BH1_set_state(bool checked)
{
    if(checked)
    {
        ui->BH1->setStyleSheet("background-color: blue");
        ui->BH1->setEnabled(checked);
    }
    else
        ui->BH1->setEnabled(checked);
}
void ClassicBoardDialog::on_BH1_clicked()
{

}

void ClassicBoardDialog::BH2_set_state(bool checked)
{
    if(checked)
    {
        ui->BH2->setStyleSheet("background-color: blue");
        ui->BH2->setEnabled(checked);
    }
    else
        ui->BH2->setEnabled(checked);
}
void ClassicBoardDialog::on_BH2_clicked()
{

}

void ClassicBoardDialog::BH3_set_state(bool checked)
{
    if(checked)
    {
        ui->BH3->setStyleSheet("background-color: blue");
        ui->BH3->setEnabled(checked);
    }
    else
        ui->BH3->setEnabled(checked);
}
void ClassicBoardDialog::on_BH3_clicked()
{

}

void ClassicBoardDialog::BH4_set_state(bool checked)
{
    if(checked)
    {
        ui->BH4->setStyleSheet("background-color: blue");
        ui->BH4->setEnabled(checked);
    }
    else
        ui->BH4->setEnabled(checked);
}
void ClassicBoardDialog::on_BH4_clicked()
{

}
//RED HOME
void ClassicBoardDialog::RH1_set_state(bool checked)
{
    if(checked)
    {
        ui->RH1->setStyleSheet("background-color: RED");
        ui->RH1->setEnabled(checked);
    }
    else
        ui->RH1->setEnabled(checked);
}
void ClassicBoardDialog::on_RH1_clicked()
{

}

void ClassicBoardDialog::RH2_set_state(bool checked)
{
    if(checked)
    {
        ui->RH2->setStyleSheet("background-color: RED");
        ui->RH2->setEnabled(checked);
    }
    else
        ui->RH2->setEnabled(checked);
}
void ClassicBoardDialog::on_RH2_clicked()
{

}

void ClassicBoardDialog::RH3_set_state(bool checked)
{
    if(checked)
    {
        ui->RH3->setStyleSheet("background-color: RED");
        ui->RH3->setEnabled(checked);
    }
    else
        ui->RH3->setEnabled(checked);
}
void ClassicBoardDialog::on_RH3_clicked()
{

}

void ClassicBoardDialog::RH4_set_state(bool checked)
{
    if(checked)
    {
        ui->RH4->setStyleSheet("background-color: RED");
        ui->RH4->setEnabled(checked);
    }
    else
        ui->RH4->setEnabled(checked);
}
void ClassicBoardDialog::on_RH4_clicked()
{

}
//YELLOW HOME
void ClassicBoardDialog::YH4_set_state(bool checked)
{
    if(checked)
    {
        ui->YH4->setStyleSheet("background-color: yellow");
        ui->YH4->setEnabled(checked);
    }
    else
        ui->YH4->setEnabled(checked);
}
void ClassicBoardDialog::on_YH4_clicked()
{

}

void ClassicBoardDialog::YH3_set_state(bool checked)
{
    if(checked)
    {
        ui->YH3->setStyleSheet("background-color: yellow");
        ui->YH3->setEnabled(checked);
    }
    else
        ui->YH3->setEnabled(checked);
}
void ClassicBoardDialog::on_YH3_clicked()
{

}

void ClassicBoardDialog::YH2_set_state(bool checked)
{
    if(checked)
    {
        ui->YH2->setStyleSheet("background-color: yellow");
        ui->YH2->setEnabled(checked);
    }
    else
        ui->YH2->setEnabled(checked);
}
void ClassicBoardDialog::on_YH2_clicked()
{

}

void ClassicBoardDialog::YH1_set_state(bool checked)
{
    if(checked)
    {
        ui->YH1->setStyleSheet("background-color: yellow");
        ui->YH1->setEnabled(checked);
    }
    else
        ui->YH1->setEnabled(checked);
}
void ClassicBoardDialog::on_YH1_clicked()
{

}

void ClassicBoardDialog::on_start_clicked()
{
    emit start_thread();
}
