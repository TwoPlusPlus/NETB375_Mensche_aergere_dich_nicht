#ifndef FIELD_CLASS_H
#define FIELD_CLASS_H

#include <iostream>

#include "player_class.cpp"

class Field // represents the game field with a simple data structure resembeling
			// an array of the 56 positions of the game field, with an extension of 6 home position nodes
{			// to every finish position node
private:
	struct Node // the node structure for the list representing the 39 game positions + the 16 home positions
	{
		Piece* occupied_piece;
		Node* next_node;
		int state; // 0 position is empty, 1-2 number of pieces stacked
        int node_id;

        Node(int id){
        node_id = id;
        state = 0;
        occupied_piece = NULL;
		next_node = NULL;
        }

        Node* move_next()
        {
            return next_node;
        }
	};

public:
    Node* node_list[56];
	Field();
	~Field();
	
	int get_node_state(int node_id);
	
	Piece* get_occupied_piece_id(int node_id); // returns occupied piece ID
    int move_next(int node_id, int move); //returns a pointer to next node
	
	void occupy_node(int node_id, Piece* occupy_piece);  // occupies the node by give piece
	void de_occupy_node(int node_id);   // de-occupies a node
};

#endif
