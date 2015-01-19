#include "game_class.h"

Game::Game(int input_player_num, int input_ai_num)
{
    player_num = input_player_num;
    ai_num = input_ai_num;

    done = false;
    roll_six = false;
    turn = 1;

    string temp_name;

    game_field = new Field();

    if (player_num == 2)
    {
        if (ai_num == 0)
        {
            cout << "Enter name for Player 1: ";
            cin >> temp_name;
            player_list[0] = new Player(temp_name, 1, false, game_field);

            cout << "Enter name for Player 2: ";
            cin >> temp_name;
            player_list[1] = new Player(temp_name, 3, false, game_field);
        } else
            if (ai_num == 1){
            cout << "Enter name for Player 1: ";
            cin >> temp_name;
            player_list[0] = new Player(temp_name, 1, false, game_field);

            player_list[1] = new Player("Bot_1", 3, true, game_field);
        } else {
            player_list[0] = new Player("Bot_1", 1, true, game_field);
            player_list[1] = new Player("Bot_2", 3, true, game_field);
        }
    } else {
        for (int i = 0; i < player_num - ai_num; i++)
        {
            cout << "Enter name for Player " << i+1 <<": ";
            cin >> temp_name;
            player_list[i] = new Player(temp_name, i+1, false, game_field);
        }
        for (int i = player_num - ai_num; i < 4; i++)
        {
            player_list[i] = new Player("Bot_", i+1, false, game_field);
            player_list[i]->add_to_name(i+1);
        }
    }


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
