#ifndef FIELD_CLASS_H
#define FIELD_CLASS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "time.h"

class Field
{
private:
    struct Node // the node structure for the list representing the 56 game positions + the 24 home positions
    {
        int ID; //0-78 IDs of the nodes used to find them in an array of pointers to the nodes
        int state; // 0 position is empty, 1-4 number of pieces stacked
        int player_id; // 0 no player here, 1-4 ID of player on this position

        Node()
        {
            state = 0;
            player_id = 0;
        }
    };
public:
    Node* field_list[56];

    inline Field();

   inline ~Field();

    inline int get_position_state(int pos_id);
    inline int get_position_player(int pos_id);
};

#endif // FIELD_CLASS_H
