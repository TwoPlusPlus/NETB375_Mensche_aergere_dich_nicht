#include "piece_class.h"

Piece::Piece(int input_piece_id, int input_player_id)
{
    piece_id = input_piece_id;
    player_id = input_player_id;
    moves = 0;
}

int Piece::get_piece_id()
{
    return piece_id;
}
int Piece::get_player_id()
{
    return player_id;
}
int Piece::get_moves()
{
    return moves;
}
