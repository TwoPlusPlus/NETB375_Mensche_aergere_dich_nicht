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

//int Game::dice(){return rand()%6+1;}

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

void Game::dice_slot()
{
    int x = rand()%6+1;
    emit show_dice(x);
}

