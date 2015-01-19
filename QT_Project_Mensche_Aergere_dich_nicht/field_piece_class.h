#ifndef __FIELD_PIECE_CLASS_H_INCLUDED__
#define __FIELD_PIECE_CLASS_H_INCLUDED__

#include <iostream>

using namespace std;

class Piece // 4 pieces per player,
{
private:
    int piece_id; // 1-4 identifies the pieces
    int piece_player_id; // 1-4 depending which player the piece belongs to
    int moves; // 0-39, number of moves taken so far, when = 39, the piece is on finish position
    int home_moves; // 0-3
public:
    Piece(int input_piece_id, int input_piece_player_id);

    int get_piece_id();
    int get_piece_player_id();
    int get_piece_moves();
    int get_piece_home_moves();
    bool is_piece_home();

    void update_moves(int roll, bool home);
};

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
    Node* home_node_list[4][4];

//-------Constructor----Destructor---------//
    Field();
    ~Field();

//------Node get functions-------------//
    Piece* get_occupied_piece(int node_id); // returns occupied piece ID
    int get_node_state(int node_id);

//----Node utility functions---------//
    void occupy_node(int node_id, Piece* occupy_piece);  // occupies the node by give piece
    void de_occupy_node(int node_id);   // de-occupies a node

    void occupy_home_node(int node_id, int player_id, Piece* occupy_piece);
    void de_occupy_home_node(int node_id, int player_id);

};

#endif
