#ifndef PIECE_CLASS_H
#define PIECE_CLASS_H

class Piece // 4 pieces per player,
{
private:
	int piece_id; // 1-4 identifies the pieces
	int piece_player_id; // 1-4 depending which player the piece belongs to
	int moves; // 0-43, number of moves taken so far, when = 39, the piece is on finish position
	int home_moves; // 1-4
public:
	Piece(int input_piece_id, int input_piece_player_id);

	int get_piece_id();
	int get_piece_player_id();
	int get_piece_moves();
	bool is_piece_home();
};

#endif