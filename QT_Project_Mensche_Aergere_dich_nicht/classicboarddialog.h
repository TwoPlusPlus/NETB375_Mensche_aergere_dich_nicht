#ifndef CLASSICBOARDDIALOG_H
#define CLASSICBOARDDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QObject>
#include <QThread>

#include "game_class.h"

#include <iostream>
#include <cstdlib>
#include <string>

namespace Ui {
class ClassicBoardDialog;
}

class ClassicBoardDialog : public QDialog
{
    Q_OBJECT
public:
    //Game* game;
    Game* game;
    explicit ClassicBoardDialog(QWidget *parent = 0, bool G = false, QString G_name="player_1", bool R = false, QString R_name="player_2", bool B = false, QString B_name="player_3", bool Y = false, QString Y_name="player_4");
    ~ClassicBoardDialog();

signals:

    void wake_thread();

    void roll_dice();
//OUTPUT LIMBO
    void GBase_1_clicked(int piece_id);
    void GBase_2_clicked(int piece_id);
    void GBase_3_clicked(int piece_id);
    void GBase_4_clicked(int piece_id);

    void BBase_1_clicked(int piece_id);
    void BBase_2_clicked(int piece_id);
    void BBase_3_clicked(int piece_id);
    void BBase_4_clicked(int piece_id);

    void RBase_1_clicked(int piece_id);
    void RBase_2_clicked(int piece_id);
    void RBase_3_clicked(int piece_id);
    void RBase_4_clicked(int piece_id);

    void YBase_1_clicked(int piece_id);
    void YBase_2_clicked(int piece_id);
    void YBase_3_clicked(int piece_id);
    void YBase_4_clicked(int piece_id);
//OUTPUT BOARD
    void node_0_clicked(int id);
    void node_1_clicked(int id);
    void node_2_clicked(int id);
    void node_3_clicked(int id);
    void node_4_clicked(int id);
    void node_5_clicked(int id);
    void node_6_clicked(int id);
    void node_7_clicked(int id);
    void node_8_clicked(int id);
    void node_9_clicked(int id);

    void node_10_clicked(int id);
    void node_11_clicked(int id);
    void node_12_clicked(int id);
    void node_13_clicked(int id);
    void node_14_clicked(int id);
    void node_15_clicked(int id);
    void node_16_clicked(int id);
    void node_17_clicked(int id);
    void node_18_clicked(int id);
    void node_19_clicked(int id);

    void node_20_clicked(int id);
    void node_21_clicked(int id);
    void node_22_clicked(int id);
    void node_23_clicked(int id);
    void node_24_clicked(int id);
    void node_25_clicked(int id);
    void node_26_clicked(int id);
    void node_27_clicked(int id);
    void node_28_clicked(int id);
    void node_29_clicked(int id);

    void node_30_clicked(int id);
    void node_31_clicked(int id);
    void node_32_clicked(int id);
    void node_33_clicked(int id);
    void node_34_clicked(int id);
    void node_35_clicked(int id);
    void node_36_clicked(int id);
    void node_37_clicked(int id);
    void node_38_clicked(int id);
    void node_39_clicked(int id);

    //HOME OUTPUT
    void GH1_clicked(int id);
    void GH2_clicked(int id);
    void GH3_clicked(int id);
    void GH4_clicked(int id);

    void BH1_clicked(int id);
    void BH2_clicked(int id);
    void BH3_clicked(int id);
    void BH4_clicked(int id);

    void RH1_clicked(int id);
    void RH2_clicked(int id);
    void RH3_clicked(int id);
    void RH4_clicked(int id);

    void YH1_clicked(int id);
    void YH2_clicked(int id);
    void YH3_clicked(int id);
    void YH4_clicked(int id);



//-----------------------------------------------------------
public slots:

    void on_Dice_Button_clicked();
    void Show_Dice(int N);
    void set_Dice_Player(bool state,int player);

