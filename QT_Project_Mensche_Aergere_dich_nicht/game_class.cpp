#include "game_class.h"

Game::Game(bool G, QString G_name, bool R, QString R_name, bool B, QString B_name, bool Y, QString Y_name)
{
    game_thread = new GameThread(this, this);

    done = false;
    roll_six = false;
    turn = 1;

    GLOBAL_DICE = 0;
    GLOBAL_LIMBO_ID = -1;
    GLOBAL_TOKEN_ID = -1;
    GLOBAL_HOME_ID = -1;

    game_field = new Field();

    player_num = 0;
    ai_num = 0;

    player_list[0] = new Player(G_name.toStdString(), 0, G, game_field);
    player_list[1] = new Player(B_name.toStdString(), 1, B, game_field);
    player_list[2] = new Player(R_name.toStdString(), 2, R, game_field);
    player_list[3] = new Player(Y_name.toStdString(), 3, Y, game_field);

    if(G)
        player_num++;
    else ai_num++;
    if(B)
        player_num++;
    else ai_num++;
    if(R)
        player_num++;
    else ai_num++;
    if(Y)
        player_num++;
    else ai_num++;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            player_list[i]->player_list[j] = player_list[j];
        }
    }

    game_thread->start();

}

Game::~Game()
{
    for (int i = 0; i < 4; i++)
    {
        if(player_list[i])
            delete player_list[i];
        player_list[i] = 0;
    }
    delete game_field;
   // delete classicboarddialog;
    game_thread->quit();
    game_thread->wait();
}

int Game::dice(){return rand()%6+1;}

