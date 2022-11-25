//
// Created by dell on 2022/11/3.
//

#ifndef INC_0000_FUNCTION_H
#define INC_0000_FUNCTION_H
#include "Player.h"
#include "Card.h"
#include <vector>
#include "Game.h"

class Card;
class Player;
class PlayGame;
class Desk;
using namespace std;
int getrandom() ;

class MyCompare{
    bool operator()( const Card*  c1, const Card* c2) ;
};

vector<Card*> GetCard(int r,Desk * d);
 void getcard(vector<Card*>&v,int r,Desk * d);
#endif //INC_0000_FUNCTION_H
