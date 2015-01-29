#ifndef CLASSICBOARDDIALOG_H
#define CLASSICBOARDDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class ClassicBoardDialog;
}

class ClassicBoardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClassicBoardDialog(QWidget *parent = 0);
    ~ClassicBoardDialog();



public slots:

    bool on_Dice_Button_clicked();

    void on_GBase1_toggled(bool checked);

    void on_GBase2_toggled(bool checked);

    void on_GBase3_toggled(bool checked);

    void on_GBase4_toggled(bool checked);

    void on_BBase1_toggled(bool checked);

    void on_BBase2_toggled(bool checked);

    void on_BBase3_toggled(bool checked);

    void on_BBase4_toggled(bool checked);

    void on_RBase1_toggled(bool checked);

    void on_RBase2_toggled(bool checked);

    void on_RBase3_toggled(bool checked);

    void on_RBase4_toggled(bool checked);

    void on_YBase1_toggled(bool checked);

    void on_YBase2_toggled(bool checked);

    void on_YBase3_toggled(bool checked);

    void on_YBase4_toggled(bool checked);
//BOARD SLOTS---------------------------------------------------------------
    void on_node_0_toggled(int player_id);//GREEN PLAYER ENTRANCE

    void on_node_1_toggled(int player_id);

    void on_node_2_toggled(int player_id);

    void on_node_3_toggled(int player_id);

    void on_node_4_toggled(int player_id);

    void on_node_5_toggled(int player_id);

    void on_node_6_toggled(int player_id);

    void on_node_7_toggled(int player_id);

    void on_node_8_toggled(int player_id);

    void on_node_9_toggled(int player_id);

    void on_node_10_toggled(int player_id);

    void on_node_11_toggled(int player_id);

    void on_node_12_toggled(int player_id);

    void on_node_13_toggled(int player_id);

    void on_node_14_toggled(int player_id);

    void on_node_15_toggled(int player_id);

    void on_node_16_toggled(int player_id);

    void on_node_17_toggled(int player_id);

    void on_node_18_toggled(int player_id);

    void on_node_19_toggled(int player_id);

    void on_node_20_toggled(int player_id);

    void on_node_21_toggled(int player_id);

    void on_node_22_toggled(int player_id);

    void on_node_23_toggled(int player_id);

    void on_node_24_toggled(int player_id);

    void on_node_25_toggled(int player_id);

    void on_node_26_toggled(int player_id);

    void on_node_27_toggled(int player_id);

    void on_node_28_toggled(int player_id);

    void on_node_29_toggled(int player_id);

    void on_node_30_toggled(int player_id);

    void on_node_31_toggled(int player_id);

    void on_node_32_toggled(int player_id);

    void on_node_33_toggled(int player_id);

    void on_node_34_toggled(int player_id);

    void on_node_35_toggled(int player_id);

    void on_node_36_toggled(int player_id);

    void on_node_37_toggled(int player_id);

    void on_node_38_toggled(int player_id);

    void on_node_39_toggled(int player_id);


private:
    Ui::ClassicBoardDialog *ui;
};

#endif // CLASSICBOARDDIALOG_H
