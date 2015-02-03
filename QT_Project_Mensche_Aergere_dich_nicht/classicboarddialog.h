#ifndef CLASSICBOARDDIALOG_H
#define CLASSICBOARDDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QString>

namespace Ui {
class ClassicBoardDialog;
}

class ClassicBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClassicBoardDialog(QWidget *parent = 0);
    ~ClassicBoardDialog();

    void on_node_0_clicked();
    void on_node_1_clicked();
    void on_node_2_clicked();
    void on_node_3_clicked();
    void on_node_4_clicked();
    void on_node_5_clicked();
    void on_node_6_clicked();
    void on_node_7_clicked();
    void on_node_8_clicked();
    void on_node_9_clicked();
    void on_node_10_clicked();
    void on_node_11_clicked();
    void on_node_12_clicked();
    void on_node_13_clicked();
    void on_node_14_clicked();
    void on_node_15_clicked();
    void on_node_16_clicked();
    void on_node_17_clicked();
    void on_node_18_clicked();
    void on_node_19_clicked();
    void on_node_20_clicked();
    void on_node_21_clicked();
    void on_node_22_clicked();
    void on_node_23_clicked();
    void on_node_24_clicked();
    void on_node_25_clicked();
    void on_node_26_clicked();
    void on_node_27_clicked();
    void on_node_28_clicked();
    void on_node_29_clicked();
    void on_node_30_clicked();
    void on_node_31_clicked();
    void on_node_32_clicked();
    void on_node_33_clicked();
    void on_node_34_clicked();
    void on_node_35_clicked();
    void on_node_36_clicked();
    void on_node_37_clicked();
    void on_node_38_clicked();
    void on_node_39_clicked();

signals:
    void game_started();
    void roll_the_dice();

    //output
    //LIMBO
    void GBase1(bool checked);

    void GBase2(bool checked);

    void GBase3(bool checked);

    void GBase4(bool checked);

    void BBase1(bool checked);

    void BBase2(bool checked);

    void BBase3(bool checked);

    void BBase4(bool checked);

    void RBase1(bool checked);

    void RBase2(bool checked);

    void RBase3(bool checked);

    void RBase4(bool checked);

    void YBase1(bool checked);

    void YBase2(bool checked);

    void YBase3(bool checked);

    void YBase4(bool checked);

    //BOARD
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

public slots:

    void on_Dice_Button_clicked();
    void Show_Dice(int N);
    void set_Dice_Player(bool state,int player);

//BOARD SLOTS---------------------------------------------------------------
    void node_0_set_state(bool checked);
    void node_0_set_player(int player_id);//GREEN PLAYER ENTRANCE

    void node_1_set_state(bool checked);
    void node_1_set_player(int player_id);

    void node_2_set_state(bool checked);
    void node_2_set_player(int player_id);

    void node_3_set_state(bool checked);
    void node_3_set_player(int player_id);

    void node_4_set_state(bool checked);
    void node_4_set_player(int player_id);

    void node_5_set_state(bool checked);
    void node_5_set_player(int player_id);

    void node_6_set_state(bool checked);
    void node_6_set_player(int player_id);

    void node_7_set_state(bool checked);
    void node_7_set_player(int player_id);

    void node_8_set_state(bool checked);
    void node_8_set_player(int player_id);

    void node_9_set_state(bool checked);
    void node_9_set_player(int player_id);

    void node_10_set_state(bool checked);
    void node_10_set_player(int player_id);//BLUE PLAYER

    void node_11_set_state(bool checked);
    void node_11_set_player(int player_id);

    void node_12_set_state(bool checked);
    void node_12_set_player(int player_id);

    void node_13_set_state(bool checked);
    void node_13_set_player(int player_id);

    void node_14_set_state(bool checked);
    void node_14_set_player(int player_id);

    void node_15_set_state(bool checked);
    void node_15_set_player(int player_id);

    void node_16_set_state(bool checked);
    void node_16_set_player(int player_id);

    void node_17_set_state(bool checked);
    void node_17_set_player(int player_id);

    void node_18_set_state(bool checked);
    void node_18_set_player(int player_id);

    void node_19_set_state(bool checked);
    void node_19_set_player(int player_id);

    void node_20_set_state(bool checked);
    void node_20_set_player(int player_id);// RED PLAYER

    void node_21_set_state(bool checked);
    void node_21_set_player(int player_id);

    void node_22_set_state(bool checked);
    void node_22_set_player(int player_id);

    void node_23_set_state(bool checked);
    void node_23_set_player(int player_id);

    void node_24_set_state(bool checked);
    void node_24_set_player(int player_id);

    void node_25_set_state(bool checked);
    void node_25_set_player(int player_id);

    void node_26_set_state(bool checked);
    void node_26_set_player(int player_id);

    void node_27_set_state(bool checked);
    void node_27_set_player(int player_id);

    void node_28_set_state(bool checked);
    void node_28_set_player(int player_id);

    void node_29_set_state(bool checked);
    void node_29_set_player(int player_id);

    void node_30_set_state(bool checked);
    void node_30_set_player(int player_id);// YELLOW PLAYER

    void node_31_set_state(bool checked);
    void node_31_set_player(int player_id);

    void node_32_set_state(bool checked);
    void node_32_set_player(int player_id);

    void node_33_set_state(bool checked);
    void node_33_set_player(int player_id);

    void node_34_set_state(bool checked);
    void node_34_set_player(int player_id);

    void node_35_set_state(bool checked);
    void node_35_set_player(int player_id);

    void node_36_set_state(bool checked);
    void node_36_set_player(int player_id);

    void node_37_set_state(bool checked);
    void node_37_set_player(int player_id);

    void node_38_set_state(bool checked);
    void node_38_set_player(int player_id);

    void node_39_set_state(bool checked);
    void node_39_set_player(int player_id);
//output


private:
    Ui::ClassicBoardDialog *ui;
};

#endif // CLASSICBOARDDIALOG_H
