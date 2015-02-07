#include "classicboarddialog.h"
#include "ui_classicboarddialog.h"

ClassicBoardDialog::ClassicBoardDialog(QWidget *parent ,bool G,QString G_name,bool R,QString R_name,bool B,QString B_name,bool Y,QString Y_name) :
    QDialog(parent),
    ui(new Ui::ClassicBoardDialog){
    game = new Game(G, G_name, R, R_name, B, B_name, Y, Y_name);

    QObject::connect(this, &ClassicBoardDialog::roll_dice, game, &Game::dice_slot);
    QObject::connect(game, &Game::show_dice, this, &ClassicBoardDialog::Show_Dice);
    QObject::connect(game, &Game::set_dice_player, this, &ClassicBoardDialog::set_Dice_Player);

    QObject::connect(this, & ClassicBoardDialog::GBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_1_set_state, this, &ClassicBoardDialog::GBase1);
    QObject::connect(game, &Game::signal_GBase_1_set_token, this, &ClassicBoardDialog::GBase1_set_token);
    QObject::connect(this, & ClassicBoardDialog::GBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_2_set_state, this, &ClassicBoardDialog::GBase2);
    QObject::connect(game, &Game::signal_GBase_2_set_token, this, &ClassicBoardDialog::GBase2_set_token);
    QObject::connect(this, & ClassicBoardDialog::GBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_3_set_state, this, &ClassicBoardDialog::GBase3);
    QObject::connect(game, &Game::signal_GBase_3_set_token, this, &ClassicBoardDialog::GBase3_set_token);
    QObject::connect(this, & ClassicBoardDialog::GBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_GBase_4_set_state, this, &ClassicBoardDialog::GBase4);
    QObject::connect(game, &Game::signal_GBase_4_set_token, this, &ClassicBoardDialog::GBase4_set_token);

    QObject::connect(this, & ClassicBoardDialog::BBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_1_set_state, this, &ClassicBoardDialog::BBase1);
    QObject::connect(game, &Game::signal_BBase_1_set_token, this, &ClassicBoardDialog::GBase1_set_token);
    QObject::connect(this, & ClassicBoardDialog::BBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_2_set_state, this, &ClassicBoardDialog::BBase2);
    QObject::connect(game, &Game::signal_BBase_2_set_token, this, &ClassicBoardDialog::GBase2_set_token);
    QObject::connect(this, & ClassicBoardDialog::BBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_3_set_state, this, &ClassicBoardDialog::BBase3);
    QObject::connect(game, &Game::signal_BBase_3_set_token, this, &ClassicBoardDialog::GBase3_set_token);
    QObject::connect(this, & ClassicBoardDialog::BBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_BBase_4_set_state, this, &ClassicBoardDialog::BBase4);
    QObject::connect(game, &Game::signal_BBase_4_set_token, this, &ClassicBoardDialog::GBase4_set_token);

    QObject::connect(this, & ClassicBoardDialog::RBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_1_set_state, this, &ClassicBoardDialog::RBase1);
    QObject::connect(game, &Game::signal_RBase_1_set_token, this, &ClassicBoardDialog::GBase1_set_token);
    QObject::connect(this, & ClassicBoardDialog::RBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_2_set_state, this, &ClassicBoardDialog::RBase2);
    QObject::connect(game, &Game::signal_RBase_2_set_token, this, &ClassicBoardDialog::GBase2_set_token);
    QObject::connect(this, & ClassicBoardDialog::RBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_3_set_state, this, &ClassicBoardDialog::RBase3);
    QObject::connect(game, &Game::signal_RBase_3_set_token, this, &ClassicBoardDialog::GBase3_set_token);
    QObject::connect(this, & ClassicBoardDialog::RBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_RBase_4_set_state, this, &ClassicBoardDialog::RBase4);
    QObject::connect(game, &Game::signal_RBase_4_set_token, this, &ClassicBoardDialog::GBase4_set_token);

    QObject::connect(this, & ClassicBoardDialog::YBase_1_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_1_set_state, this, &ClassicBoardDialog::YBase1);
    QObject::connect(game, &Game::signal_YBase_1_set_token, this, &ClassicBoardDialog::GBase1_set_token);
    QObject::connect(this, & ClassicBoardDialog::YBase_2_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_2_set_state, this, &ClassicBoardDialog::YBase2);
    QObject::connect(game, &Game::signal_YBase_2_set_token, this, &ClassicBoardDialog::GBase2_set_token);
    QObject::connect(this, & ClassicBoardDialog::YBase_3_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_3_set_state, this, &ClassicBoardDialog::YBase3);
    QObject::connect(game, &Game::signal_YBase_3_set_token, this, &ClassicBoardDialog::GBase3_set_token);
    QObject::connect(this, & ClassicBoardDialog::YBase_4_clicked, game, &Game::limbo_input);
    QObject::connect(game, &Game::signal_YBase_4_set_state, this, &ClassicBoardDialog::YBase4);
    QObject::connect(game, &Game::signal_YBase_4_set_token, this, &ClassicBoardDialog::GBase4_set_token);

    //board connections
    QObject::connect(this, &ClassicBoardDialog::node_0_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_0_set_player, this, &ClassicBoardDialog::node_0_set_player);
    QObject::connect(game, &Game::signal_node_0_set_state, this, &ClassicBoardDialog::node_0_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_1_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_1_set_player, this, &ClassicBoardDialog::node_1_set_player);
    QObject::connect(game, &Game::signal_node_1_set_state, this, &ClassicBoardDialog::node_1_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_2_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_2_set_player, this, &ClassicBoardDialog::node_2_set_player);
    QObject::connect(game, &Game::signal_node_2_set_state, this, &ClassicBoardDialog::node_2_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_3_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_3_set_player, this, &ClassicBoardDialog::node_3_set_player);
    QObject::connect(game, &Game::signal_node_3_set_state, this, &ClassicBoardDialog::node_3_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_4_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_4_set_player, this, &ClassicBoardDialog::node_4_set_player);
    QObject::connect(game, &Game::signal_node_4_set_state, this, &ClassicBoardDialog::node_4_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_5_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_5_set_player, this, &ClassicBoardDialog::node_5_set_player);
    QObject::connect(game, &Game::signal_node_5_set_state, this, &ClassicBoardDialog::node_5_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_6_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_6_set_player, this, &ClassicBoardDialog::node_6_set_player);
    QObject::connect(game, &Game::signal_node_6_set_state, this, &ClassicBoardDialog::node_6_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_7_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_7_set_player, this, &ClassicBoardDialog::node_7_set_player);
    QObject::connect(game, &Game::signal_node_7_set_state, this, &ClassicBoardDialog::node_7_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_8_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_8_set_player, this, &ClassicBoardDialog::node_8_set_player);
    QObject::connect(game, &Game::signal_node_8_set_state, this, &ClassicBoardDialog::node_8_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_9_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_9_set_player, this, &ClassicBoardDialog::node_9_set_player);
    QObject::connect(game, &Game::signal_node_9_set_state, this, &ClassicBoardDialog::node_9_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_10_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_10_set_player, this, &ClassicBoardDialog::node_10_set_player);
    QObject::connect(game, &Game::signal_node_10_set_state, this, &ClassicBoardDialog::node_10_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_11_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_11_set_player, this, &ClassicBoardDialog::node_11_set_player);
    QObject::connect(game, &Game::signal_node_11_set_state, this, &ClassicBoardDialog::node_11_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_12_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_12_set_player, this, &ClassicBoardDialog::node_12_set_player);
    QObject::connect(game, &Game::signal_node_12_set_state, this, &ClassicBoardDialog::node_12_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_13_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_13_set_player, this, &ClassicBoardDialog::node_13_set_player);
    QObject::connect(game, &Game::signal_node_13_set_state, this, &ClassicBoardDialog::node_13_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_14_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_14_set_player, this, &ClassicBoardDialog::node_14_set_player);
    QObject::connect(game, &Game::signal_node_14_set_state, this, &ClassicBoardDialog::node_14_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_15_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_15_set_player, this, &ClassicBoardDialog::node_15_set_player);
    QObject::connect(game, &Game::signal_node_15_set_state, this, &ClassicBoardDialog::node_15_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_16_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_16_set_player, this, &ClassicBoardDialog::node_16_set_player);
    QObject::connect(game, &Game::signal_node_16_set_state, this, &ClassicBoardDialog::node_16_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_17_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_17_set_player, this, &ClassicBoardDialog::node_17_set_player);
    QObject::connect(game, &Game::signal_node_17_set_state, this, &ClassicBoardDialog::node_17_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_18_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_18_set_player, this, &ClassicBoardDialog::node_18_set_player);
    QObject::connect(game, &Game::signal_node_18_set_state, this, &ClassicBoardDialog::node_18_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_19_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_19_set_player, this, &ClassicBoardDialog::node_19_set_player);
    QObject::connect(game, &Game::signal_node_19_set_state, this, &ClassicBoardDialog::node_19_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_20_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_20_set_player, this, &ClassicBoardDialog::node_20_set_player);
    QObject::connect(game, &Game::signal_node_20_set_state, this, &ClassicBoardDialog::node_20_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_21_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_21_set_player, this, &ClassicBoardDialog::node_21_set_player);
    QObject::connect(game, &Game::signal_node_21_set_state, this, &ClassicBoardDialog::node_21_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_22_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_22_set_player, this, &ClassicBoardDialog::node_22_set_player);
    QObject::connect(game, &Game::signal_node_22_set_state, this, &ClassicBoardDialog::node_22_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_23_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_23_set_player, this, &ClassicBoardDialog::node_23_set_player);
    QObject::connect(game, &Game::signal_node_23_set_state, this, &ClassicBoardDialog::node_23_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_24_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_24_set_player, this, &ClassicBoardDialog::node_24_set_player);
    QObject::connect(game, &Game::signal_node_24_set_state, this, &ClassicBoardDialog::node_24_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_25_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_25_set_player, this, &ClassicBoardDialog::node_25_set_player);
    QObject::connect(game, &Game::signal_node_25_set_state, this, &ClassicBoardDialog::node_25_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_26_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_26_set_player, this, &ClassicBoardDialog::node_26_set_player);
    QObject::connect(game, &Game::signal_node_26_set_state, this, &ClassicBoardDialog::node_26_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_27_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_27_set_player, this, &ClassicBoardDialog::node_27_set_player);
    QObject::connect(game, &Game::signal_node_27_set_state, this, &ClassicBoardDialog::node_27_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_28_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_28_set_player, this, &ClassicBoardDialog::node_28_set_player);
    QObject::connect(game, &Game::signal_node_28_set_state, this, &ClassicBoardDialog::node_28_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_29_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_29_set_player, this, &ClassicBoardDialog::node_29_set_player);
    QObject::connect(game, &Game::signal_node_29_set_state, this, &ClassicBoardDialog::node_29_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_30_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_30_set_player, this, &ClassicBoardDialog::node_30_set_player);
    QObject::connect(game, &Game::signal_node_30_set_state, this, &ClassicBoardDialog::node_30_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_31_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_31_set_player, this, &ClassicBoardDialog::node_31_set_player);
    QObject::connect(game, &Game::signal_node_31_set_state, this, &ClassicBoardDialog::node_31_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_32_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_32_set_player, this, &ClassicBoardDialog::node_32_set_player);
    QObject::connect(game, &Game::signal_node_32_set_state, this, &ClassicBoardDialog::node_32_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_33_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_33_set_player, this, &ClassicBoardDialog::node_33_set_player);
    QObject::connect(game, &Game::signal_node_33_set_state, this, &ClassicBoardDialog::node_33_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_34_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_34_set_player, this, &ClassicBoardDialog::node_34_set_player);
    QObject::connect(game, &Game::signal_node_34_set_state, this, &ClassicBoardDialog::node_34_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_35_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_35_set_player, this, &ClassicBoardDialog::node_35_set_player);
    QObject::connect(game, &Game::signal_node_35_set_state, this, &ClassicBoardDialog::node_35_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_36_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_36_set_player, this, &ClassicBoardDialog::node_36_set_player);
    QObject::connect(game, &Game::signal_node_36_set_state, this, &ClassicBoardDialog::node_36_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_37_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_37_set_player, this, &ClassicBoardDialog::node_37_set_player);
    QObject::connect(game, &Game::signal_node_37_set_state, this, &ClassicBoardDialog::node_37_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_38_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_38_set_player, this, &ClassicBoardDialog::node_38_set_player);
    QObject::connect(game, &Game::signal_node_38_set_state, this, &ClassicBoardDialog::node_38_set_state);

    QObject::connect(this, &ClassicBoardDialog::node_39_clicked, game, &Game::classicboard_input);
    QObject::connect(game, &Game::signal_node_39_set_player, this, &ClassicBoardDialog::node_39_set_player);
    QObject::connect(game, &Game::signal_node_39_set_state, this, &ClassicBoardDialog::node_39_set_state);


    QObject::connect(this, &ClassicBoardDialog::GH1_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_GH1_set_state, this, &ClassicBoardDialog::GH1_set_state);
    QObject::connect(this, &ClassicBoardDialog::GH2_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_GH2_set_state, this, &ClassicBoardDialog::GH2_set_state);
    QObject::connect(this, &ClassicBoardDialog::GH3_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_GH3_set_state, this, &ClassicBoardDialog::GH3_set_state);
    QObject::connect(this, &ClassicBoardDialog::GH4_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_GH4_set_state, this, &ClassicBoardDialog::GH4_set_state);

    QObject::connect(this, &ClassicBoardDialog::BH1_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_BH1_set_state, this, &ClassicBoardDialog::BH1_set_state);
    QObject::connect(this, &ClassicBoardDialog::BH2_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_BH2_set_state, this, &ClassicBoardDialog::BH2_set_state);
    QObject::connect(this, &ClassicBoardDialog::BH3_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_BH3_set_state, this, &ClassicBoardDialog::BH3_set_state);
    QObject::connect(this, &ClassicBoardDialog::BH4_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_BH4_set_state, this, &ClassicBoardDialog::BH4_set_state);

    QObject::connect(this, &ClassicBoardDialog::RH1_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_RH1_set_state, this, &ClassicBoardDialog::RH1_set_state);
    QObject::connect(this, &ClassicBoardDialog::RH2_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_RH2_set_state, this, &ClassicBoardDialog::RH2_set_state);
    QObject::connect(this, &ClassicBoardDialog::RH3_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_RH3_set_state, this, &ClassicBoardDialog::RH3_set_state);
    QObject::connect(this, &ClassicBoardDialog::RH4_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_RH4_set_state, this, &ClassicBoardDialog::RH4_set_state);

    QObject::connect(this, &ClassicBoardDialog::YH1_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_YH1_set_state, this, &ClassicBoardDialog::YH1_set_state);
    QObject::connect(this, &ClassicBoardDialog::YH2_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_YH2_set_state, this, &ClassicBoardDialog::YH2_set_state);
    QObject::connect(this, &ClassicBoardDialog::YH3_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_YH3_set_state, this, &ClassicBoardDialog::YH3_set_state);
    QObject::connect(this, &ClassicBoardDialog::YH4_clicked, game, &Game::home_input);
    QObject::connect(game, &Game::signal_YH4_set_state, this, &ClassicBoardDialog::YH4_set_state);

    //Thread connections
    QObject::connect(this, &ClassicBoardDialog::wake_thread, game->game_thread, &GameThread::wakeThread);
    //=====================

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
    emit wake_thread();
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

    if(player == 0)//allmost working as intendet
        ui->green_player_name->setStyleSheet("background-color: green");
    else
        ui->green_player_name->setStyleSheet("background-color: white");
    if(player == 1)
        ui->blue_player_name->setStyleSheet("background-color: blue");
    else
        ui->blue_player_name->setStyleSheet("background-color: white");
    if(player == 2)
        ui->red_player_name->setStyleSheet("background-color: red");
    else
        ui->red_player_name->setStyleSheet("background-color: white");
    if(player == 3)
        ui->yellow_player_name->setStyleSheet("background-color: yellow");
    else
        ui->yellow_player_name->setStyleSheet("background-color: white");
}

