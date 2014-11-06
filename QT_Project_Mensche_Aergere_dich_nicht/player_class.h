#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <iostream>
#include <string>

//-----------------//

#include "piece_class.h"

using namespace std;

class Player  // holds player properties
{
private:

    string name;
    int ID; // 1-4, decides turns and other events
    int start_move; // starting position on field, node ID
    int finish_move;// finish position on field, node ID
    bool is_bot;

public:
    Piece* piece_list[4];

    inline Player(string input_name, int input_ID, bool bot);
    inline ~Player();

    inline string get_name();
    inline int get_id();
    inline int get_start();
    inline int get_finish();
    inline bool is_player_bot();
    inline void add_to_name(char x);
};

#endif // PLAYER_CLASS_H
