#include "game_class.h"

Game::Game(bool G, string G_name, bool R, string R_name, bool B, string B_name, bool Y, string Y_name)
{
    done = false;
    roll_six = false;
    turn = 1;

    game_field = new Field();


    player_list[0] = new Player(G_name, 0, G, game_field, player_list);
//cout<<G_name;
    player_list[1] = new Player(R_name, 1, R, game_field, player_list);
//cout<<R_name;
    player_list[2] = new Player(B_name, 2, B, game_field, player_list);
//cout<<B_name;
    player_list[3] = new Player(Y_name, 3, Y, game_field, player_list);
//cout<<Y_name;

    classicboarddialog = new ClassicBoardDialog(0);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::roll_the_dice,  this, &Game::dice_slot);
    QObject::connect(this, &Game::show_dice, classicboarddialog, &ClassicBoardDialog::Show_Dice);
    QObject::connect(this, &Game::set_dice_player,classicboarddialog, &ClassicBoardDialog::set_Dice_Player);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::GBase_1_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_GBase_1_set_state, classicboarddialog, & ClassicBoardDialog::GBase1);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::GBase_2_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_GBase_2_set_state, classicboarddialog, & ClassicBoardDialog::GBase2);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::GBase_3_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_GBase_3_set_state, classicboarddialog, & ClassicBoardDialog::GBase3);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::GBase_4_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_GBase_4_set_state, classicboarddialog, & ClassicBoardDialog::GBase4);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::BBase_1_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_BBase_1_set_state, classicboarddialog, & ClassicBoardDialog::BBase1);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::BBase_2_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_BBase_2_set_state, classicboarddialog, & ClassicBoardDialog::BBase2);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::BBase_3_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_BBase_3_set_state, classicboarddialog, & ClassicBoardDialog::BBase3);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::BBase_4_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_BBase_4_set_state, classicboarddialog, & ClassicBoardDialog::BBase4);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::RBase_1_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_RBase_1_set_state, classicboarddialog, & ClassicBoardDialog::RBase1);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::RBase_2_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_RBase_2_set_state, classicboarddialog, & ClassicBoardDialog::RBase2);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::RBase_3_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_RBase_3_set_state, classicboarddialog, & ClassicBoardDialog::RBase3);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::RBase_4_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_RBase_4_set_state, classicboarddialog, & ClassicBoardDialog::RBase4);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::YBase_1_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_YBase_1_set_state, classicboarddialog, & ClassicBoardDialog::YBase1);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::YBase_2_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_YBase_2_set_state, classicboarddialog, & ClassicBoardDialog::YBase2);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::YBase_3_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_YBase_3_set_state, classicboarddialog, & ClassicBoardDialog::YBase3);

    QObject::connect(classicboarddialog, & ClassicBoardDialog::YBase_4_clicked, this, & Game::limbo_input);
    QObject::connect(this, &Game::signal_YBase_4_set_state, classicboarddialog, & ClassicBoardDialog::YBase4);

    //board connections
    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_0_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_0_set_player, classicboarddialog, &ClassicBoardDialog::node_0_set_player);
    QObject::connect(this, &Game::signal_node_0_set_state, classicboarddialog, &ClassicBoardDialog::node_0_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_1_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_1_set_player, classicboarddialog, &ClassicBoardDialog::node_1_set_player);
    QObject::connect(this, &Game::signal_node_1_set_state, classicboarddialog, &ClassicBoardDialog::node_1_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_2_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_2_set_player, classicboarddialog, &ClassicBoardDialog::node_2_set_player);
    QObject::connect(this, &Game::signal_node_2_set_state, classicboarddialog, &ClassicBoardDialog::node_2_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_3_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_3_set_player, classicboarddialog, &ClassicBoardDialog::node_3_set_player);
    QObject::connect(this, &Game::signal_node_3_set_state, classicboarddialog, &ClassicBoardDialog::node_3_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_4_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_4_set_player, classicboarddialog, &ClassicBoardDialog::node_4_set_player);
    QObject::connect(this, &Game::signal_node_4_set_state, classicboarddialog, &ClassicBoardDialog::node_4_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_5_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_5_set_player, classicboarddialog, &ClassicBoardDialog::node_5_set_player);
    QObject::connect(this, &Game::signal_node_5_set_state, classicboarddialog, &ClassicBoardDialog::node_5_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_6_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_6_set_player, classicboarddialog, &ClassicBoardDialog::node_6_set_player);
    QObject::connect(this, &Game::signal_node_6_set_state, classicboarddialog, &ClassicBoardDialog::node_6_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_7_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_7_set_player, classicboarddialog, &ClassicBoardDialog::node_7_set_player);
    QObject::connect(this, &Game::signal_node_7_set_state, classicboarddialog, &ClassicBoardDialog::node_7_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_8_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_8_set_player, classicboarddialog, &ClassicBoardDialog::node_8_set_player);
    QObject::connect(this, &Game::signal_node_8_set_state, classicboarddialog, &ClassicBoardDialog::node_8_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_9_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_9_set_player, classicboarddialog, &ClassicBoardDialog::node_9_set_player);
    QObject::connect(this, &Game::signal_node_9_set_state, classicboarddialog, &ClassicBoardDialog::node_9_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_10_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_10_set_player, classicboarddialog, &ClassicBoardDialog::node_10_set_player);
    QObject::connect(this, &Game::signal_node_10_set_state, classicboarddialog, &ClassicBoardDialog::node_10_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_11_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_11_set_player, classicboarddialog, &ClassicBoardDialog::node_11_set_player);
    QObject::connect(this, &Game::signal_node_11_set_state, classicboarddialog, &ClassicBoardDialog::node_11_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_12_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_12_set_player, classicboarddialog, &ClassicBoardDialog::node_12_set_player);
    QObject::connect(this, &Game::signal_node_12_set_state, classicboarddialog, &ClassicBoardDialog::node_12_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_13_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_13_set_player, classicboarddialog, &ClassicBoardDialog::node_13_set_player);
    QObject::connect(this, &Game::signal_node_13_set_state, classicboarddialog, &ClassicBoardDialog::node_13_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_14_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_14_set_player, classicboarddialog, &ClassicBoardDialog::node_14_set_player);
    QObject::connect(this, &Game::signal_node_14_set_state, classicboarddialog, &ClassicBoardDialog::node_14_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_15_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_15_set_player, classicboarddialog, &ClassicBoardDialog::node_15_set_player);
    QObject::connect(this, &Game::signal_node_15_set_state, classicboarddialog, &ClassicBoardDialog::node_15_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_16_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_16_set_player, classicboarddialog, &ClassicBoardDialog::node_16_set_player);
    QObject::connect(this, &Game::signal_node_16_set_state, classicboarddialog, &ClassicBoardDialog::node_16_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_17_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_17_set_player, classicboarddialog, &ClassicBoardDialog::node_17_set_player);
    QObject::connect(this, &Game::signal_node_17_set_state, classicboarddialog, &ClassicBoardDialog::node_17_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_18_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_18_set_player, classicboarddialog, &ClassicBoardDialog::node_18_set_player);
    QObject::connect(this, &Game::signal_node_18_set_state, classicboarddialog, &ClassicBoardDialog::node_18_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_19_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_19_set_player, classicboarddialog, &ClassicBoardDialog::node_19_set_player);
    QObject::connect(this, &Game::signal_node_19_set_state, classicboarddialog, &ClassicBoardDialog::node_19_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_20_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_20_set_player, classicboarddialog, &ClassicBoardDialog::node_20_set_player);
    QObject::connect(this, &Game::signal_node_20_set_state, classicboarddialog, &ClassicBoardDialog::node_20_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_21_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_21_set_player, classicboarddialog, &ClassicBoardDialog::node_21_set_player);
    QObject::connect(this, &Game::signal_node_21_set_state, classicboarddialog, &ClassicBoardDialog::node_21_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_22_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_22_set_player, classicboarddialog, &ClassicBoardDialog::node_22_set_player);
    QObject::connect(this, &Game::signal_node_22_set_state, classicboarddialog, &ClassicBoardDialog::node_22_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_23_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_23_set_player, classicboarddialog, &ClassicBoardDialog::node_23_set_player);
    QObject::connect(this, &Game::signal_node_23_set_state, classicboarddialog, &ClassicBoardDialog::node_23_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_24_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_24_set_player, classicboarddialog, &ClassicBoardDialog::node_24_set_player);
    QObject::connect(this, &Game::signal_node_24_set_state, classicboarddialog, &ClassicBoardDialog::node_24_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_25_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_25_set_player, classicboarddialog, &ClassicBoardDialog::node_25_set_player);
    QObject::connect(this, &Game::signal_node_25_set_state, classicboarddialog, &ClassicBoardDialog::node_25_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_26_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_26_set_player, classicboarddialog, &ClassicBoardDialog::node_26_set_player);
    QObject::connect(this, &Game::signal_node_26_set_state, classicboarddialog, &ClassicBoardDialog::node_26_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_27_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_27_set_player, classicboarddialog, &ClassicBoardDialog::node_27_set_player);
    QObject::connect(this, &Game::signal_node_27_set_state, classicboarddialog, &ClassicBoardDialog::node_27_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_28_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_28_set_player, classicboarddialog, &ClassicBoardDialog::node_28_set_player);
    QObject::connect(this, &Game::signal_node_28_set_state, classicboarddialog, &ClassicBoardDialog::node_28_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_29_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_29_set_player, classicboarddialog, &ClassicBoardDialog::node_29_set_player);
    QObject::connect(this, &Game::signal_node_29_set_state, classicboarddialog, &ClassicBoardDialog::node_29_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_30_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_30_set_player, classicboarddialog, &ClassicBoardDialog::node_30_set_player);
    QObject::connect(this, &Game::signal_node_30_set_state, classicboarddialog, &ClassicBoardDialog::node_30_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_31_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_31_set_player, classicboarddialog, &ClassicBoardDialog::node_31_set_player);
    QObject::connect(this, &Game::signal_node_31_set_state, classicboarddialog, &ClassicBoardDialog::node_31_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_32_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_32_set_player, classicboarddialog, &ClassicBoardDialog::node_32_set_player);
    QObject::connect(this, &Game::signal_node_32_set_state, classicboarddialog, &ClassicBoardDialog::node_32_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_33_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_33_set_player, classicboarddialog, &ClassicBoardDialog::node_33_set_player);
    QObject::connect(this, &Game::signal_node_33_set_state, classicboarddialog, &ClassicBoardDialog::node_33_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_34_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_34_set_player, classicboarddialog, &ClassicBoardDialog::node_34_set_player);
    QObject::connect(this, &Game::signal_node_34_set_state, classicboarddialog, &ClassicBoardDialog::node_34_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_35_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_35_set_player, classicboarddialog, &ClassicBoardDialog::node_35_set_player);
    QObject::connect(this, &Game::signal_node_35_set_state, classicboarddialog, &ClassicBoardDialog::node_35_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_36_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_36_set_player, classicboarddialog, &ClassicBoardDialog::node_36_set_player);
    QObject::connect(this, &Game::signal_node_36_set_state, classicboarddialog, &ClassicBoardDialog::node_36_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_37_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_37_set_player, classicboarddialog, &ClassicBoardDialog::node_37_set_player);
    QObject::connect(this, &Game::signal_node_37_set_state, classicboarddialog, &ClassicBoardDialog::node_37_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_38_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_38_set_player, classicboarddialog, &ClassicBoardDialog::node_38_set_player);
    QObject::connect(this, &Game::signal_node_38_set_state, classicboarddialog, &ClassicBoardDialog::node_38_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::on_node_39_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_39_set_player, classicboarddialog, &ClassicBoardDialog::node_39_set_player);
    QObject::connect(this, &Game::signal_node_39_set_state, classicboarddialog, &ClassicBoardDialog::node_39_set_state);

    //-----------------

    classicboarddialog->setModal(true);
    classicboarddialog->exec();
}