//------------------------------------------------------------------------
// GREEN LIMBO
//------------------------------------------------------------------------

void ClassicBoardDialog::GBase1_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->GBase1->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->GBase1->setChecked(false);// button is pushed
        ui->GBase1->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_GBase1_clicked()
{
    emit GBase_1_clicked(0);
    emit wake_thread();
}
void ClassicBoardDialog::GBase1(bool checked)
{
    if(!checked) // if not player
    {
        ui->GBase1->setStyleSheet("background-color: green");
        ui->GBase1->setEnabled(false);

    }
    else // if player
    {
        ui->GBase1->setStyleSheet("background-color: white");
        ui->GBase1->setEnabled(true);
    }
}


void ClassicBoardDialog::GBase2_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->GBase2->setChecked(true);
    }
    else
    {
        ui->GBase2->setChecked(false);
        ui->GBase2->setEnabled(false);
    }
}

void ClassicBoardDialog::on_GBase2_clicked()
{
    emit GBase_2_clicked(1);
    emit wake_thread();
}
void ClassicBoardDialog::GBase2(bool checked)
{
    if(!checked)
    {
        ui->GBase2->setStyleSheet("background-color: green");
        ui->GBase2->setEnabled(false);
    }
    else
    {
        ui->GBase2->setStyleSheet("background-color: white");
        ui->GBase2->setEnabled(true);
    }
}


