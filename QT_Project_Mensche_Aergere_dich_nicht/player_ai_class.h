#ifndef __PIECE_PLAYER_CLASS_H_INCLUDED__
#define __PIECE_PLAYER_H_INCLUDED__

#include "field_piece_class.h"
#include <string>

using namespace std;

class Player // holds player properties
{
protected:

    string name;
    int ID; // 0-3, decides turns and other events
    int start_move; // starting position on field, node ID
    int finish_move;// finish position on field, node ID
    bool is_bot;
    int active_player_pieces;
    Field* board;


public:
    Player* player_list[4];
    Piece* piece_list[4];
    bool home_score[4];

    Player(string input_name, int input_ID, bool bot, Field* game_field, Player** input_player_list);
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
    //new//==========================================
    void move_piece (int piece_id, int roll);
    void activate_piece(int piece_id);
    void deactivate_piece(int piece_id);
    void move_piece_home(int piece_id, int roll);
    void move_home_piece(int piece_id, int roll);

};

class Ai: public Player
{
public:
    Ai(string input_name,int input_ID,Field* game_field, Player** input_player_list) : Player(input_name,input_ID,true,game_field,input_player_list)
    {}

    void ai_exec(int dice);



};

#endif
