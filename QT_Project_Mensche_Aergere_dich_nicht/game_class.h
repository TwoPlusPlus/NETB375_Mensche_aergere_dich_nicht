#ifndef __GAME_CLASS_H_INCLUDED__
#define __GAME_CLASS_H_INCLUDED__

#include "player_ai_class.h"

#include <cstdlib>

class Game{
private:

    int ai_num;

    bool done;
    bool roll_six;

    int turn;

public:
    int player_num;
    Player* player_list[4];
    Field* game_field;

    Game();
    ~Game();

    int dice();

    void play();
    void game_turn();
    void player_turn(int plr_ID);
    void ai_turn(int plr_ID);
};

#endif
