#include "field_class.h"

Field::Field()
{
    node_list[0] = new Node(0); // create first node
    for(int i = 0; i < 55; i++)
    {
        node_list[i+1] = new Node(i+1);  //create next node
		node_list[i]->next_node = node_list[i+1]; //link 1st to next node
	}
	node_list[55]->next_node = node_list[0]; // links last node to first node
}
Field::~Field()
{
    for(int i = 0; i < 56; i++)
    {
		delete node_list[i];  // deletes all node objects
	}
}

int Field::get_node_state(int node_id)
{
	return node_list[node_id]->state; // returns node state
}

Piece* Field::get_occupied_piece_id(int node_id)
{
	return node_list[node_id]->occupied_piece; // returns occupied piece ID
}
int Field::move_next(int node_id, int move)
{
    Node* node_ptr = NULL;
    for(int i = 0; i < move; i++)
    {
       node_ptr = node_list[node_id]->next_node;
    }
    return node_ptr->node_id;
}

void Field::occupy_node(int node_id, Piece* occupy_piece)
{
	node_list[node_id]->occupied_piece = occupy_piece;  // occupies the node by give piece
}
void Field::de_occupy_node(int node_id)
{
	node_list[node_id]->occupied_piece = NULL;   // de-occupies a node
}