Game::~Game()
{
    for (int i = 0; i < player_num; i++)
    {
        delete player_list[i];
    }
    delete game_field;
    delete classicboarddialog;
}

void Game::play()
{
    while (!done)
    {
        game_turn();
    }
}

void Game::game_turn()
{
    for (int i = 0; i < player_num; i++)
    {
        if(player_list[i]->is_player_bot() == false)
        {
            player_turn(i+1);
            if (roll_six == true)
                player_turn(i+1);
            roll_six = false;
        }
        else
        {
            //ai_turn(i+1);
            if (roll_six == true)
                // ai_turn(i+1);
            roll_six = false;
        }
    }
    turn++;
}

void Game::player_turn(int plr_ID)
{
    //int roll = 0;
   // int choice;

    if (player_list[plr_ID-1]->is_player_active() == true)
    {

    } else {


    }
}

void Game::ai_turn(int plr_ID)
{
    int roll = 0;

   // roll = dice();

    if( roll == 6)
    {
        roll_six = true;
    }

    if(player_list[plr_ID-1]->is_player_active() == true)
    {
        //player_list[plr_ID-1]->ai_exec(roll);
    }
    else
    {
        for(int i = 0; i < 2; i++)
        {
            if(roll_six == true)
            {
                //player_list[plr_ID-1]->ai_exec(roll);
                roll_six = false;
                break;
            }
        }
    }
}

