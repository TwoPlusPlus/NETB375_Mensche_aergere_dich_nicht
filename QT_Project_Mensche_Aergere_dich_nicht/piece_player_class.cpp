#include "piece_player_class.h"

//===========================PIECE CLASS======================================//

Piece::Piece(int input_piece_id, int input_piece_player_id)
{
	piece_id = input_piece_id;
	piece_player_id = input_piece_player_id;
	moves = -1;
    home_moves = -1;
}

int Piece::get_piece_id()
{
	return piece_id;
}

int Piece::get_piece_player_id()
{
	return piece_player_id;
}

int Piece::get_piece_moves()
{
	return moves;
}

bool Piece::is_piece_home()
{
    if (home_moves > 0) return true;
    return false;
}
//===============================================================END==============//


//==============================PLAYER CLASS======================================//

Player::Player(string input_name, int input_ID, bool bot)
{
    ID = input_ID;
    name = input_name;
    is_bot = bot;
    active = false;
    active_player_pieces = 0;
    switch(ID)
    {
        case 1:
            start_move = 0;
            finish_move = 39;
            break;
        case 2:
            start_move = 10;
            finish_move = 9;
            break;
        case 3:
            start_move = 20;
            finish_move = 19;
            break;
        case 4:
            start_move = 30;
            finish_move = 29;
            break;
        default:
            break;
    }
    for (int i = 0; i < 4; i++)
    {
        piece_list[i] = new Piece(i+1,ID);
    }
    for (int i = 0; i < 4; i++)
    {
        home_node_list[i] = new Home_node();
    }
    for (int i = 0; i < 4; i++)
    {
        home_score[i] = false;
    }
}
Player::~Player()
{
     for (int i = 0; i < 4; i++)
     {
         delete piece_list[i];
     }
     for (int i = 0; i < 4; i++)
     {
         delete home_node_list[i];
     }
}

string Player::get_name()
{
    return name;
}
int Player::get_player_id()
{
    return ID;
}
int Player::get_player_start()
{
    return start_move;
}
int Player::get_player_finish()
{
    return finish_move;
}
bool Player::is_player_bot()
{
    return is_bot;
}

bool Player::is_player_active()
{
    if (active_player_pieces > 0)
        return true;
    return false;
}

int Player::get_piece_current_node_id(int piece_id)
{
    return ((piece_list[piece_id]->get_piece_moves() + start_move) % 39) - 1; // calculates pieces current node id by combining number of moves made and starting node ID
}															// modulus division by 39 (number of nodes) gives us the correct ID of the node

void Player::update_score()
{
    for (int i = 0; i < 4; i++)
    {
        if (home_node_list[i]->home_occupied_piece != NULL)
            home_score[i] = true;
    }
}
bool Player::is_player_win()
{
    int x = 0;
    for (int i = 0; i < 4; i++)
    {
       if (home_score[i] == true)
           x++;
    }
    if (x == 4)
        return true;
    return false;
}

void Player::add_to_name(int x)
{
     name += to_string(x);
}
//==================================================================END=====//