void ClassicBoardDialog::GBase3_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->GBase3->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->GBase3->setChecked(false);// button is pushed
        ui->GBase3->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_GBase3_clicked()
{
    emit GBase_3_clicked(2);
    emit wake_thread();
}
void ClassicBoardDialog::GBase3(bool checked)
{
    if(!checked)
    {
        ui->GBase3->setStyleSheet("background-color: green");
        ui->GBase3->setEnabled(false);
    }
    else
    {
        ui->GBase3->setStyleSheet("background-color: white");
        ui->GBase3->setEnabled(true);
    }
}


void ClassicBoardDialog::GBase4_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->GBase4->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->GBase4->setChecked(false);// button is pushed
        ui->GBase4->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_GBase4_clicked()
{
    emit GBase_4_clicked(3);
    emit wake_thread();
}
void ClassicBoardDialog::GBase4(bool checked)
{
    if(!checked)
    {
        ui->GBase4->setStyleSheet("background-color: green");
        ui->GBase4->setEnabled(false);
    }
    else
    {
        ui->GBase4->setStyleSheet("background-color: white");
        ui->GBase4->setEnabled(true);
    }
}


//------------------------------------------------------------------------
// BLUE LIMBO
//------------------------------------------------------------------------

void ClassicBoardDialog::BBase1_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->BBase1->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->BBase1->setChecked(false);// button is pushed
        ui->BBase1->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_BBase1_clicked()
{
    emit BBase_1_clicked(0);
    emit wake_thread();
}
void ClassicBoardDialog::BBase1(bool checked)
{
    if(!checked)
    {
        ui->BBase1->setStyleSheet("background-color: blue");
        ui->BBase1->setEnabled(false);
    }
    else
    {
        ui->BBase1->setStyleSheet("background-color: white");
        ui->BBase1->setEnabled(true);
    }
}


