#ifndef __PIECE_PLAYER_CLASS_H_INCLUDED__
#define __PIECE_PLAYER_H_INCLUDED__

#include <iostream>
#include <string>

using namespace std;

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

class Player // holds player properties
{
private:
    struct Home_node{
        Piece* home_occupied_piece;

        Home_node(){
            home_occupied_piece = NULL;
        }
    };

    string name;
    int ID; // 1-4, decides turns and other events
    int start_move; // starting position on field, node ID
    int finish_move;// finish position on field, node ID
    bool is_bot;
    int active_player_pieces;

public:
    Piece* piece_list[4];
    Home_node* home_node_list[4];
    bool home_score[4];

    Player(string input_name, int input_ID, bool bot);
    ~Player();

    string get_name();
    int get_player_id();
    int get_player_start();
    int get_player_finish();
    bool is_player_bot();

    bool is_player_active();

    int get_piece_current_node_id(int piece_id);// calculates pieces current node id by combining number of moves made and starting node ID
                                // modulus division by 39 (number of nodes) gives us the correct ID of the node

    void update_score();
    bool is_player_win();

    void add_to_name(int x);
};

#endif