//SIGNAL EMIT'S -> BOARD
//------------------------------------------------------------------------
void Game::update_classicboard()
{
    //LIMBO
    emit signal_GBase_1_set_state(this->player_list[0]->piece_list[0]->is_piece_home());
    emit signal_GBase_2_set_state(this->player_list[0]->piece_list[1]->is_piece_home());
    emit signal_GBase_3_set_state(this->player_list[0]->piece_list[2]->is_piece_home());
    emit signal_GBase_4_set_state(this->player_list[0]->piece_list[3]->is_piece_home());

    emit signal_BBase_1_set_state(this->player_list[1]->piece_list[0]->is_piece_home());
    emit signal_BBase_2_set_state(this->player_list[1]->piece_list[1]->is_piece_home());
    emit signal_BBase_3_set_state(this->player_list[1]->piece_list[2]->is_piece_home());
    emit signal_BBase_4_set_state(this->player_list[1]->piece_list[3]->is_piece_home());

    emit signal_RBase_1_set_state(this->player_list[2]->piece_list[0]->is_piece_home());
    emit signal_RBase_2_set_state(this->player_list[2]->piece_list[1]->is_piece_home());
    emit signal_RBase_3_set_state(this->player_list[2]->piece_list[2]->is_piece_home());
    emit signal_RBase_4_set_state(this->player_list[2]->piece_list[3]->is_piece_home());

    emit signal_YBase_1_set_state(this->player_list[3]->piece_list[0]->is_piece_home());
    emit signal_YBase_2_set_state(this->player_list[3]->piece_list[1]->is_piece_home());
    emit signal_YBase_3_set_state(this->player_list[3]->piece_list[2]->is_piece_home());
    emit signal_YBase_4_set_state(this->player_list[3]->piece_list[3]->is_piece_home());

//BOARD
    emit signal_node_0_set_player(this->game_field->node_list[0]->occupied_piece->get_piece_player_id());
    emit signal_node_1_set_player(this->game_field->node_list[1]->occupied_piece->get_piece_player_id());
    emit signal_node_2_set_player(this->game_field->node_list[2]->occupied_piece->get_piece_player_id());
    emit signal_node_3_set_player(this->game_field->node_list[3]->occupied_piece->get_piece_player_id());
    emit signal_node_4_set_player(this->game_field->node_list[4]->occupied_piece->get_piece_player_id());
    emit signal_node_5_set_player(this->game_field->node_list[5]->occupied_piece->get_piece_player_id());
    emit signal_node_6_set_player(this->game_field->node_list[6]->occupied_piece->get_piece_player_id());
    emit signal_node_7_set_player(this->game_field->node_list[7]->occupied_piece->get_piece_player_id());
    emit signal_node_8_set_player(this->game_field->node_list[8]->occupied_piece->get_piece_player_id());
    emit signal_node_9_set_player(this->game_field->node_list[9]->occupied_piece->get_piece_player_id());

    emit signal_node_10_set_player(this->game_field->node_list[10]->occupied_piece->get_piece_player_id());
    emit signal_node_11_set_player(this->game_field->node_list[11]->occupied_piece->get_piece_player_id());
    emit signal_node_12_set_player(this->game_field->node_list[12]->occupied_piece->get_piece_player_id());
    emit signal_node_13_set_player(this->game_field->node_list[13]->occupied_piece->get_piece_player_id());
    emit signal_node_14_set_player(this->game_field->node_list[14]->occupied_piece->get_piece_player_id());
    emit signal_node_15_set_player(this->game_field->node_list[15]->occupied_piece->get_piece_player_id());
    emit signal_node_16_set_player(this->game_field->node_list[16]->occupied_piece->get_piece_player_id());
    emit signal_node_17_set_player(this->game_field->node_list[17]->occupied_piece->get_piece_player_id());
    emit signal_node_18_set_player(this->game_field->node_list[18]->occupied_piece->get_piece_player_id());
    emit signal_node_19_set_player(this->game_field->node_list[19]->occupied_piece->get_piece_player_id());

    emit signal_node_20_set_player(this->game_field->node_list[20]->occupied_piece->get_piece_player_id());
    emit signal_node_21_set_player(this->game_field->node_list[21]->occupied_piece->get_piece_player_id());
    emit signal_node_22_set_player(this->game_field->node_list[22]->occupied_piece->get_piece_player_id());
    emit signal_node_23_set_player(this->game_field->node_list[23]->occupied_piece->get_piece_player_id());
    emit signal_node_24_set_player(this->game_field->node_list[24]->occupied_piece->get_piece_player_id());
    emit signal_node_25_set_player(this->game_field->node_list[25]->occupied_piece->get_piece_player_id());
    emit signal_node_26_set_player(this->game_field->node_list[26]->occupied_piece->get_piece_player_id());
    emit signal_node_27_set_player(this->game_field->node_list[27]->occupied_piece->get_piece_player_id());
    emit signal_node_28_set_player(this->game_field->node_list[28]->occupied_piece->get_piece_player_id());
    emit signal_node_29_set_player(this->game_field->node_list[29]->occupied_piece->get_piece_player_id());

    emit signal_node_30_set_player(this->game_field->node_list[30]->occupied_piece->get_piece_player_id());
    emit signal_node_31_set_player(this->game_field->node_list[31]->occupied_piece->get_piece_player_id());
    emit signal_node_32_set_player(this->game_field->node_list[32]->occupied_piece->get_piece_player_id());
    emit signal_node_33_set_player(this->game_field->node_list[33]->occupied_piece->get_piece_player_id());
    emit signal_node_34_set_player(this->game_field->node_list[34]->occupied_piece->get_piece_player_id());
    emit signal_node_35_set_player(this->game_field->node_list[35]->occupied_piece->get_piece_player_id());
    emit signal_node_36_set_player(this->game_field->node_list[36]->occupied_piece->get_piece_player_id());
    emit signal_node_37_set_player(this->game_field->node_list[37]->occupied_piece->get_piece_player_id());
    emit signal_node_38_set_player(this->game_field->node_list[38]->occupied_piece->get_piece_player_id());
    emit signal_node_39_set_player(this->game_field->node_list[39]->occupied_piece->get_piece_player_id());

}