    void GBase1(bool checked);
    void GBase1_set_token (bool isPushed);
    void GBase2(bool checked);
    void GBase2_set_token (bool isPushed);
    void GBase3(bool checked);
    void GBase3_set_token (bool isPushed);
    void GBase4(bool checked);
    void GBase4_set_token (bool isPushed);

    void BBase1(bool checked);
    void BBase1_set_token (bool isPushed);
    void BBase2(bool checked);
    void BBase2_set_token (bool isPushed);
    void BBase3(bool checked);
    void BBase3_set_token (bool isPushed);
    void BBase4(bool checked);
    void BBase4_set_token (bool isPushed);

    void RBase1(bool checked);
    void RBase1_set_token (bool isPushed);
    void RBase2(bool checked);
    void RBase2_set_token (bool isPushed);
    void RBase3(bool checked);
    void RBase3_set_token (bool isPushed);
    void RBase4(bool checked);
    void RBase4_set_token (bool isPushed);

    void YBase1(bool checked);
    void YBase1_set_token (bool isPushed);
    void YBase2(bool checked);
    void YBase2_set_token (bool isPushed);
    void YBase3(bool checked);
    void YBase3_set_token (bool isPushed);
    void YBase4(bool checked);
    void YBase4_set_token (bool isPushed);


    void on_GBase1_clicked();
    void on_GBase2_clicked();
    void on_GBase3_clicked();
    void on_GBase4_clicked();

    void on_BBase1_clicked();
    void on_BBase2_clicked();
    void on_BBase3_clicked();
    void on_BBase4_clicked();

    void on_RBase1_clicked();
    void on_RBase2_clicked();
    void on_RBase3_clicked();
    void on_RBase4_clicked();

    void on_YBase1_clicked();
    void on_YBase2_clicked();
    void on_YBase3_clicked();
    void on_YBase4_clicked();

//BOARD SLOTS---------------------------------------------------------------
   // void on_node_0_toggled(int player_id);

    void on_node_0_clicked();//GREEN PLAYER ENTRANCE
    void node_0_set_state(bool checked);
    void node_0_set_player(int player_id);

    void on_node_1_clicked();
    void node_1_set_state(bool checked);
    void node_1_set_player(int player_id);

    void on_node_2_clicked();
    void node_2_set_state(bool checked);
    void node_2_set_player(int player_id);

    void on_node_3_clicked();
    void node_3_set_state(bool checked);
    void node_3_set_player(int player_id);

    void on_node_4_clicked();
    void node_4_set_state(bool checked);
    void node_4_set_player(int player_id);

    void on_node_5_clicked();
    void node_5_set_state(bool checked);
    void node_5_set_player(int player_id);

    void on_node_6_clicked();
    void node_6_set_state(bool checked);
    void node_6_set_player(int player_id);

    void on_node_7_clicked();
    void node_7_set_state(bool checked);
    void node_7_set_player(int player_id);

    void on_node_8_clicked();
    void node_8_set_state(bool checked);
    void node_8_set_player(int player_id);

    void on_node_9_clicked();
    void node_9_set_state(bool checked);
    void node_9_set_player(int player_id);


    void on_node_10_clicked();//BLUE PLAYER ENTRANCE
    void node_10_set_state(bool checked);
    void node_10_set_player(int player_id);

    void on_node_11_clicked();
    void node_11_set_state(bool checked);
    void node_11_set_player(int player_id);

    void on_node_12_clicked();
    void node_12_set_state(bool checked);
    void node_12_set_player(int player_id);

    void on_node_13_clicked();
    void node_13_set_state(bool checked);
    void node_13_set_player(int player_id);

    void on_node_14_clicked();
    void node_14_set_state(bool checked);
    void node_14_set_player(int player_id);

    void on_node_15_clicked();
    void node_15_set_state(bool checked);
    void node_15_set_player(int player_id);

    void on_node_16_clicked();
    void node_16_set_state(bool checked);
    void node_16_set_player(int player_id);

    void on_node_17_clicked();
    void node_17_set_state(bool checked);
    void node_17_set_player(int player_id);

