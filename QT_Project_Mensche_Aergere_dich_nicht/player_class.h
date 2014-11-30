#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <iostream>
#include <string>

#include "piece_class.h"

using namespace std;

class Player // holds player properties
{
private:
	string name;
	int ID; // 1-4, decides turns and other events
	int start_move; // starting position on field, node ID
	int finish_move;// finish position on field, node ID
	bool is_bot;
	bool active;

public:
    Piece* piece_list[4];

	Player(string input_name, int input_ID, bool bot);
	~Player();

	string get_name();
	int get_player_id();
	int get_player_start();
	int get_player_finish();
	bool is_player_bot();

	void add_to_name(int x);
	
	int get_piece_current_node_id(int piece_id);// calculates pieces current node id by combining number of moves made and starting node ID
								// modulus division by 39 (number of nodes) gives us the correct ID of the node
	
	bool is_player_home();
};

#endif
