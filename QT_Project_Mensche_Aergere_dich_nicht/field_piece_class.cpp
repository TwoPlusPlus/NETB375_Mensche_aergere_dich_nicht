#include "field_piece_class.h"

//===========================PIECE CLASS======================================//

Piece::Piece(int input_piece_id, int input_piece_player_id)
{
    piece_id = input_piece_id;
    piece_player_id = input_piece_player_id;
    moves = -1;
    home_moves = -1;
}

Piece::Piece(Piece &a)
{
    this->piece_id = a.piece_id;
    this->piece_player_id = a.piece_player_id;
    this->moves = a.moves;
    this->home_moves = a.home_moves;
}

int Piece::get_piece_id()
{
    return piece_id;
}

int Piece::get_piece_player_id()
{
    return piece_player_id;
}

int Piece::get_piece_moves()
{
    return moves;
}
int Piece::get_piece_home_moves()
{
    return home_moves;
}

bool Piece::is_piece_home()
{
    if (home_moves > 0) return true;
    return false;
}

void Piece::update_moves(int roll, bool home)
{
    if (!home)
    {
        if (roll > 0)
            this->moves += roll;
        else if (roll == 0)
            this->moves = 0;
        else if (roll == -1)
            this->moves = -1;
        else if (roll == 39)
            this->moves = 39;

    }
    else
    {
        home_moves += roll;
    }
}

//JSON

void Piece::read(const QJsonObject &json)
{
    piece_id = json["piece-id"].toInt();
    piece_player_id = json["pice-player-id"].toInt();
    moves = json["moves"].toInt();
    home_moves = json["home-moves"].toInt();
}

void Piece::write(QJsonObject &json) const
{
    json["piece-id"] = piece_id;
    json["pice-player-id"] = piece_player_id;
    json["moves"] = moves;
    json["home-moves"] = home_moves;
}

//===============================================================END==============//


//=================================FIELD CLASS====================================//
//--------------------------Constructor------------------------------//
Field::Field()
{
    for (int i = 0; i < 40; i++)
    {
        node_list[i] = new Node(i);  //create node
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            home_node_list[i][j] = new Node(j);
        }
    }
}
Field::~Field()
{
    for (int i = 0; i < 40; i++)
    {
        delete node_list[i];  // deletes all node objects
        node_list[i] = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            delete home_node_list[i][j];
            home_node_list[i][j] = 0;
        }
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
    node_list[node_id]->state = 1;
}
void Field::de_occupy_node(int node_id)
{
    node_list[node_id]->occupied_piece = NULL;   // de-occupies a node
    node_list[node_id]->state = 0;
}

void Field::occupy_home_node(int node_id, int player_id, Piece* occupy_piece)
{
    this->home_node_list[player_id][node_id]->occupied_piece = occupy_piece;
    this->home_node_list[player_id][node_id]->state = 1;
}

void Field::de_occupy_home_node(int node_id, int player_id)
{
    this->home_node_list[player_id][node_id]->occupied_piece = 0;
    this->home_node_list[player_id][node_id]->state = 0;
}
