#ifndef __GAME_CLASS_H_INCLUDED__
#define __GAME_CLASS_H_INCLUDED__

#include "field_class.h"

#include <cstdlib>

class Game{
private:
	int player_num;
	int ai_num;

	bool done;
	bool roll_six;

	int turn;

public:
    Player* player_list[4];
    Field* game_field;

	Game(int input_player_num, int input_ai_num);
    ~Game();

    int dice();

    void play();
	void game_turn();
    void player_turn(int plr_ID);
};

#endif
