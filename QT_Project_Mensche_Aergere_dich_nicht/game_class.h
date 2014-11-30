#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include "field_class.h"

class Game{
public:
	int player_num;
	int ai_num;

	Player* player_list[4];
	Field* game_field;
	
	bool done;
	bool roll_six;
	
	int turn;

	Game(int input_player_num, int input_ai_num);
    ~Game();

    int dice();

    void play();
	void game_turn();
	void player_turn(int plr_ID);
};

#endif
