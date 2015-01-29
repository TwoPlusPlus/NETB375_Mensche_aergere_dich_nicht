#ifndef __GAME_CLASS_H_INCLUDED__
#define __GAME_CLASS_H_INCLUDED__

#include "player_ai_class.h"
#include "classicboarddialog.h"
#include <QObject>

#include <cstdlib>

class Game
{
private:

    int ai_num;

    bool done;
    bool roll_six;

    int turn;

public:
    int player_num;
    Player* player_list[4];
    Field* game_field;

    Game(bool G,string G_name,bool R,string R_name,bool B,string B_name,bool Y,string Y_name);
    ~Game();

    int dice();

    void play();
    void game_turn();
    void player_turn(int plr_ID);
    void ai_turn(int plr_ID);

public slots:
    void match_boardButtons_nodeList(int index);
};

#endif
