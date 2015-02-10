#ifndef __PIECE_PLAYER_CLASS_H_INCLUDED__
#define __PIECE_PLAYER_H_INCLUDED__

#include "field_piece_class.h"
#include <string>
#include <QList>
#include <QJsonArray>

using namespace std;

class Player // holds player properties
{
protected:

    QString name;
    int ID; // 0-3, decides turns and other events
    int start_move; // starting position on field, node ID
    int finish_move;// finish position on field, node ID
    int active_player_pieces;
    bool is_bot;


public:
    Field* board;
    Player* player_list[4];

    Piece* piece_list[4];
    //json
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    //==============
    bool home_score[4];

    Player(QString input_name, int input_ID, bool bot, Field* game_field);
    Player(Player &a);
    ~Player();

    QString get_name();
    int get_player_id();
    int get_player_start();
    int get_player_finish();

    bool is_player_active();
    bool is_player_bot();

    int get_piece_current_node_id(int piece_id);// calculates pieces current node id by combining number of moves made and starting node ID
                                // modulus division by 39 (number of nodes) gives us the correct ID of the node

    void update_score();
    bool is_player_win();
    //new//==========================================
    void move_piece (int piece_id, int roll);
    void activate_piece(int piece_id);
    void deactivate_piece(int piece_id);
    void move_piece_home(int piece_id, int roll);
    void move_home_piece(int piece_id, int roll);
//ai
    bool ai_clear_start_pos(int i, int dice);
    bool ai_score_point(int i,int dice);
    bool ai_remove_enemy_token(int i, int dice);
    void ai_dice_6();
    int ai_move_token(int dice);

    void ai_exec(int dice);

};
/*
class Ai: public Player
{
public:
    Ai(string input_name,int input_ID,Field* game_field) : Player(input_name,input_ID,game_field)
    {}

    void ai_exec(int dice);



};
*/
#endif