    void on_node_18_clicked();
    void node_18_set_state(bool checked);
    void node_18_set_player(int player_id);

    void on_node_19_clicked();
    void node_19_set_state(bool checked);
    void node_19_set_player(int player_id);


    void on_node_20_clicked();//RED PLAYER ENTRANCE
    void node_20_set_state(bool checked);
    void node_20_set_player(int player_id);

    void on_node_21_clicked();
    void node_21_set_state(bool checked);
    void node_21_set_player(int player_id);

    void on_node_22_clicked();
    void node_22_set_state(bool checked);
    void node_22_set_player(int player_id);

    void on_node_23_clicked();
    void node_23_set_state(bool checked);
    void node_23_set_player(int player_id);

    void on_node_24_clicked();
    void node_24_set_state(bool checked);
    void node_24_set_player(int player_id);

    void on_node_25_clicked();
    void node_25_set_state(bool checked);
    void node_25_set_player(int player_id);

    void on_node_26_clicked();
    void node_26_set_state(bool checked);
    void node_26_set_player(int player_id);

    void on_node_27_clicked();
    void node_27_set_state(bool checked);
    void node_27_set_player(int player_id);

    void on_node_28_clicked();
    void node_28_set_state(bool checked);
    void node_28_set_player(int player_id);

    void on_node_29_clicked();
    void node_29_set_state(bool checked);
    void node_29_set_player(int player_id);


    void on_node_30_clicked();//YELLOW PLAYER ENTRANCE
    void node_30_set_state(bool checked);
    void node_30_set_player(int player_id);

    void on_node_31_clicked();
    void node_31_set_state(bool checked);
    void node_31_set_player(int player_id);

    void on_node_32_clicked();
    void node_32_set_state(bool checked);
    void node_32_set_player(int player_id);

    void on_node_33_clicked();
    void node_33_set_state(bool checked);
    void node_33_set_player(int player_id);

    void on_node_34_clicked();
    void node_34_set_state(bool checked);
    void node_34_set_player(int player_id);

    void on_node_35_clicked();
    void node_35_set_state(bool checked);
    void node_35_set_player(int player_id);

    void on_node_36_clicked();
    void node_36_set_state(bool checked);
    void node_36_set_player(int player_id);

    void on_node_37_clicked();
    void node_37_set_state(bool checked);
    void node_37_set_player(int player_id);

    void on_node_38_clicked();
    void node_38_set_state(bool checked);
    void node_38_set_player(int player_id);

    void on_node_39_clicked();
    void node_39_set_state(bool checked);
    void node_39_set_player(int player_id);


    void on_GH4_clicked();
    void GH4_set_state(bool cheacked);
    void on_GH3_clicked();
    void GH3_set_state(bool cheacked);
    void on_GH2_clicked();
    void GH2_set_state(bool cheacked);
    void on_GH1_clicked();
    void GH1_set_state(bool cheacked);

    void on_BH1_clicked();
    void BH1_set_state(bool cheacked);
    void on_BH2_clicked();
    void BH2_set_state(bool cheacked);
    void on_BH3_clicked();
    void BH3_set_state(bool cheacked);
    void on_BH4_clicked();
    void BH4_set_state(bool cheacked);

    void on_RH1_clicked();
    void RH1_set_state(bool cheacked);
    void on_RH2_clicked();
    void RH2_set_state(bool cheacked);
    void on_RH3_clicked();
    void RH3_set_state(bool cheacked);
    void on_RH4_clicked();
    void RH4_set_state(bool cheacked);

    void on_YH4_clicked();
    void YH4_set_state(bool cheacked);
    void on_YH3_clicked();
    void YH3_set_state(bool cheacked);
    void on_YH2_clicked();
    void YH2_set_state(bool cheacked);
    void on_YH1_clicked();
    void YH1_set_state(bool cheacked);

private:
    Ui::ClassicBoardDialog *ui;
};

#endif // CLASSICBOARDDIALOG_H
