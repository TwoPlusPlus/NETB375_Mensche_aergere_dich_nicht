#include "player_ai_class.h"

//==============================PLAYER CLASS======================================//

Player::Player(QString input_name, int input_ID, bool bot, Field* game_field)
{
    ID = input_ID;
    name = input_name;
    board = game_field;
    active_player_pieces = 0;
    is_bot = bot;
    switch(ID)
    {
        case 0:
            start_move = 0;
            finish_move = 39;
            break;
        case 1:
            start_move = 10;
            finish_move = 9;
            break;
        case 2:
            start_move = 20;
            finish_move = 19;
            break;
        case 3:
            start_move = 30;
            finish_move = 29;
            break;
        default:
            break;
    }
    for (int i = 0; i < 4; i++)
    {
        piece_list[i] = new Piece(i,ID);
    }
    for (int i = 0; i < 4; i++)
    {
        home_score[i] = false;
    }
}
Player::Player(Player &a)
{
    this->ID = a.ID;
    this->name = a.name;
    this->active_player_pieces = a.active_player_pieces;
    this->is_bot = a.is_bot;
    this->start_move = a.start_move;
    this->finish_move = a.finish_move;
    for (int i = 0; i < 4; i++)
    {
        this->piece_list[i] = new Piece(*a.piece_list[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        this->home_score[i] = a.home_score[i];
    }
}

Player::~Player()
{
     for (int i = 0; i < 4; i++)
     {
         if(piece_list[i])
            delete piece_list[i];
         piece_list[i] = 0;
     }
}

QString Player::get_name()
{
    return name;
}
int Player::get_player_id()
{
    return ID;
}
int Player::get_player_start()
{
    return start_move;
}
int Player::get_player_finish()
{
    return finish_move;
}

bool Player::is_player_active()
{
    if (active_player_pieces > 0)
        return true;
    return false;
}
bool Player::is_player_bot()
{
    return is_bot;
}

int Player::get_piece_current_node_id(int piece_id)
{
    int debug = ((piece_list[piece_id]->get_piece_moves() + start_move) % 40);
    return debug; // calculates pieces current node id by combining number of moves made and starting node ID
}															// modulus division by 40 (number of nodes) gives us the correct ID of the node

void Player::update_score()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->board->home_node_list[this->get_player_id()][i]->occupied_piece != 0)
            home_score[i] = true;
    }
}
bool Player::is_player_win()
{
    int x = 0;
    for (int i = 0; i < 4; i++)
    {
       if (home_score[i] == true)
           x++;
    }
    if (x == 4)
        return true;
    return false;
}

//new==============================================
void Player::move_piece (int piece_id, int roll)
{
    int x = this->get_piece_current_node_id(piece_id);
    this->board->de_occupy_node(x);

    this->piece_list[piece_id]->update_moves(roll, false);

    x = this->get_piece_current_node_id(piece_id);
    this->board->occupy_node(x, this->piece_list[piece_id]);
}

void Player::activate_piece(int piece_id)
{
    if (this->get_player_id() == 0 && piece_id == 1)
    {
        int f= 1;
        f++;
    }

    this->piece_list[piece_id]->update_moves(0, false);

    this->board->occupy_node(this->start_move, this->piece_list[piece_id]);

    this->active_player_pieces++;
}
void Player::deactivate_piece(int piece_id)
{
    int x = this->get_piece_current_node_id(piece_id);
    this->board->de_occupy_node(x);

    this->piece_list[piece_id]->update_moves(-1,false);

    this->active_player_pieces--;
}
void Player::move_piece_home(int piece_id, int roll)
{
    int x = this->get_piece_current_node_id(piece_id);
    this->board->de_occupy_node(x);

    x = this->piece_list[piece_id]->get_piece_moves();
    x = 39 - x;
    if(x==0)
        this->piece_list[piece_id]->update_moves(39, false);
    this->piece_list[piece_id]->update_moves(x, false);

    x = roll - x;
    this->piece_list[piece_id]->update_moves(x, true);

    x = this->piece_list[piece_id]->get_piece_home_moves();
    this->board->occupy_home_node(x, this->get_player_id(), this->piece_list[piece_id]);

    this->update_score();

    this->active_player_pieces--;
}

void Player::move_home_piece(int piece_id, int roll)
{
    int x = this->piece_list[piece_id]->get_piece_home_moves();
    this->board->de_occupy_home_node(x, this->get_player_id());

    this->piece_list[piece_id]->update_moves(roll, true);

    x = this->piece_list[piece_id]->get_piece_home_moves();
    this->board->occupy_home_node(x, this->get_player_id(), this->piece_list[piece_id]);

    this->update_score();
}

