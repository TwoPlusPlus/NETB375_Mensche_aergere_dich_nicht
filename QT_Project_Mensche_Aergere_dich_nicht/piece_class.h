#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

#include <iostream>
#include <string>
#include <cstdlib>

class Piece
{
private:
    int piece_id; // 1-4 identifies the pieces
    int player_id; // 1-4 depending which player the piece belongs to
    int moves; // 0-39, number of moves taken so far, when = 55, the piece is on finish position

public:
    Piece(int input_piece_id, int input_player_id)
        :
        piece_id(input_piece_id),
        player_id(input_player_id),
        moves(0)
    {}

    int get_piece_id();
    int get_player_id();
    int get_moves();
};

#endif // PIECE_H
