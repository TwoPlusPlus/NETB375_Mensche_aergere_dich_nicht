#include "game_class.h"

Game::Game(bool G, QString G_name, bool R, QString R_name, bool B, QString B_name, bool Y, QString Y_name)
{
    game_thread = new GameThread(this, this);

    done = false;
    roll_six = false;
    turn = 1;

    game_field = new Field();

    player_num = 4;

    player_list[0] = new Player(G_name.toStdString(), 0, G, game_field);
//cout<<G_name;
    player_list[1] = new Player(R_name.toStdString(), 1, R, game_field);
//cout<<R_name;
    player_list[2] = new Player(B_name.toStdString(), 2, B, game_field);
//cout<<B_name;
    player_list[3] = new Player(Y_name.toStdString(), 3, Y, game_field);
//cout<<Y_name;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            player_list[i]->player_list[j] = player_list[j];
        }
    }

    game_thread->start();
    //classicboarddialog = new ClassicBoardDialog(0);
/*

    //board connections
    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_0_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_0_set_player, classicboarddialog, &ClassicBoardDialog::node_0_set_player);
    QObject::connect(this, &Game::signal_node_0_set_state, classicboarddialog, &ClassicBoardDialog::node_0_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_1_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_1_set_player, classicboarddialog, &ClassicBoardDialog::node_1_set_player);
    QObject::connect(this, &Game::signal_node_1_set_state, classicboarddialog, &ClassicBoardDialog::node_1_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_2_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_2_set_player, classicboarddialog, &ClassicBoardDialog::node_2_set_player);
    QObject::connect(this, &Game::signal_node_2_set_state, classicboarddialog, &ClassicBoardDialog::node_2_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_3_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_3_set_player, classicboarddialog, &ClassicBoardDialog::node_3_set_player);
    QObject::connect(this, &Game::signal_node_3_set_state, classicboarddialog, &ClassicBoardDialog::node_3_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_4_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_4_set_player, classicboarddialog, &ClassicBoardDialog::node_4_set_player);
    QObject::connect(this, &Game::signal_node_4_set_state, classicboarddialog, &ClassicBoardDialog::node_4_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_5_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_5_set_player, classicboarddialog, &ClassicBoardDialog::node_5_set_player);
    QObject::connect(this, &Game::signal_node_5_set_state, classicboarddialog, &ClassicBoardDialog::node_5_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_6_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_6_set_player, classicboarddialog, &ClassicBoardDialog::node_6_set_player);
    QObject::connect(this, &Game::signal_node_6_set_state, classicboarddialog, &ClassicBoardDialog::node_6_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_7_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_7_set_player, classicboarddialog, &ClassicBoardDialog::node_7_set_player);
    QObject::connect(this, &Game::signal_node_7_set_state, classicboarddialog, &ClassicBoardDialog::node_7_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_8_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_8_set_player, classicboarddialog, &ClassicBoardDialog::node_8_set_player);
    QObject::connect(this, &Game::signal_node_8_set_state, classicboarddialog, &ClassicBoardDialog::node_8_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_9_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_9_set_player, classicboarddialog, &ClassicBoardDialog::node_9_set_player);
    QObject::connect(this, &Game::signal_node_9_set_state, classicboarddialog, &ClassicBoardDialog::node_9_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_10_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_10_set_player, classicboarddialog, &ClassicBoardDialog::node_10_set_player);
    QObject::connect(this, &Game::signal_node_10_set_state, classicboarddialog, &ClassicBoardDialog::node_10_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_11_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_11_set_player, classicboarddialog, &ClassicBoardDialog::node_11_set_player);
    QObject::connect(this, &Game::signal_node_11_set_state, classicboarddialog, &ClassicBoardDialog::node_11_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_12_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_12_set_player, classicboarddialog, &ClassicBoardDialog::node_12_set_player);
    QObject::connect(this, &Game::signal_node_12_set_state, classicboarddialog, &ClassicBoardDialog::node_12_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_13_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_13_set_player, classicboarddialog, &ClassicBoardDialog::node_13_set_player);
    QObject::connect(this, &Game::signal_node_13_set_state, classicboarddialog, &ClassicBoardDialog::node_13_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_14_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_14_set_player, classicboarddialog, &ClassicBoardDialog::node_14_set_player);
    QObject::connect(this, &Game::signal_node_14_set_state, classicboarddialog, &ClassicBoardDialog::node_14_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_15_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_15_set_player, classicboarddialog, &ClassicBoardDialog::node_15_set_player);
    QObject::connect(this, &Game::signal_node_15_set_state, classicboarddialog, &ClassicBoardDialog::node_15_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_16_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_16_set_player, classicboarddialog, &ClassicBoardDialog::node_16_set_player);
    QObject::connect(this, &Game::signal_node_16_set_state, classicboarddialog, &ClassicBoardDialog::node_16_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_17_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_17_set_player, classicboarddialog, &ClassicBoardDialog::node_17_set_player);
    QObject::connect(this, &Game::signal_node_17_set_state, classicboarddialog, &ClassicBoardDialog::node_17_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_18_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_18_set_player, classicboarddialog, &ClassicBoardDialog::node_18_set_player);
    QObject::connect(this, &Game::signal_node_18_set_state, classicboarddialog, &ClassicBoardDialog::node_18_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_19_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_19_set_player, classicboarddialog, &ClassicBoardDialog::node_19_set_player);
    QObject::connect(this, &Game::signal_node_19_set_state, classicboarddialog, &ClassicBoardDialog::node_19_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_20_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_20_set_player, classicboarddialog, &ClassicBoardDialog::node_20_set_player);
    QObject::connect(this, &Game::signal_node_20_set_state, classicboarddialog, &ClassicBoardDialog::node_20_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_21_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_21_set_player, classicboarddialog, &ClassicBoardDialog::node_21_set_player);
    QObject::connect(this, &Game::signal_node_21_set_state, classicboarddialog, &ClassicBoardDialog::node_21_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_22_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_22_set_player, classicboarddialog, &ClassicBoardDialog::node_22_set_player);
    QObject::connect(this, &Game::signal_node_22_set_state, classicboarddialog, &ClassicBoardDialog::node_22_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_23_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_23_set_player, classicboarddialog, &ClassicBoardDialog::node_23_set_player);
    QObject::connect(this, &Game::signal_node_23_set_state, classicboarddialog, &ClassicBoardDialog::node_23_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_24_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_24_set_player, classicboarddialog, &ClassicBoardDialog::node_24_set_player);
    QObject::connect(this, &Game::signal_node_24_set_state, classicboarddialog, &ClassicBoardDialog::node_24_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_25_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_25_set_player, classicboarddialog, &ClassicBoardDialog::node_25_set_player);
    QObject::connect(this, &Game::signal_node_25_set_state, classicboarddialog, &ClassicBoardDialog::node_25_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_26_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_26_set_player, classicboarddialog, &ClassicBoardDialog::node_26_set_player);
    QObject::connect(this, &Game::signal_node_26_set_state, classicboarddialog, &ClassicBoardDialog::node_26_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_27_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_27_set_player, classicboarddialog, &ClassicBoardDialog::node_27_set_player);
    QObject::connect(this, &Game::signal_node_27_set_state, classicboarddialog, &ClassicBoardDialog::node_27_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_28_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_28_set_player, classicboarddialog, &ClassicBoardDialog::node_28_set_player);
    QObject::connect(this, &Game::signal_node_28_set_state, classicboarddialog, &ClassicBoardDialog::node_28_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_29_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_29_set_player, classicboarddialog, &ClassicBoardDialog::node_29_set_player);
    QObject::connect(this, &Game::signal_node_29_set_state, classicboarddialog, &ClassicBoardDialog::node_29_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_30_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_30_set_player, classicboarddialog, &ClassicBoardDialog::node_30_set_player);
    QObject::connect(this, &Game::signal_node_30_set_state, classicboarddialog, &ClassicBoardDialog::node_30_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_31_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_31_set_player, classicboarddialog, &ClassicBoardDialog::node_31_set_player);
    QObject::connect(this, &Game::signal_node_31_set_state, classicboarddialog, &ClassicBoardDialog::node_31_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_32_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_32_set_player, classicboarddialog, &ClassicBoardDialog::node_32_set_player);
    QObject::connect(this, &Game::signal_node_32_set_state, classicboarddialog, &ClassicBoardDialog::node_32_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_33_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_33_set_player, classicboarddialog, &ClassicBoardDialog::node_33_set_player);
    QObject::connect(this, &Game::signal_node_33_set_state, classicboarddialog, &ClassicBoardDialog::node_33_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_34_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_34_set_player, classicboarddialog, &ClassicBoardDialog::node_34_set_player);
    QObject::connect(this, &Game::signal_node_34_set_state, classicboarddialog, &ClassicBoardDialog::node_34_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_35_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_35_set_player, classicboarddialog, &ClassicBoardDialog::node_35_set_player);
    QObject::connect(this, &Game::signal_node_35_set_state, classicboarddialog, &ClassicBoardDialog::node_35_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_36_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_36_set_player, classicboarddialog, &ClassicBoardDialog::node_36_set_player);
    QObject::connect(this, &Game::signal_node_36_set_state, classicboarddialog, &ClassicBoardDialog::node_36_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_37_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_37_set_player, classicboarddialog, &ClassicBoardDialog::node_37_set_player);
    QObject::connect(this, &Game::signal_node_37_set_state, classicboarddialog, &ClassicBoardDialog::node_37_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_38_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_38_set_player, classicboarddialog, &ClassicBoardDialog::node_38_set_player);
    QObject::connect(this, &Game::signal_node_38_set_state, classicboarddialog, &ClassicBoardDialog::node_38_set_state);

    QObject::connect(classicboarddialog, &ClassicBoardDialog::node_39_clicked, this,& Game::classicboard_input);
    QObject::connect(this, &Game::signal_node_39_set_player, classicboarddialog, &ClassicBoardDialog::node_39_set_player);
    QObject::connect(this, &Game::signal_node_39_set_state, classicboarddialog, &ClassicBoardDialog::node_39_set_state);

 */
}