//json

void Player::read(const QJsonObject &json)
{

    ID = json["id"].toInt();
    name = json["id"].toString();
    active_player_pieces = json["active-player-pieces"].toInt();
    is_bot = json["is-bot"].toBool();
    start_move = json["start-move"].toInt();
    finish_move = json["finish_move"].toInt();

    QJsonArray pieces_array = json["pieces"].toArray();
    for (int i = 0; i < 4; i++)
    {
        QJsonObject pieceObject = pieces_array[i].toObject();
        Piece piece(i,this->ID);
        piece.read(pieceObject);
        piece_list[i] = new Piece(piece);
    }
}

void Player::write(QJsonObject &json) const
{
    json["id"] = ID;
    json["name"] = name;
    json["active-player-pieces"] = active_player_pieces;
    json["is-bot"] = is_bot;
    json["start-move"] = start_move;
    json["finish-move"] = finish_move;
    QJsonArray piece_array;
    for(int i = 0; i < 4; i++)
    {
        QJsonObject pieceObject;
        piece_list[i]->write(pieceObject);
        piece_array.append(pieceObject);
    }
    json["pieces"] = piece_array;
}

//=============

//AI METHODS--------------------------------------------------------------


bool Player::ai_clear_start_pos(int i,int dice)
{
    if(this->board->node_list[this->get_player_start()]->state != 0)//CLEAR BOT STARTING FIELD
    {
        if(this->board->node_list[this->get_player_start() + dice]->state == 0)
        {
            this->move_piece(board->node_list[this->get_player_start()]->occupied_piece->get_piece_id(), dice);//move token
            return true;
        }
        else
        {
            if(this->get_player_id() != this->board->node_list[this->get_player_start() + dice]->occupied_piece->get_piece_player_id())//remove enemy token and clear starting field
            {
                int enemy_player_id = this->board->node_list[this->get_player_start() + dice]->occupied_piece->get_piece_player_id();
                int token_id = this->board->node_list[this->get_player_start() + dice]->occupied_piece->get_piece_id();

                this->player_list[enemy_player_id]->deactivate_piece(token_id);//REMOVE ENEMY PLAYER TOKEN

                this->move_piece(board->node_list[this->get_player_start()]->occupied_piece->get_piece_id(), dice);// MOVE TOKEN TO THE NEW POSITION
                return true;
            }
            //else it's one of player's token -> do notting
        }
    }
    return false;
}
bool Player::ai_score_point(int i, int dice)
{
    if(this->piece_list[i]->get_piece_moves() + dice > 39  && this->piece_list[i]->get_piece_moves() + dice < 44)//SCORE A POINT
    {
        int x = ( this->piece_list[i]->get_piece_moves() + dice ) % 40;
        if(this->board->home_node_list[this->get_player_id()][x]->state != 0)
        {
            this->move_piece_home(i,dice);
            return true;
        }
    }
    return false;

}

bool Player::ai_remove_enemy_token(int i,int dice)
{
    if (this->get_player_id() == 3 && i == 0){
        int f = 3;
        f++;
    }
    //REMOVE OPPONENT'S TOKEN FROM PLAY
    if(this->piece_list[i]->get_piece_moves() > -1)// check if token is on the board
    {
        if(this->board->node_list[(this->get_piece_current_node_id(i) + dice)%40]->state != 0)//check board's node_list->state( token position + dice)
        {
            if(this->get_player_id() != this->board->node_list[(this->get_piece_current_node_id(i) + dice)%40]->occupied_piece->get_piece_player_id() ) // check if token isn't one of current player's tokes
            {
                //Remove opponet's token & move player's token there

                int enemy_player_id = this->board->node_list[(this->get_piece_current_node_id(i) + dice)%40]->occupied_piece->get_piece_player_id();
                int token_id = this->board->node_list[(this->get_piece_current_node_id(i) + dice)%40]->occupied_piece->get_piece_id();

                this->player_list[enemy_player_id]->deactivate_piece(token_id);//REMOVE ENEMY PLAYER TOKEN

                this->move_piece(board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_id(), dice);// MOVE CURRET PLAYER'S TOKEN TO THE NEW POSITION
                return true;
            }
        }
    }
    return false;
}