//SIGNAL EMIT'S -> BOARD
//------------------------------------------------------------------------
void Game::update_classicboard()
{
    //LIMBO
    //emit signal_GBase_1_set_state(this->player_list[0]->piece_list[0]->get_piece_moves() != -1);
    emit signal_GBase_1_set_token(this->player_list[0]->piece_list[0]->get_piece_moves() == -1);
    emit signal_GBase_2_set_token(this->player_list[0]->piece_list[1]->get_piece_moves() == -1);
    emit signal_GBase_3_set_token(this->player_list[0]->piece_list[2]->get_piece_moves() == -1);
    emit signal_GBase_4_set_token(this->player_list[0]->piece_list[3]->get_piece_moves() == -1);

    emit signal_BBase_1_set_token(this->player_list[1]->piece_list[0]->get_piece_moves() == -1);
    emit signal_BBase_2_set_token(this->player_list[1]->piece_list[1]->get_piece_moves() == -1);
    emit signal_BBase_3_set_token(this->player_list[1]->piece_list[2]->get_piece_moves() == -1);
    emit signal_BBase_4_set_token(this->player_list[1]->piece_list[3]->get_piece_moves() == -1);

    emit signal_RBase_1_set_token(this->player_list[2]->piece_list[0]->get_piece_moves() == -1);
    emit signal_RBase_2_set_token(this->player_list[2]->piece_list[1]->get_piece_moves() == -1);
    emit signal_RBase_3_set_token(this->player_list[2]->piece_list[2]->get_piece_moves() == -1);
    emit signal_RBase_4_set_token(this->player_list[2]->piece_list[3]->get_piece_moves() == -1);

    emit signal_YBase_1_set_token(this->player_list[3]->piece_list[0]->get_piece_moves() == -1);
    emit signal_YBase_2_set_token(this->player_list[3]->piece_list[1]->get_piece_moves() == -1);
    emit signal_YBase_3_set_token(this->player_list[3]->piece_list[2]->get_piece_moves() == -1);
    emit signal_YBase_4_set_token(this->player_list[3]->piece_list[3]->get_piece_moves() == -1);

//BOARD
    if(this->game_field->node_list[0]->state != 0)
        emit signal_node_0_set_player(this->game_field->node_list[0]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_0_set_player(-1);
    if(this->game_field->node_list[1]->state != 0)
        emit signal_node_1_set_player(this->game_field->node_list[1]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_1_set_player(-1);
    if(this->game_field->node_list[2]->state != 0)
        emit signal_node_2_set_player(this->game_field->node_list[2]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_2_set_player(-1);
    if(this->game_field->node_list[3]->state != 0)
        emit signal_node_3_set_player(this->game_field->node_list[3]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_3_set_player(-1);
    if(this->game_field->node_list[4]->state != 0)
        emit signal_node_4_set_player(this->game_field->node_list[4]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_4_set_player(-1);
    if(this->game_field->node_list[5]->state != 0)
        emit signal_node_5_set_player(this->game_field->node_list[5]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_5_set_player(-1);
    if(this->game_field->node_list[6]->state != 0)
        emit signal_node_6_set_player(this->game_field->node_list[6]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_6_set_player(-1);
    if(this->game_field->node_list[7]->state != 0)
        emit signal_node_7_set_player(this->game_field->node_list[7]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_7_set_player(-1);
    if(this->game_field->node_list[8]->state != 0)
        emit signal_node_8_set_player(this->game_field->node_list[8]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_8_set_player(-1);
    if(this->game_field->node_list[9]->state != 0)
        emit signal_node_9_set_player(this->game_field->node_list[9]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_9_set_player(-1);

    if(this->game_field->node_list[10]->state != 0)
        emit signal_node_10_set_player(this->game_field->node_list[10]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_10_set_player(-1);
    if(this->game_field->node_list[11]->state != 0)
        emit signal_node_11_set_player(this->game_field->node_list[11]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_11_set_player(-1);
    if(this->game_field->node_list[12]->state != 0)
        emit signal_node_12_set_player(this->game_field->node_list[12]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_12_set_player(-1);
    if(this->game_field->node_list[13]->state != 0)
        emit signal_node_13_set_player(this->game_field->node_list[13]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_13_set_player(-1);
    if(this->game_field->node_list[14]->state != 0)
        emit signal_node_14_set_player(this->game_field->node_list[14]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_14_set_player(-1);
    if(this->game_field->node_list[15]->state != 0)
        emit signal_node_15_set_player(this->game_field->node_list[15]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_15_set_player(-1);
    if(this->game_field->node_list[16]->state != 0)
        emit signal_node_16_set_player(this->game_field->node_list[16]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_16_set_player(-1);
    if(this->game_field->node_list[17]->state != 0)
        emit signal_node_17_set_player(this->game_field->node_list[17]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_17_set_player(-1);
    if(this->game_field->node_list[18]->state != 0)
        emit signal_node_18_set_player(this->game_field->node_list[18]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_18_set_player(-1);
    if(this->game_field->node_list[19]->state != 0)
        emit signal_node_19_set_player(this->game_field->node_list[19]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_19_set_player(-1);

    if(this->game_field->node_list[20]->state != 0)
        emit signal_node_20_set_player(this->game_field->node_list[20]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_20_set_player(-1);
    if(this->game_field->node_list[21]->state != 0)
        emit signal_node_21_set_player(this->game_field->node_list[21]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_21_set_player(-1);
    if(this->game_field->node_list[22]->state != 0)
        emit signal_node_22_set_player(this->game_field->node_list[22]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_22_set_player(-1);
    if(this->game_field->node_list[23]->state != 0)
        emit signal_node_23_set_player(this->game_field->node_list[23]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_23_set_player(-1);
    if(this->game_field->node_list[24]->state != 0)
        emit signal_node_24_set_player(this->game_field->node_list[24]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_24_set_player(-1);
    if(this->game_field->node_list[25]->state != 0)
        emit signal_node_25_set_player(this->game_field->node_list[25]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_25_set_player(-1);
    if(this->game_field->node_list[26]->state != 0)
        emit signal_node_26_set_player(this->game_field->node_list[26]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_26_set_player(-1);
    if(this->game_field->node_list[27]->state != 0)
        emit signal_node_27_set_player(this->game_field->node_list[27]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_27_set_player(-1);
    if(this->game_field->node_list[28]->state != 0)
        emit signal_node_28_set_player(this->game_field->node_list[28]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_28_set_player(-1);
    if(this->game_field->node_list[29]->state != 0)
        emit signal_node_29_set_player(this->game_field->node_list[29]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_29_set_player(-1);

    if(this->game_field->node_list[30]->state != 0)
        emit signal_node_30_set_player(this->game_field->node_list[30]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_30_set_player(-1);
    if(this->game_field->node_list[31]->state != 0)
        emit signal_node_31_set_player(this->game_field->node_list[31]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_31_set_player(-1);
    if(this->game_field->node_list[32]->state != 0)
        emit signal_node_32_set_player(this->game_field->node_list[32]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_32_set_player(-1);
    if(this->game_field->node_list[33]->state != 0)
        emit signal_node_33_set_player(this->game_field->node_list[33]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_33_set_player(-1);
    if(this->game_field->node_list[34]->state != 0)
        emit signal_node_34_set_player(this->game_field->node_list[34]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_34_set_player(-1);
    if(this->game_field->node_list[35]->state != 0)
        emit signal_node_35_set_player(this->game_field->node_list[35]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_35_set_player(-1);
    if(this->game_field->node_list[36]->state != 0)
        emit signal_node_36_set_player(this->game_field->node_list[36]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_36_set_player(-1);
    if(this->game_field->node_list[37]->state != 0)
        emit signal_node_37_set_player(this->game_field->node_list[37]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_37_set_player(-1);
    if(this->game_field->node_list[38]->state != 0)
        emit signal_node_38_set_player(this->game_field->node_list[38]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_38_set_player(-1);
    if(this->game_field->node_list[39]->state != 0)
        emit signal_node_39_set_player(this->game_field->node_list[39]->occupied_piece->get_piece_player_id());
    else
        emit signal_node_39_set_player(-1);
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
            if(this->player_list[0]->piece_list[0]->get_piece_moves() == -1)
            {
                if(game_field->node_list[0]->state != 0)
                {
                    if(game_field->node_list[0]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_GBase_1_set_state(true);
                    }
                    else
                    {
                        emit signal_GBase_1_set_state(false);
                    }
                }

                else
                {
                    emit signal_GBase_1_set_state(true);
                }
            }
        }
        else
            emit signal_GBase_1_set_state(false);

        if(state == 2 && active_player == 0 )
        {
            if(this->player_list[0]->piece_list[1]->get_piece_moves() == -1)
            {
                if(game_field->node_list[0]->state != 0)
                {
                    if(game_field->node_list[0]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_GBase_2_set_state(true);
                    }
                    else
                    {
                        emit signal_GBase_2_set_state(false);
                    }
                }

                else
                {
                    emit signal_GBase_2_set_state(true);
                }
            }
        }
        else
            emit signal_GBase_2_set_state(false);

        if(state == 2 && active_player == 0 )
        {
            if(this->player_list[0]->piece_list[2]->get_piece_moves() == -1)
            {
                if(game_field->node_list[0]->state != 0)
                {
                    if(game_field->node_list[0]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_GBase_3_set_state(true);
                    }
                    else
                    {
                        emit signal_GBase_3_set_state(false);
                    }
                }
                else
                {
                    emit signal_GBase_3_set_state(true);
                }
            }

        }
        else
            emit signal_GBase_3_set_state(false);

        if(state == 2 && active_player == 0 )
        {
            if(this->player_list[0]->piece_list[3]->get_piece_moves() == -1)
            {
                if(game_field->node_list[0]->state != 0)
                {
                    if(game_field->node_list[0]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_GBase_4_set_state(true);
                    }
                    else
                    {
                        emit signal_GBase_4_set_state(false);
                    }
                }
                else
                {
                    emit signal_GBase_4_set_state(true);
                }
            }

        }
        else
            emit signal_GBase_4_set_state(false);

        // BLUE BASE
        if(state == 2 && active_player == 1) // check the player's number
        {
            if(this->player_list[1]->piece_list[0]->get_piece_moves() == -1)
            {
                if(game_field->node_list[10]->state != 0)
                {
                    if(game_field->node_list[10]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_BBase_1_set_state(true);
                    }
                    else
                    {
                        emit signal_BBase_1_set_state(false);
                    }
                }
                else
                {
                    emit signal_BBase_1_set_state(true);
                }
            }

        }
        else
            emit signal_BBase_1_set_state(false);

        if(state == 2 && active_player == 1)
        {
            if(this->player_list[1]->piece_list[1]->get_piece_moves() == -1)
            {
                if(game_field->node_list[10]->state != 0)
                {
                    if(game_field->node_list[10]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_BBase_2_set_state(true);
                    }
                    else
                    {
                        emit signal_BBase_2_set_state(false);
                    }
                }
                else
                {
                    emit signal_BBase_2_set_state(true);
                }
            }
        }
        else
            emit signal_BBase_2_set_state(false);

        if(state == 2 && active_player == 1)
        {
            if(this->player_list[1]->piece_list[2]->get_piece_moves() == -1)
            {
                if(game_field->node_list[10]->state != 0)
                {
                    if(game_field->node_list[10]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_BBase_3_set_state(true);
                    }
                    else
                    {
                        emit signal_BBase_3_set_state(false);
                    }
                }
                else
                {
                    emit signal_BBase_3_set_state(true);
                }
            }
        }
        else
            emit signal_BBase_3_set_state(false);

        if(state == 2 && active_player == 1)
        {
            if(this->player_list[1]->piece_list[3]->get_piece_moves() == -1)
            {
                if(game_field->node_list[10]->state != 0)
                {
                    if(game_field->node_list[10]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_BBase_4_set_state(true);
                    }
                    else
                    {
                        emit signal_BBase_4_set_state(false);
                    }
                }
                else
                {
                    emit signal_BBase_4_set_state(true);
                }
            }
        }
        else
            emit signal_BBase_4_set_state(false);


        // RED BASE
        if(state == 2 && active_player == 2)
        {
            if(this->player_list[2]->piece_list[0]->get_piece_moves() == -1)
            {
                if(game_field->node_list[20]->state != 0)
                {
                    if(game_field->node_list[20]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_RBase_1_set_state(true);
                    }
                    else
                    {
                        emit signal_RBase_1_set_state(false);
                    }
                }
                else
                {
                    emit signal_RBase_1_set_state(true);
                }
            }
        }
        else
            emit signal_RBase_1_set_state(false);
        if(state == 2 && active_player == 2)
        {
            if(this->player_list[2]->piece_list[1]->get_piece_moves() == -1)
            {
                if(game_field->node_list[20]->state != 0)
                {
                    if(game_field->node_list[20]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_RBase_2_set_state(true);
                    }
                    else
                    {
                        emit signal_RBase_2_set_state(false);
                    }
                }
                else
                {
                    emit signal_RBase_2_set_state(true);
                }
            }
        }
        else
            emit signal_RBase_2_set_state(false);
        if(state == 2 && active_player == 2)
        {
            if(this->player_list[2]->piece_list[2]->get_piece_moves() == -1)
            {
                if(game_field->node_list[20]->state != 0)
                {
                    if(game_field->node_list[20]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_RBase_3_set_state(true);
                    }
                    else
                    {
                        emit signal_RBase_3_set_state(false);
                    }
                }
                else
                {
                    emit signal_RBase_3_set_state(true);
                }
            }
        }
        else
            emit signal_RBase_3_set_state(false);
        if(state == 2 && active_player == 2)
        {
            if(this->player_list[2]->piece_list[3]->get_piece_moves() == -1)
            {
                if(game_field->node_list[20]->state != 0)
                {
                    if(game_field->node_list[20]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_RBase_4_set_state(true);
                    }
                    else
                    {
                        emit signal_RBase_4_set_state(false);
                    }
                }
                else
                {
                    emit signal_RBase_4_set_state(true);
                }
            }
        }
        else
            emit signal_RBase_4_set_state(false);
        // YELLOW BASE
        if(state == 2 && active_player == 3 )
        {
            if(this->player_list[3]->piece_list[0]->get_piece_moves() == -1)
            {
                if(game_field->node_list[30]->state != 0)
                {
                    if(game_field->node_list[30]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_YBase_1_set_state(true);
                    }
                    else
                    {
                        emit signal_YBase_1_set_state(false);
                    }
                }
                else
                {
                    emit signal_YBase_1_set_state(true);
                }
            }
        }
        else
            emit signal_YBase_1_set_state(false);
        if(state == 2 && active_player == 3 )
        {
            if(this->player_list[3]->piece_list[1]->get_piece_moves() == -1)
            {
                if(game_field->node_list[30]->state != 0)
                {
                    if(game_field->node_list[30]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_YBase_2_set_state(true);
                    }
                    else
                    {
                        emit signal_YBase_2_set_state(false);
                    }
                }
                else
                {

                    emit signal_YBase_2_set_state(true);
                }
            }
        }
        else
            emit signal_YBase_2_set_state(false);
        if(state == 2 && active_player == 3 )
        {
            if(this->player_list[3]->piece_list[2]->get_piece_moves() == -1)
            {
                if(game_field->node_list[30]->state != 0)
                {
                    if(game_field->node_list[30]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_YBase_3_set_state(true);
                    }
                    else
                    {
                        emit signal_YBase_3_set_state(false);
                    }
                }
                else
                {
                    emit signal_YBase_3_set_state(true);
                }
            }
        }
        else
            emit signal_YBase_3_set_state(false);
        if(state == 2 && active_player == 3 )
        {
            if(this->player_list[3]->piece_list[3]->get_piece_moves() == -1)
            {
                if(game_field->node_list[30]->state != 0)
                {
                    if(game_field->node_list[30]->occupied_piece->get_piece_player_id() != active_player)
                    {
                        emit signal_YBase_4_set_state(true);
                    }
                    else
                    {
                        emit signal_YBase_4_set_state(false);
                    }
                }
                else
                {
                    emit signal_YBase_4_set_state(true);
                }
            }
        }
        else
            emit signal_YBase_4_set_state(false);

        //BOARD
        if((state > 0 || state == 3) && (this->game_field->node_list[0]->state != 0))// button_node_0
        {
            if(active_player == this->game_field->node_list[0]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+0]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+0]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_0_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_0_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_0_set_state(true);
                }
            }
        }
        else
            emit signal_node_0_set_state(false);

        if((state > 0 && state < 3 )&& (this->game_field->node_list[1]->state != 0))
        {
            if(active_player == this->game_field->node_list[1]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+1]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+1]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_1_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_1_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_1_set_state(true);
                }
            }
        }
        else
            emit signal_node_1_set_state(false);

        if((state > 0 && state < 3 )&& (this->game_field->node_list[2]->state != 0))
        {
            if(active_player == this->game_field->node_list[2]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+2]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+2]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_2_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_2_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_2_set_state(true);
                }
            }
        }
        else
            emit signal_node_2_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[3]->state != 0))
        {
            if(active_player == this->game_field->node_list[3]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+3]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+3]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_3_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_3_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_3_set_state(true);
                }
            }
        }
        else
            emit signal_node_3_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[4]->state != 0))
        {
            if(active_player == this->game_field->node_list[4]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+4]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+4]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_4_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_4_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_4_set_state(true);
                }
            }
        }
        else
            emit signal_node_4_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[5]->state != 0))
        {
            if(active_player == this->game_field->node_list[5]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+5]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+5]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_5_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_5_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_5_set_state(true);
                }
            }
        }
        else
            emit signal_node_5_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[6]->state != 0))
        {
            if(active_player == this->game_field->node_list[6]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+6]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+6]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_6_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_6_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_6_set_state(true);
                }
            }
        }
        else
            emit signal_node_6_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[7]->state != 0))
        {
            if(active_player == this->game_field->node_list[7]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+7]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+7]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_7_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_7_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_7_set_state(true);
                }
            }
        }
        else
            emit signal_node_7_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[8]->state != 0))
        {
            if(active_player == this->game_field->node_list[8]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+8]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+8]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_8_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_8_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_8_set_state(true);
                }
            }
        }
        else
            emit signal_node_8_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[9]->state != 0))
        {
            if(active_player == this->game_field->node_list[9]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+9]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+9]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_9_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_9_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_9_set_state(true);
                }
            }
        }
        else
            emit signal_node_9_set_state(false);

        if((state > 0 || state == 3 )&& (this->game_field->node_list[10]->state != 0))// button_node_10
        {
            if(active_player == this->game_field->node_list[10]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+10]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+10]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_10_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_10_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_10_set_state(true);
                }
            }
        }
        else
            emit signal_node_10_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[11]->state != 0))
        {
            if(active_player == this->game_field->node_list[11]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+11]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+11]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_11_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_11_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_11_set_state(true);
                }
            };
        }
        else
            emit signal_node_11_set_state(false);

        if((state > 0 && state < 3 )&&( this->game_field->node_list[12]->state != 0))
        {
            if(active_player == this->game_field->node_list[12]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+12]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+12]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_12_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_12_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_12_set_state(true);
                }
            }
        }
        else
            emit signal_node_12_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[13]->state != 0))
        {
            if(active_player == this->game_field->node_list[13]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+13]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+13]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_13_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_13_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_13_set_state(true);
                }
            }
        }
        else
            emit signal_node_13_set_state(false);

        if((state > 0 && state < 3 )&& (this->game_field->node_list[14]->state != 0))
        {
            if(active_player == this->game_field->node_list[14]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+14]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+14]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_14_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_14_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_14_set_state(true);
                }
            }
        }
        else
            emit signal_node_14_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[15]->state != 0))
        {
            if(active_player == this->game_field->node_list[15]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+15]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+15]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_15_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_15_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_15_set_state(true);
                }
            }
        }
        else
            emit signal_node_15_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[16]->state != 0))
        {
            if(active_player == this->game_field->node_list[16]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+16]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+16]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_16_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_16_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_16_set_state(true);
                }
            }
        }
        else
            emit signal_node_16_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[17]->state != 0))
        {
            if(active_player == this->game_field->node_list[17]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+17]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+17]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_17_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_17_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_17_set_state(true);
                }
            }
        }
        else
            emit signal_node_17_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[18]->state != 0))
        {
            if(active_player == this->game_field->node_list[18]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+18]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+18]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_18_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_18_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_18_set_state(true);
                }
            }
        }
        else
            emit signal_node_18_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[19]->state != 0))
        {
            if(active_player == this->game_field->node_list[19]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+19]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+19]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_19_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_19_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_19_set_state(true);
                }
            }
        }
        else
            emit signal_node_19_set_state(false);

        if((state > 0 || state == 3) && (this->game_field->node_list[20]->state != 0))// button_node_20
        {
            if(active_player == this->game_field->node_list[20]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+20]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+20]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_20_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_20_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_20_set_state(true);
                }
            }
        }
        else
            emit signal_node_20_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[21]->state != 0))
        {
            if(active_player == this->game_field->node_list[21]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+21]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+21]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_21_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_21_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_21_set_state(true);
                }
            }
        }
        else
            emit signal_node_21_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[22]->state != 0))
        {
            if(active_player == this->game_field->node_list[22]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+22]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+22]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_22_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_22_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_22_set_state(true);
                }
            }
        }
        else
            emit signal_node_22_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[23]->state != 0))
        {
            if(active_player == this->game_field->node_list[23]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+23]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+23]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_23_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_23_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_23_set_state(true);
                }
            }
        }
        else
            emit signal_node_23_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[24]->state != 0))
        {
            if(active_player == this->game_field->node_list[24]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+24]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+24]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_24_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_24_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_24_set_state(true);
                }
            }
        }
        else
            emit signal_node_24_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[25]->state != 0))
        {
            if(active_player == this->game_field->node_list[25]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+25]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+25]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_25_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_25_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_25_set_state(true);
                }
            }
        }
        else
            emit signal_node_25_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[26]->state != 0))
        {
            if(active_player == this->game_field->node_list[26]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+26]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+26]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_26_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_26_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_26_set_state(true);
                }
            }
        }
        else
            emit signal_node_26_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[27]->state != 0))
        {
            if(active_player == this->game_field->node_list[27]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+27]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+27]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_27_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_27_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_27_set_state(true);
                }
            }
        }
        else
            emit signal_node_27_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[28]->state != 0))
        {
            if(active_player == this->game_field->node_list[28]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+28]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+28]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_28_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_28_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_28_set_state(true);
                }
            }
        }
        else
            emit signal_node_28_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[29]->state != 0))
        {
            if(active_player == this->game_field->node_list[29]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+29]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+29]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_29_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_29_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_29_set_state(true);
                }
            }
        }
        else
            emit signal_node_29_set_state(false);

        if((state > 0 || state == 3) && (this->game_field->node_list[30]->state != 0))//node 30
        {
            if(active_player == this->game_field->node_list[30]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+30]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+30]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_30_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_30_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_30_set_state(true);
                }
            }
        }
        else
            emit signal_node_30_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[31]->state != 0))
        {
            if(active_player == this->game_field->node_list[31]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+31]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+31]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_31_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_31_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_31_set_state(true);
                }
            }
        }
        else
            emit signal_node_31_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[32]->state != 0))
        {
            if(active_player == this->game_field->node_list[32]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+32]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+32]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_32_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_32_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_32_set_state(true);
                }
            }
        }
        else
            emit signal_node_32_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[33]->state != 0))
        {
            if(active_player == this->game_field->node_list[33]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+33]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+33]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_33_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_33_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_33_set_state(true);
                }
            }
        }
        else
            emit signal_node_33_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[34]->state != 0))
        {
            if(active_player == 0 && this->GLOBAL_DICE == 6)// 9 02 2015 5:24 making shit happen
            {
                if(this->game_field->home_node_list[0][0]->state == 0)
                {
                    emit signal_node_34_set_state(true);
                }
            }


            if(active_player == this->game_field->node_list[34]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+34]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+34]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_34_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_34_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_34_set_state(true);
                }
            }
        }
        else
            emit signal_node_34_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[35]->state != 0))
        {
            if(active_player == 0 && this->GLOBAL_DICE == 5)// 9 02 2015 5:24 making shit happen
            {
                if(this->game_field->home_node_list[0][0]->state == 0)
                {
                    emit signal_node_34_set_state(true);
                }
            }
            if(active_player == this->game_field->node_list[35]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+35]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+35]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_35_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_35_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_35_set_state(true);
                }
            }
        }
        else
            emit signal_node_35_set_state(false);

        if((state > 0 && state < 3) &&( this->game_field->node_list[36]->state != 0))
        {
            if(active_player == 0 && this->GLOBAL_DICE == 4)// 9 02 2015 5:24 making shit happen
            {
                if(this->game_field->home_node_list[0][0]->state == 0)
                {
                    emit signal_node_36_set_state(true);
                }
            }
            if(active_player == this->game_field->node_list[36]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+36]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+36]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_36_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_36_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_36_set_state(true);
                }
            }
        }
        else
            emit signal_node_36_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[37]->state != 0))
        {
            if(active_player == 0 && this->GLOBAL_DICE == 3)// 9 02 2015 5:24 making shit happen
            {
                if(this->game_field->home_node_list[0][0]->state == 0)
                {
                    emit signal_node_34_set_state(true);
                }
            }
            if(active_player == this->game_field->node_list[37]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+37]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+37]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_37_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_37_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_37_set_state(true);
                }
            }
        }
        else
            emit signal_node_37_set_state(false);

        if((state > 0 && state < 3) && (this->game_field->node_list[38]->state != 0))
        {
            if(active_player == this->game_field->node_list[38]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+38]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+38]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_38_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_38_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_38_set_state(true);
                }
            }
        }
        else
            emit signal_node_38_set_state(false);

        if((state > 0 && state < 3 )&& (this->game_field->node_list[39]->state != 0))
        {
            if(active_player == this->game_field->node_list[39]->occupied_piece->get_piece_player_id())
            {
                if(this->game_field->node_list[this->GLOBAL_DICE+39]->state != 0)
                { // if next node empty
                    if(active_player != this->game_field->node_list[this->GLOBAL_DICE+39]->occupied_piece->get_piece_player_id())
                    {
                       emit signal_node_39_set_state(true); //if next node diff player piece
                    }
                    else // if next node same player piece
                        emit signal_node_39_set_state(false);
                } else
                { // if next node empty
                    emit signal_node_39_set_state(true);
                }
            }
        }
        else
            emit signal_node_39_set_state(false);

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
    GLOBAL_HOME_ID = home_id;
}