Game::~Game()
{
    for (int i = 0; i < player_num; i++)
    {
        delete player_list[i];
    }
    delete game_field;
   // delete classicboarddialog;
    game_thread->quit();
    game_thread->wait();
}

int Game::dice(){return rand()%6+1;}

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
            player_turn(i);
            if (roll_six == true)
                player_turn(i);
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

    if (player_list[plr_ID]->is_player_active() == true)
    {

    } else {


    }
}

void Game::ai_turn(int plr_ID)
{
   // int roll = 0;

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
void Game::set_board_state(int active_player,int state)
{
    if(state == 0 )// DICE
        {
            emit set_dice_player(true,active_player);
        }
        // GREEN LIMBO
        if(state == 2 && active_player == 0 )
        {
            emit signal_GBase_1_set_state(true);
        }
        else
            emit signal_GBase_1_set_state(false);

        if(state == 2 && active_player == 0 )
        {
            emit signal_GBase_2_set_state(true);
        }
        else
            emit signal_GBase_2_set_state(false);

        if(state == 2 && active_player == 0 )
        {
            emit signal_GBase_3_set_state(true);
        }
        else
            emit signal_GBase_3_set_state(false);

        if(state == 2 && active_player == 0 )
        {
            emit signal_GBase_4_set_state(true);
        }
        else
            emit signal_GBase_4_set_state(false);

        // BLUE BASE
        if(state == 2 && active_player == 1) // check the player's number
        {
            emit signal_BBase_1_set_state(true);
        }
        else
            emit signal_BBase_1_set_state(false);

        if(state == 2 && active_player == 1)
        {
            emit signal_BBase_2_set_state(true);
        }
        else
            emit signal_BBase_2_set_state(false);

        if(state == 2 && active_player == 1)
        {
            emit signal_BBase_3_set_state(true);
        }
        else
            emit signal_BBase_3_set_state(false);

        if(state == 2 && active_player == 1)
        {
            emit signal_BBase_4_set_state(true);
        }
        else
            emit signal_BBase_4_set_state(false);


        // RED BASE
        if(state == 2 && active_player == 2)
        {
            emit signal_RBase_1_set_state(true);
        }
        else
            emit signal_RBase_1_set_state(false);
        if(state == 2 && active_player == 2)
        {
            emit signal_RBase_2_set_state(true);
        }
        else
            emit signal_RBase_2_set_state(false);
        if(state == 2 && active_player == 2)
        {
            emit signal_RBase_3_set_state(true);
        }
        else
            emit signal_RBase_3_set_state(false);
        if(state == 2 && active_player == 2)
        {
            emit signal_RBase_4_set_state(true);
        }
        else
            emit signal_RBase_4_set_state(false);
        // YELLOW BASE
        if(state == 2 && active_player == 3 )
        {
            emit signal_YBase_1_set_state(true);
        }
        else
            emit signal_YBase_1_set_state(false);
        if(state == 2 && active_player == 3 )
        {
            emit signal_YBase_2_set_state(true);
        }
        else
            emit signal_YBase_2_set_state(false);
        if(state == 2 && active_player == 3 )
        {
            emit signal_YBase_3_set_state(true);
        }
        else
            emit signal_YBase_3_set_state(false);
        if(state == 2 && active_player == 3 )
        {
            emit signal_YBase_4_set_state(true);
        }
        else
            emit signal_YBase_4_set_state(false);
/*
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
*/
}

//------------------------------------------------------------------------

//SLOTS
//------------------------------------------------------------------------
void Game::dice_slot()
{
    GLOBAL_DICE = rand()%6+1;
    emit show_dice(GLOBAL_DICE);
}
void Game::classicboard_input(int node_id)
{
    GLOBAL_TOKEN_ID = node_id;
}
void Game::limbo_input(int limbo_id)
{
    GLOBAL_LIMBO_ID = limbo_id;
}
void Game::home_input(int home_id)
{
    GLONAL_HOME_ID = home_id;
}


void GameThread::run() {
   // qDebug() << "from game-ptr thread" << currentThreadId();
    while(!gamePtr->done){
        for(int i = 0; i < 4; i++){
            mutex.lock();
            gamePtr->set_board_state(i,0);
            keypressed.wait(&mutex);
            mutex.unlock();
        }
    }
}