void ClassicBoardDialog::BBase2_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->BBase2->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->BBase2->setChecked(false);// button is pushed
        ui->BBase2->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_BBase2_clicked()
{
    emit BBase_2_clicked(1);
    emit wake_thread();
}
void ClassicBoardDialog::BBase2(bool checked)
{
    if(!checked)
    {
        ui->BBase2->setStyleSheet("background-color: blue");
        ui->BBase2->setEnabled(false);
    }
    else
    {
        ui->BBase2->setStyleSheet("background-color: white");
        ui->BBase2->setEnabled(true);
    }
}


void ClassicBoardDialog::BBase3_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->BBase3->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->BBase3->setChecked(false);// button is pushed
        ui->BBase3->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_BBase3_clicked()
{
    emit BBase_3_clicked(2);
    emit wake_thread();
}
void ClassicBoardDialog::BBase3(bool checked)
{
    if(!checked)
    {
        ui->BBase3->setStyleSheet("background-color: blue");
        ui->BBase3->setEnabled(false);
    }
    else
    {
        ui->BBase3->setStyleSheet("background-color: white");
        ui->BBase3->setEnabled(true);
    }
}


void ClassicBoardDialog::BBase4_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->BBase4->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->BBase4->setChecked(false);// button is pushed
        ui->BBase4->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_BBase4_clicked()
{
    emit BBase_4_clicked(3);
    emit wake_thread();
}
void ClassicBoardDialog::BBase4(bool checked)
{
    if(!checked)
    {
        ui->BBase4->setStyleSheet("background-color: blue");
        ui->BBase4->setEnabled(false);
    }
    else
    {
        ui->BBase4->setStyleSheet("background-color: white");
        ui->BBase4->setEnabled(true);
    }
}

