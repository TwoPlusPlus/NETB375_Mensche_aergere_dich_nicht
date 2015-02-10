#ifndef __GAME_CLASS_H_INCLUDED__
#define __GAME_CLASS_H_INCLUDED__

#include "player_ai_class.h"
//#include "classicboarddialog.h"
#include <QObject>

#include <QDebug>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>



//#include <QSound>

#include <cstdlib>

class GameThread;

class Game : public QObject
{
    Q_OBJECT

private:
public:
    bool done;
    bool roll_six;
    int winner;

    int game_turn;
    int player_turn;
    int roll;

    bool load;

    int GLOBAL_DICE;
    int GLOBAL_TOKEN_ID;
    int GLOBAL_LIMBO_ID;
    int GLOBAL_HOME_ID;
    int GLOBAL_TRANSITION;
    bool GLOBAL_VALID_MOVE;

    //ClassicBoardDialog *classicboarddialog;

    int player_num;
    int ai_num;

    Player* player_list[4];
    Field* game_field;

    GameThread* game_thread;

    Game();
    Game(bool G,QString G_name,bool R,QString R_name,bool B,QString B_name,bool Y,QString Y_name);
    ~Game();

    int dice();

    //from game_class to board_dialog
    //syncs boards with node_List[]
    void update_classicboard();

    //takes care which player turn is and which button he/she can push
    void set_board_state(int active_player, int state);


    void play();

    void finish();
    void set_winner(int king);


    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;



public slots:

    bool loadGame();
    bool saveGame() const;

    void dice_slot();

    void classicboard_input(int node_id, bool end_node);
    void limbo_input(int limbo_id);
    void home_input(int i, int j);


signals:
    void show_dice(int num);
    void set_dice_player(bool state,int player);
   //LIMBO
    void signal_GBase_1_set_state(bool check);
    void signal_GBase_1_set_token(bool isPushed);
    void signal_GBase_2_set_state(bool check);
    void signal_GBase_2_set_token(bool isPushed);
    void signal_GBase_3_set_state(bool check);
    void signal_GBase_3_set_token(bool isPushed);
    void signal_GBase_4_set_state(bool check);
    void signal_GBase_4_set_token(bool isPushed);

    void signal_BBase_1_set_state(bool check);
    void signal_BBase_1_set_token(bool isPushed);
    void signal_BBase_2_set_state(bool check);
    void signal_BBase_2_set_token(bool isPushed);
    void signal_BBase_3_set_state(bool check);
    void signal_BBase_3_set_token(bool isPushed);
    void signal_BBase_4_set_state(bool check);
    void signal_BBase_4_set_token(bool isPushed);

    void signal_RBase_1_set_state(bool check);
    void signal_RBase_1_set_token(bool isPushed);
    void signal_RBase_2_set_state(bool check);
    void signal_RBase_2_set_token(bool isPushed);
    void signal_RBase_3_set_state(bool check);
    void signal_RBase_3_set_token(bool isPushed);
    void signal_RBase_4_set_state(bool check);
    void signal_RBase_4_set_token(bool isPushed);

    void signal_YBase_1_set_state(bool check);
    void signal_YBase_1_set_token(bool isPushed);
    void signal_YBase_2_set_state(bool check);
    void signal_YBase_2_set_token(bool isPushed);
    void signal_YBase_3_set_state(bool check);
    void signal_YBase_3_set_token(bool isPushed);
    void signal_YBase_4_set_state(bool check);
    void signal_YBase_4_set_token(bool isPushed);

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
//=====================
    void signal_home_set_state(int i, int j, bool can_move);
    void signal_home_update_state(int i, int j, bool taken);
//===============
};

class GameThread : public QThread
{
    Q_OBJECT
private:
public:
    QWaitCondition keypressed;
    QMutex mutex;
    Game* gamePtr;

    GameThread(QObject* parent = 0, Game* gamePtr = 0) : QThread(parent)
    {
        this->gamePtr = gamePtr;
    }

    void run() Q_DECL_OVERRIDE;
public slots:
    void wakeThread();

};

#endif