void Player::ai_dice_6()
{
    if(this->board->node_list[this->get_player_start()]->state != 0)
    {
        if(this->board->node_list[this->get_player_start()]->occupied_piece->get_piece_player_id() != this->get_player_id())
        {
            //Remove opponet's token & put player's token

            int enemy_player_id = this->board->node_list[this->get_player_start()]->occupied_piece->get_piece_player_id();
            int token_id = this->board->node_list[this->get_player_start()]->occupied_piece->get_piece_id();

            this->player_list[enemy_player_id]->deactivate_piece(token_id);//REMOVE ENEMY PLAYER TOKEN

            for(int i = 0;i<4;i++)
            {
                if(this->piece_list[i]->get_piece_moves() == -1)
                {
                    this->activate_piece(i);
                    //this->board->occupy_node(this->get_player_start(),this->piece_list[i]);
                    break;
                }
            }
        }
    }
    else
    {
        for(int i = 0;i<4;i++) // find a token that is not on the board by checking if token moves is = -1
        {
            if(this->piece_list[i]->get_piece_moves() == -1)
            {
                this->activate_piece(i);
                //this->board->occupy_node(this->get_player_start(),this->piece_list[i]);
                break;
            }
        }
    }
}
int Player::ai_move_token(int dice)
{
    int PRIORITY[4] = {-1,-1,-1,-1};//var for each token
    int selected_token = -1;
    int max = -1;

    for(int i = 0;i<4;i++) //аsing priority to each token
    {
        //CHEACK FIELDS BEHIND TOKEN AND ADD PRIORITY

        if(this->piece_list[i]->get_piece_moves() ==-1 || this->piece_list[i]->get_piece_moves() == 39)
            continue;
        PRIORITY[i] = 0;
        int x = this->get_piece_current_node_id(i);
        if(this->board->node_list[x + dice]->state != 0)
            if(this->board->node_list[x + dice]->occupied_piece->get_piece_player_id() == this->get_player_id())
                continue;

        if(this->board->node_list[(40 + this->get_piece_current_node_id(i) - 5)%40]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(40 + this->get_piece_current_node_id(i) - 5)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[(40 + this->get_piece_current_node_id(i) - 4)%40]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(40 + this->get_piece_current_node_id(i) - 4)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[(40 + this->get_piece_current_node_id(i) - 3)%40]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(40 + this->get_piece_current_node_id(i) - 3)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[(40 + this->get_piece_current_node_id(i) - 2)%40]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(40 + this->get_piece_current_node_id(i) - 2)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[(40 + this->get_piece_current_node_id(i) - 1)%40]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(40 + this->get_piece_current_node_id(i) - 1)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }

        //CHEACK FIELDS IN FRONT OF TOKEN AND SUBTRACT FROM PRIORITY

        if(this->board->node_list[this->get_piece_current_node_id(i) + 5]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(this->get_piece_current_node_id(i) + 5)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=5;
            }
        }
        if(this->board->node_list[this->get_piece_current_node_id(i) + 4]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(this->get_piece_current_node_id(i) + 4)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[this->get_piece_current_node_id(i) + 3]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(this->get_piece_current_node_id(i) + 3)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[this->get_piece_current_node_id(i) + 2]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(this->get_piece_current_node_id(i) + 2)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=10;
            }
        }
        if(this->board->node_list[this->get_piece_current_node_id(i) + 1]->state != 0)
        {
            if(this->board->node_list[this->get_piece_current_node_id(i)]->occupied_piece->get_piece_player_id() != this->board->node_list[(this->get_piece_current_node_id(i) + 1)%40]->occupied_piece->get_piece_player_id())
            {
                PRIORITY[i]+=20;
            }
        }
        //MOVE TOKEN WITH HIGHEST PRIORITY
        if(max < PRIORITY[i])
        {
            max = PRIORITY[i];
            selected_token = i;
        }
        //check if there is one of players token in the way
    }
    return selected_token;

}

void Player::ai_exec(int dice)
{
    if(this->is_player_active())
    {
        int x = 0;
        for(int i = 0;i<4;i++)
        {
            if(ai_clear_start_pos(i,dice))
            {
                x = 1;
                break;
            }

            if(ai_score_point(i,dice))
            {
                x = 1;
                break;
            }
            if(ai_remove_enemy_token(i,dice))
            {
                x = 1;
                break;
            }
        }
        if(x == 0)
        {
            if(dice==6)
                ai_dice_6();
            else
                this->move_piece(ai_move_token(dice), dice);
        }
    }
    else
    {
        if(dice == 6)
        {
            ai_dice_6();

            dice = rand()%6+1;

            for(int i = 0;i < 4; i++)
            {
                if(ai_clear_start_pos(i,dice))
                    break;
            }
        }

    }

}