//------------------------------------------------------------------------
// RED LIMBO
//------------------------------------------------------------------------


void ClassicBoardDialog::RBase1_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->RBase1->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->RBase1->setChecked(false);// button is pushed
        ui->RBase1->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_RBase1_clicked()
{
    emit RBase_1_clicked(0);
    emit wake_thread();
}
void ClassicBoardDialog::RBase1(bool checked)
{
    if(!checked){
        ui->RBase1->setStyleSheet("background-color: red");
        ui->RBase1->setEnabled(false);
    }
    else{
        ui->RBase1->setStyleSheet("background-color: white");
        ui->RBase1->setEnabled(true);
    }
}


void ClassicBoardDialog::RBase2_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->RBase2->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->RBase2->setChecked(false);// button is pushed
        ui->RBase2->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_RBase2_clicked()
{
    emit RBase_2_clicked(1);
    emit wake_thread();
}
void ClassicBoardDialog::RBase2(bool checked)
{
    if(!checked){
        ui->RBase2->setStyleSheet("background-color: red");
        ui->RBase2->setEnabled(false);
    }
    else{
        ui->RBase2->setStyleSheet("background-color: white");
        ui->RBase2->setEnabled(true);
    }
}

void ClassicBoardDialog::on_RBase3_clicked()
{
    emit RBase_3_clicked(2);
    emit wake_thread();
}
void ClassicBoardDialog::RBase3(bool checked)
{
    if(!checked){
        ui->RBase3->setStyleSheet("background-color: red");
        ui->RBase3->setEnabled(false);
    }
    else{
        ui->RBase3->setStyleSheet("background-color: white");
        ui->RBase3->setEnabled(true);
    }
}
void ClassicBoardDialog::RBase3_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->RBase3->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->RBase3->setChecked(false);// button is pushed
        ui->RBase3->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_RBase4_clicked()
{
    emit RBase_4_clicked(3);
    emit wake_thread();
}
void ClassicBoardDialog::RBase4(bool checked)
{
    if(!checked){
        ui->RBase4->setStyleSheet("background-color: red");
        ui->RBase4->setEnabled(false);
    }

    else{
        ui->RBase4->setStyleSheet("background-color: white");
        ui->RBase4->setEnabled(true);
    }

}
void ClassicBoardDialog::RBase4_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->RBase4->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->RBase4->setChecked(false);// button is pushed
        ui->RBase4->setEnabled(false);// when no piece home the button is disabled
    }
}
//------------------------------------------------------------------------
// YELLOW LIMBO
//------------------------------------------------------------------------
void ClassicBoardDialog::on_YBase1_clicked()
{
    emit YBase_1_clicked(0);
    emit wake_thread();
}
void ClassicBoardDialog::YBase1(bool checked)
{
    if(!checked){
        ui->YBase1->setStyleSheet("background-color: yellow");
        ui->YBase1->setEnabled(false);
    }
    else
    {
        ui->YBase1->setStyleSheet("background-color: white");
        ui->YBase1->setEnabled(true);
    }
}
void ClassicBoardDialog::YBase1_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->YBase1->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->YBase1->setChecked(false);// button is pushed
        ui->YBase1->setEnabled(false);// when no piece home the button is disabled
    }
}
void ClassicBoardDialog::on_YBase2_clicked()
{
    emit YBase_2_clicked(1);
    emit wake_thread();
}
void ClassicBoardDialog::YBase2(bool checked)
{
    if(!checked){
        ui->YBase2->setStyleSheet("background-color: yellow");
        ui->YBase2->setEnabled(false);
    }
    else{
        ui->YBase2->setStyleSheet("background-color: white");
        ui->YBase2->setEnabled(true);
    }
}
void ClassicBoardDialog::YBase2_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->YBase2->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->YBase2->setChecked(false);// button is pushed
        ui->YBase2->setEnabled(false);// when no piece home the button is disabled
    }
}

