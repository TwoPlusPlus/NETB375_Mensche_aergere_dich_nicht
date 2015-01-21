#include "game_class.h"

Game::Game()
{
    done = false;
    roll_six = false;
    turn = 1;

    //string temp_name;

    game_field = new Field();

    player_list[0] = new Player("BOT 1", 0, true, game_field, player_list);

    player_list[1] = new Player("bot 2", 1, true, game_field, player_list);

    player_list[2] = new Player("terminator 3", 2, true, game_field, player_list);

    player_list[3] = new Player("BoT_4", 3, true, game_field, player_list);


}

Game::~Game()
{
    for (int i = 0; i < player_num; i++)
    {

        delete player_list[i];
    }
    delete game_field;
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

    roll = dice();

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
