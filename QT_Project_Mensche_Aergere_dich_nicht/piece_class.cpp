#include "piece_class.h"

Piece::Piece(int input_piece_id, int input_piece_player_id)
{
	piece_id = input_piece_id;
	piece_player_id = input_piece_player_id;
	moves = -1;
	home_moves = 0;
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
	if(home_moves > 0) return true;
	else return false;
}