void Game::set_board_state(int dice,int active_player,int state)
{
    if(state == 0 )// DICE
    {
        emit set_dice_player(true,active_player);
    }
    // GREEN LIMBO
    if(state == 2 && active_player == 0 && dice == 6)
    {
        emit signal_GBase_1_set_state(true);
    }
    else
        emit signal_GBase_1_set_state(false);
    // BLUE BASE
    if(state == 2 && active_player == 1 && dice == 6) // check the player's number
    {
        emit signal_BBase_1_set_state(true);
    }
    else
        emit signal_BBase_1_set_state(false);
    // RED BASE
    if(state == 2 && active_player == 2 && dice == 6)
    {
        emit signal_RBase_1_set_state(true);
    }
    else
        emit signal_RBase_1_set_state(false);
    // YELLOW BASE
    if(state == 2 && active_player == 3 && dice == 6)
    {
        emit signal_YBase_1_set_state(true);
    }
    else
        emit signal_YBase_1_set_state(false);

    //BOARD
    if((state > 0 || state == 3) && (active_player == this->game_field->node_list[0]->occupied_piece->get_piece_player_id()))// button_node_0
    {
        emit signal_node_0_set_state(true);
    }
    else
        emit signal_node_0_set_state(false);

    if((state > 0 && state < 3 )&& (active_player == this->game_field->node_list[1]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_1_set_state(true);
    }
    else
        emit signal_node_1_set_state(false);

    if((state > 0 && state < 3 )&& (active_player == this->game_field->node_list[2]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_2_set_state(true);
    }
    else
        emit signal_node_2_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[3]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_3_set_state(true);
    }
    else
        emit signal_node_3_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[4]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_4_set_state(true);
    }
    else
        emit signal_node_4_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[5]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_5_set_state(true);
    }
    else
        emit signal_node_5_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[6]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_6_set_state(true);
    }
    else
        emit signal_node_6_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[7]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_7_set_state(true);
    }
    else
        emit signal_node_7_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[8]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_8_set_state(true);
    }
    else
        emit signal_node_8_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[9]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_9_set_state(true);
    }
    else
        emit signal_node_9_set_state(false);

    if((state > 0 || state == 3 )&& (active_player == this->game_field->node_list[10]->occupied_piece->get_piece_player_id()))// button_node_10
    {
        emit signal_node_10_set_state(true);
    }
    else
        emit signal_node_10_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[11]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_11_set_state(true);
    }
    else
        emit signal_node_11_set_state(false);

    if((state > 0 && state < 3 )&&( active_player == this->game_field->node_list[12]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_12_set_state(true);
    }
    else
        emit signal_node_12_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[13]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_13_set_state(true);
    }
    else
        emit signal_node_13_set_state(false);

    if((state > 0 && state < 3 )&& (active_player == this->game_field->node_list[14]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_14_set_state(true);
    }
    else
        emit signal_node_14_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[15]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_15_set_state(true);
    }
    else
        emit signal_node_15_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[16]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_16_set_state(true);
    }
    else
        emit signal_node_16_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[17]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_17_set_state(true);
    }
    else
        emit signal_node_17_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[18]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_18_set_state(true);
    }
    else
        emit signal_node_18_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[19]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_19_set_state(true);
    }
    else
        emit signal_node_19_set_state(false);

    if((state > 0 || state < 3) && (active_player == this->game_field->node_list[20]->occupied_piece->get_piece_player_id()))// button_node_20
    {
        emit signal_node_20_set_state(true);
    }
    else
        emit signal_node_20_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[21]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_21_set_state(true);
    }
    else
        emit signal_node_21_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[22]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_22_set_state(true);
    }
    else
        emit signal_node_22_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[23]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_23_set_state(true);
    }
    else
        emit signal_node_23_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[24]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_24_set_state(true);
    }
    else
        emit signal_node_24_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[25]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_25_set_state(true);
    }
    else
        emit signal_node_25_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[26]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_26_set_state(true);
    }
    else
        emit signal_node_26_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[27]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_27_set_state(true);
    }
    else
        emit signal_node_27_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[28]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_28_set_state(true);
    }
    else
        emit signal_node_28_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[29]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_29_set_state(true);
    }
    else
        emit signal_node_29_set_state(false);

    if((state > 0 || state < 3) && (active_player == this->game_field->node_list[30]->occupied_piece->get_piece_player_id()))//node 30
    {
        emit signal_node_30_set_state(true);
    }
    else
        emit signal_node_30_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[31]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_31_set_state(true);
    }
    else
        emit signal_node_31_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[32]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_32_set_state(true);
    }
    else
        emit signal_node_32_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[33]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_33_set_state(true);
    }
    else
        emit signal_node_33_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[34]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_34_set_state(true);
    }
    else
        emit signal_node_34_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[35]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_35_set_state(true);
    }
    else
        emit signal_node_35_set_state(false);

    if((state > 0 && state < 3) &&( active_player == this->game_field->node_list[36]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_36_set_state(true);
    }
    else
        emit signal_node_36_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[37]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_37_set_state(true);
    }
    else
        emit signal_node_37_set_state(false);

    if((state > 0 && state < 3) && (active_player == this->game_field->node_list[38]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_38_set_state(true);
    }
    else
        emit signal_node_38_set_state(false);

    if((state > 0 && state < 3 )&& (active_player == this->game_field->node_list[39]->occupied_piece->get_piece_player_id()))
    {
        emit signal_node_39_set_state(true);
    }
    else
        emit signal_node_39_set_state(false);

}

//------------------------------------------------------------------------

//SLOTS
//------------------------------------------------------------------------
void Game::dice_slot()
{
    int x = rand()%6+1;
    emit show_dice(x);
}

int Game::classicboard_input(int node_id)
{
    if(node_id != -1)
        return node_id;

    return -1;
}
int Game::limbo_input(int limbo_id)
{
    if(limbo_id != -1)
        return limbo_id;
    return -1;
}

//------------------------------------------------------------------------