void ClassicBoardDialog::on_YBase3_clicked()
{
    emit YBase_3_clicked(2);
    emit wake_thread();
}
void ClassicBoardDialog::YBase3(bool checked)
{
    if(!checked){
        ui->YBase3->setStyleSheet("background-color: yellow");
        ui->YBase3->setEnabled(false);
    }
    else{
        ui->YBase3->setStyleSheet("background-color: white");
        ui->YBase3->setEnabled(true);
    }
}
void ClassicBoardDialog::YBase3_set_token(bool isPushed)
{
    if(!isPushed)
    {
        ui->YBase3->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->YBase3->setChecked(false);// button is pushed
        ui->YBase3->setEnabled(false);// when no piece home the button is disabled
    }
}

void ClassicBoardDialog::on_YBase4_clicked()
{
    emit YBase_4_clicked(3);
    emit wake_thread();
}
void ClassicBoardDialog::YBase4(bool checked)
{
    if(!checked){
        ui->YBase4->setStyleSheet("background-color: yellow");
        ui->YBase4->setEnabled(false);
    }
    else{
        ui->YBase4->setStyleSheet("background-color: white");
        ui->YBase4->setEnabled(true);
    }
}
void ClassicBoardDialog::YBase4_set_token(bool isPushed)
{
    if(!!isPushed)
    {
        ui->YBase4->setChecked(true);// if piece is home -> button is up
    }
    else
    {
        ui->YBase4->setChecked(false);// button is pushed
        ui->YBase4->setEnabled(false);// when no piece home the button is disabled
    }
}
//------------------------------------------------------------------------
// BOARD
//------------------------------------------------------------------------
void ClassicBoardDialog::on_node_0_clicked()
{
    emit node_0_clicked(0);
    emit wake_thread();
}
void ClassicBoardDialog::node_0_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_0->setStyleSheet("background-color: white");
        ui->node_0->setEnabled(false);
        break;
    case 0:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_0->setEnabled(true);
        ui->node_0->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_1_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_1->setStyleSheet("background-color: white");
        ui->node_1->setEnabled(false);
        break;
    case 0:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_1->setEnabled(true);
        ui->node_1->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}

