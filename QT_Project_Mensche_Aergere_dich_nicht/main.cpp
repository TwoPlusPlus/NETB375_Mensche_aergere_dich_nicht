#include <QCoreApplication>
#include <iostream>
#include <string>
#include <cstdlib>
#include "time.h"

//------------------//

#include "game.h"
#include "player_class.h"
#include "field_class.h"
#include "template_stack_class.h"

using namespace  std;

int main()
{
    srand(time(NULL));
    Game test(4,2);
    for(int i = 0; i < test.player_num; i++)
    {
        cout << test.player_list[i]->get_name() << " " << test.player_list[i]->get_id() << " " << test.player_list[i]->get_start() << " " << test.player_list[i]->get_finish()<< endl;

        for(int j = 0; j < 4; j++)
        {
            cout << test.player_list[i] ->piece_list[j]->get_piece_id() <<
            " " << test.player_list[i]->piece_list[j]->get_player_id() <<
            " " << test.player_list[i]->piece_list[j]->get_moves() << endl;
        }
        cout << endl;
    }

    for(int i = 0; i < 100; i++)
    {
        cout << test.dice() << " ";
    }

    return 0;
}
