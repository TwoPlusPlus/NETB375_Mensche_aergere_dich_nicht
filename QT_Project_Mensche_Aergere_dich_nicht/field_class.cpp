#include "field_class.h"

//--------------------------Constructor------------------------------//
Field::Field()
{
    for (int i = 0; i < 40; i++)
    {
        node_list[i] = new Node(i);  //create node
	}
}
Field::~Field()
{
    for(int i = 0; i < 40; i++)
    {
		delete node_list[i];  // deletes all node objects
	}
}

//-------------------------Node get functions--------------------------------//
int Field::get_node_state(int node_id)
{
	return node_list[node_id]->state; // returns node state
}

Piece* Field::get_occupied_piece(int node_id)
{
	return node_list[node_id]->occupied_piece; // returns occupied piece ID
}

//-------------------------Node utility functions-------------------------------//
void Field::occupy_node(int node_id, Piece* occupy_piece)
{
	node_list[node_id]->occupied_piece = occupy_piece;  // occupies the node by give piece
}
void Field::de_occupy_node(int node_id)
{
	node_list[node_id]->occupied_piece = NULL;   // de-occupies a node
}


