#ifndef __FIELD_CLASS_H_INCLUDED__
#define __FIELD_CLASS_H_INCLUDED__

#include "piece_player_class.h"

#include <iostream>

class Field{ // represents the game field with a simple data structure resembeling
			// an array of the 56 positions of the game field, with an extension of 6 home position nodes
            // to every finish position node
private:

    struct Node{ // the node structure for the list representing the 39 game positions + the 16 home positions
		Piece* occupied_piece;
		int state; // 0 position is empty, 1-2 number of pieces stacked
        int node_id;

        Node(int id)
        {
        occupied_piece = NULL;
        state = 0;
        node_id = id;
        }
	};

public:

    Node* node_list[40];

//-------Constructor----Destructor---------//
	Field();
    ~Field();

//------Node get functions-------------//
    Piece* get_occupied_piece(int node_id); // returns occupied piece ID
    int get_node_state(int node_id);

//----Node utility functions---------//
	void occupy_node(int node_id, Piece* occupy_piece);  // occupies the node by give piece
	void de_occupy_node(int node_id);   // de-occupies a node

};

#endif