void ClassicBoardDialog::node_2_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_2->setStyleSheet("background-color: white");
        ui->node_2->setEnabled(false);
        break;
    case 0:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_2->setEnabled(true);
        ui->node_2->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_3_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_3->setStyleSheet("background-color: white");
        ui->node_3->setEnabled(false);
        break;
    case 0:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_3->setEnabled(true);
        ui->node_3->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_4_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_4->setStyleSheet("background-color: white");
        ui->node_4->setEnabled(false);
        break;
    case 0:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_4->setEnabled(true);
        ui->node_4->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_5_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_5->setStyleSheet("background-color: white");
        ui->node_5->setEnabled(false);
        break;
    case 0:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_5->setEnabled(true);
        ui->node_5->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_6_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_6->setStyleSheet("background-color: white");
        ui->node_6->setEnabled(false);
        break;
    case 0:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: red");
        break;

    case 3:
        ui->node_6->setEnabled(true);
        ui->node_6->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_7_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_7->setStyleSheet("background-color: white");
        ui->node_7->setEnabled(false);
        break;
    case 0:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: green");
        break;

    case 1:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: blue");
        break;

    case 2:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_7->setEnabled(true);
        ui->node_7->setStyleSheet("background-color: yellow");
        break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_8_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_8->setStyleSheet("background-color: white");
        ui->node_8->setEnabled(false);
                break;
    case 0:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_8->setEnabled(true);
        ui->node_8->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_9_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_9->setStyleSheet("background-color: white");
        ui->node_9->setEnabled(false);
                break;
    case 0:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_9->setEnabled(true);
        ui->node_9->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_10_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_10->setStyleSheet("background-color: white");
        ui->node_10->setEnabled(false);
                break;
    case 0:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_10->setEnabled(true);
        ui->node_10->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_11_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_11->setStyleSheet("background-color: white");
        ui->node_11->setEnabled(false);
                break;
    case 0:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_11->setEnabled(true);
        ui->node_11->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_12_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_12->setStyleSheet("background-color: white");
        ui->node_12->setEnabled(false);
                break;
    case 0:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_12->setEnabled(true);
        ui->node_12->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_13_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_13->setStyleSheet("background-color: white");
        ui->node_13->setEnabled(false);
        break;
    case 0:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_13->setEnabled(true);
        ui->node_13->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_14_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_14->setStyleSheet("background-color: white");
        ui->node_14->setEnabled(false);
                break;
    case 0:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_14->setEnabled(true);
        ui->node_14->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_15_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_15->setStyleSheet("background-color: white");
        ui->node_15->setEnabled(false);
                break;
    case 0:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_15->setEnabled(true);
        ui->node_15->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_16_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_16->setStyleSheet("background-color: white");
        ui->node_16->setEnabled(false);
                break;
    case 0:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_16->setEnabled(true);
        ui->node_16->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_17_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_17->setStyleSheet("background-color: white");
        ui->node_17->setEnabled(false);
                break;
    case 0:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_17->setEnabled(true);
        ui->node_17->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_18_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_18->setStyleSheet("background-color: white");
        ui->node_18->setEnabled(false);
                break;
    case 0:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_18->setEnabled(true);
        ui->node_18->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_19_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_19->setStyleSheet("background-color: white");
        ui->node_19->setEnabled(false);
                break;
    case 0:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_19->setEnabled(true);
        ui->node_19->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_20_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_20->setStyleSheet("background-color: white");
        ui->node_20->setEnabled(false);
                break;
    case 0:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_20->setEnabled(true);
        ui->node_20->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_21_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_21->setStyleSheet("background-color: white");
        ui->node_21->setEnabled(false);
                break;
    case 0:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_21->setEnabled(true);
        ui->node_21->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_22_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_22->setStyleSheet("background-color: white");
        ui->node_22->setEnabled(false);
                break;
    case 0:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_22->setEnabled(true);
        ui->node_22->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_23_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_23->setStyleSheet("background-color: white");
        ui->node_23->setEnabled(false);
                break;
    case 0:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_23->setEnabled(true);
        ui->node_23->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_24_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_24->setStyleSheet("background-color: white");
        ui->node_24->setEnabled(false);
                break;
    case 0:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: green");
                break;

    case 1:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_24->setEnabled(true);
        ui->node_24->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_25_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_25->setStyleSheet("background-color: white");
        ui->node_25->setEnabled(false);
                break;
    case 0:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_25->setEnabled(true);
        ui->node_25->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_26_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_26->setStyleSheet("background-color: white");
        ui->node_26->setEnabled(false);
                break;
    case 0:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_26->setEnabled(true);
        ui->node_26->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_27_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_27->setStyleSheet("background-color: white");
        ui->node_27->setEnabled(false);
                break;
    case 0:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_27->setEnabled(true);
        ui->node_27->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_28_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_28->setStyleSheet("background-color: white");
        ui->node_28->setEnabled(false);
                break;
    case 0:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: green");
                break;

    case 1:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: blue");
                break;

    case 2:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_28->setEnabled(true);
        ui->node_28->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_29_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_29->setStyleSheet("background-color: white");
        ui->node_29->setEnabled(false);
                break;
    case 0:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_29->setEnabled(true);
        ui->node_29->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_30_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_30->setStyleSheet("background-color: white");
        ui->node_30->setEnabled(false);
                break;
    case 0:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: green");
                break;

    case 1:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_30->setEnabled(true);
        ui->node_30->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_31_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_31->setStyleSheet("background-color: white");
        ui->node_31->setEnabled(false);
                break;
    case 0:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_31->setEnabled(true);
        ui->node_31->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_32_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_32->setStyleSheet("background-color: white");
        ui->node_32->setEnabled(false);
                break;
    case 0:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_32->setEnabled(true);
        ui->node_32->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_33_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_33->setStyleSheet("background-color: white");
        ui->node_33->setEnabled(false);
                break;
    case 0:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_33->setEnabled(true);
        ui->node_33->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_34_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_34->setStyleSheet("background-color: white");
        ui->node_34->setEnabled(false);
                break;
    case 0:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_34->setEnabled(true);
        ui->node_34->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_35_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_35->setStyleSheet("background-color: white");
        ui->node_35->setEnabled(false);
                break;
    case 0:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_35->setEnabled(true);
        ui->node_35->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_36_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_36->setStyleSheet("background-color: white");
        ui->node_36->setEnabled(false);
                break;
    case 0:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_36->setEnabled(true);
        ui->node_36->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_37_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_37->setStyleSheet("background-color: white");
        ui->node_37->setEnabled(false);
                break;
    case 0:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_37->setEnabled(true);
        ui->node_37->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_38_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_38->setStyleSheet("background-color: white");
        ui->node_38->setEnabled(false);
                break;
    case 0:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_38->setEnabled(true);
        ui->node_38->setStyleSheet("background-color: yellow");
                break;
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
    emit wake_thread();
}
void ClassicBoardDialog::node_39_set_player(int player_id)
{
    switch(player_id)
    {
    default:
        ui->node_39->setStyleSheet("background-color: white");
        ui->node_39->setEnabled(false);
                break;
    case 0:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: green");
        break;
    case 1:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: blue");
        break;
    case 2:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: red");
        break;
    case 3:
        ui->node_39->setEnabled(true);
        ui->node_39->setStyleSheet("background-color: yellow");
                break;
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