void GameThread::run() {
    qDebug() << "from game-ptr thread" << currentThreadId();
    msleep(999);
    while(!gamePtr->done){
        if(gamePtr->turn == 17)
            msleep(1); // debug
        for(int i = 0; i < 4; i++){
            if(gamePtr->player_list[i]->is_player_bot())
            {
               mutex.lock();
               gamePtr->set_board_state(i,0);
               gamePtr->dice_slot();
               gamePtr->player_list[i]->ai_exec(gamePtr->GLOBAL_DICE);
               msleep(200);
               gamePtr->GLOBAL_HOME_ID = -1;
               gamePtr->GLOBAL_LIMBO_ID = -1;
               gamePtr->GLOBAL_TOKEN_ID = -1;
               gamePtr->update_classicboard();
               mutex.unlock();
               continue;
            }
            mutex.lock();

            gamePtr->set_board_state(i,0);

            keypressed.wait(&mutex);
            mutex.unlock();

            if (gamePtr->player_list[i]->is_player_active()){// if player active
                if (gamePtr->GLOBAL_DICE != 6){ //if dice not 6
                    mutex.lock();

                    gamePtr->set_board_state(i,1);

                    keypressed.wait(&mutex);
                    mutex.unlock();
                    mutex.lock();

                    if (gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->state != 0){
                        int x = gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->occupied_piece->get_piece_player_id();
                        int y = gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->occupied_piece->get_piece_id();
                        gamePtr->player_list[x]->deactivate_piece(y);
                    }
                    gamePtr->player_list[i]->move_piece(gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID]->occupied_piece->get_piece_id(), gamePtr->GLOBAL_DICE);
                    gamePtr->update_classicboard();

                    mutex.unlock();
                }
                else{ // if dice 6
                    mutex.lock();

                    gamePtr->set_board_state(i,2);

                    keypressed.wait(&mutex);
                    mutex.unlock();
                    mutex.lock();

                    if(gamePtr->GLOBAL_TOKEN_ID != -1) // move piece
                    {
                        if (gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->state != 0){
                            int x = gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->occupied_piece->get_piece_player_id();
                            int y = gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->occupied_piece->get_piece_id();
                            gamePtr->player_list[x]->deactivate_piece(y);
                        }
                        gamePtr->player_list[i]->move_piece(gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID]->occupied_piece->get_piece_id(), gamePtr->GLOBAL_DICE);
                        gamePtr->update_classicboard();

                        mutex.unlock();
                    }
                    else{  // activate piece
                        if(gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->state != 0)
                        {
                            int x = gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->occupied_piece->get_piece_player_id();
                            int y = gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->occupied_piece->get_piece_id();
                            gamePtr->player_list[x]->deactivate_piece(y);
                        }
                        gamePtr->player_list[i]->activate_piece(gamePtr->GLOBAL_LIMBO_ID);
                        gamePtr->update_classicboard();
                        gamePtr->set_board_state(i,0);

                        mutex.unlock();
                    }
                }
            }
            else{ // player inactive
                if(gamePtr->GLOBAL_DICE == 6){// dice 6 - move/limbo
                    mutex.lock();

                    gamePtr->set_board_state(i,2);

                    keypressed.wait(&mutex);
                    mutex.unlock();
                    mutex.lock();
                    if(gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->state != 0)
                    {
                        int x = gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->occupied_piece->get_piece_player_id();
                        int y = gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->occupied_piece->get_piece_id();
                        gamePtr->player_list[x]->deactivate_piece(y);
                    }
                    gamePtr->player_list[i]->activate_piece(gamePtr->GLOBAL_LIMBO_ID);
                    msleep(100);
                    gamePtr->update_classicboard();
                    this->msleep(100);
                    gamePtr->update_classicboard();
                    this->msleep(100);
                    gamePtr->set_board_state(i,0);

                    keypressed.wait(&mutex);
                    mutex.unlock();
                    mutex.lock();

                    gamePtr->set_board_state(i,3);

                    keypressed.wait(&mutex);
                    mutex.unlock();
                    mutex.lock();

                    if (gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->state != 0){
                        int x = gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->occupied_piece->get_piece_player_id();
                        int y = gamePtr->game_field->node_list[gamePtr->GLOBAL_TOKEN_ID+gamePtr->GLOBAL_DICE]->occupied_piece->get_piece_id();
                        gamePtr->player_list[x]->deactivate_piece(y);
                    }
                    int x = gamePtr->game_field->node_list[gamePtr->player_list[i]->get_player_start()]->occupied_piece->get_piece_id();
                    // start node piece id
                    gamePtr->player_list[i]->move_piece(x, gamePtr->GLOBAL_DICE);
                    gamePtr->update_classicboard();

                    mutex.unlock();
                }
                else{

                }
            }

            mutex.lock();

            gamePtr->GLOBAL_HOME_ID = -1;
            gamePtr->GLOBAL_LIMBO_ID = -1;
            gamePtr->GLOBAL_TOKEN_ID = -1;
          //  gamePtr->update_classicboard();

            mutex.unlock();

        }
        qDebug() << gamePtr->turn << " ends";
        gamePtr->turn++;

    }

}

void GameThread::wakeThread(){
    keypressed.wakeAll();
}
