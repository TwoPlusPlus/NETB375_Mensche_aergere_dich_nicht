#ifndef __GAME_CLASS_H_INCLUDED__
#define __GAME_CLASS_H_INCLUDED__

#include "player_ai_class.h"
#include "classicboarddialog.h"
#include <QObject>
#include <QThread>

#include <cstdlib>

class Game : public QDialog
{
    Q_OBJECT
private:

    int ai_num;

    bool done;
    bool roll_six;

    int turn;
    int roll;

public:
    ClassicBoardDialog *classicboarddialog;

    int player_num;
    Player* player_list[4];
    Field* game_field;

    Game(bool G,string G_name,bool R,string R_name,bool B,string B_name,bool Y,string Y_name);
    ~Game();

    int dice();


    void game_turn();
    void player_turn(int plr_ID);
    void ai_turn(int plr_ID);

    //from game_class to board_dialog
    //syncs boards with node_List[]
    void update_classicboard();

    //takes care which player turn is and which button he/she can push
    void set_board_state(int active_player, int state);

public slots:
    void play();
    void dice_slot();

    int classicboard_input(int node_id);
    int limbo_input(int limbo_id);


signals:
    void show_dice(int num);
    void set_dice_player(bool state,int player);
   //LIMBO
    void signal_GBase_1_set_state(bool check);
    void signal_GBase_2_set_state(bool check);
    void signal_GBase_3_set_state(bool check);
    void signal_GBase_4_set_state(bool check);

    void signal_BBase_1_set_state(bool check);
    void signal_BBase_2_set_state(bool check);
    void signal_BBase_3_set_state(bool check);
    void signal_BBase_4_set_state(bool check);

    void signal_RBase_1_set_state(bool check);
    void signal_RBase_2_set_state(bool check);
    void signal_RBase_3_set_state(bool check);
    void signal_RBase_4_set_state(bool check);

    void signal_YBase_1_set_state(bool check);
    void signal_YBase_2_set_state(bool check);
    void signal_YBase_3_set_state(bool check);
    void signal_YBase_4_set_state(bool check);

//BOARD
    void signal_node_0_set_player(int player_id);
    void signal_node_0_set_state(bool check);

    void signal_node_1_set_player(int player_id);
    void signal_node_1_set_state(bool check);

    void signal_node_2_set_player(int player_id);
    void signal_node_2_set_state(bool check);

    void signal_node_3_set_player(int player_id);
    void signal_node_3_set_state(bool check);

    void signal_node_4_set_player(int player_id);
    void signal_node_4_set_state(bool check);

    void signal_node_5_set_player(int player_id);
    void signal_node_5_set_state(bool check);

    void signal_node_6_set_player(int player_id);
    void signal_node_6_set_state(bool check);

    void signal_node_7_set_player(int player_id);
    void signal_node_7_set_state(bool check);

    void signal_node_8_set_player(int player_id);
    void signal_node_8_set_state(bool check);

    void signal_node_9_set_player(int player_id);
    void signal_node_9_set_state(bool check);

//---

    void signal_node_10_set_player(int player_id);
    void signal_node_10_set_state(bool check);

    void signal_node_11_set_player(int player_id);
    void signal_node_11_set_state(bool check);

    void signal_node_12_set_player(int player_id);
    void signal_node_12_set_state(bool check);

    void signal_node_13_set_player(int player_id);
    void signal_node_13_set_state(bool check);

    void signal_node_14_set_player(int player_id);
    void signal_node_14_set_state(bool check);

    void signal_node_15_set_player(int player_id);
    void signal_node_15_set_state(bool check);

    void signal_node_16_set_player(int player_id);
    void signal_node_16_set_state(bool check);

    void signal_node_17_set_player(int player_id);
    void signal_node_17_set_state(bool check);

    void signal_node_18_set_player(int player_id);
    void signal_node_18_set_state(bool check);

    void signal_node_19_set_player(int player_id);
    void signal_node_19_set_state(bool check);

    //---

    void signal_node_20_set_player(int player_id);
    void signal_node_20_set_state(bool check);

    void signal_node_21_set_player(int player_id);
    void signal_node_21_set_state(bool check);

    void signal_node_22_set_player(int player_id);
    void signal_node_22_set_state(bool check);

    void signal_node_23_set_player(int player_id);
    void signal_node_23_set_state(bool check);

    void signal_node_24_set_player(int player_id);
    void signal_node_24_set_state(bool check);

    void signal_node_25_set_player(int player_id);
    void signal_node_25_set_state(bool check);

    void signal_node_26_set_player(int player_id);
    void signal_node_26_set_state(bool check);

    void signal_node_27_set_player(int player_id);
    void signal_node_27_set_state(bool check);

    void signal_node_28_set_player(int player_id);
    void signal_node_28_set_state(bool check);

    void signal_node_29_set_player(int player_id);
    void signal_node_29_set_state(bool check);

    //---

    void signal_node_30_set_player(int player_id);
    void signal_node_30_set_state(bool check);

    void signal_node_31_set_player(int player_id);
    void signal_node_31_set_state(bool check);

    void signal_node_32_set_player(int player_id);
    void signal_node_32_set_state(bool check);

    void signal_node_33_set_player(int player_id);
    void signal_node_33_set_state(bool check);

    void signal_node_34_set_player(int player_id);
    void signal_node_34_set_state(bool check);

    void signal_node_35_set_player(int player_id);
    void signal_node_35_set_state(bool check);

    void signal_node_36_set_player(int player_id);
    void signal_node_36_set_state(bool check);

    void signal_node_37_set_player(int player_id);
    void signal_node_37_set_state(bool check);

    void signal_node_38_set_player(int player_id);
    void signal_node_38_set_state(bool check);

    void signal_node_39_set_player(int player_id);
    void signal_node_39_set_state(bool check);
};

#endif
