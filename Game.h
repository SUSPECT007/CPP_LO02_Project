//
// Created by dell on 2022/11/3.
//

#ifndef INC_0000_GAME_H
#define INC_0000_GAME_H

#include "Card.h"
#include "Function.h"


using namespace std;

class Card;

class Player;
class EXPlayer;
//class MyCompare;



class Desk {
protected:
    map<Card *, int> deck;

    // friend class Player;
//    static Desk * instance;
//    Desk(const Desk &)=delete;
//    Desk& operator=(const Desk &)=delete;

public:
      Desk();

    virtual ~Desk() {
        for (auto it = deck.begin(); it != deck.end(); ++it) {
            if(it->first!=NULL){
            //delete it->first;//此处可以省略，会造成一个错误
            //it->first=NULL;
            deck.erase(it);
            }
        }
    }

//    static Desk & getinstance(){if(instance==nullptr) instance = new Desk;return *instance;};
//    static void liberer(){ delete instance;instance = NULL;}
    void showDeck(ostream &f = cout);

    void change(Card *c);

    class iterator : public map<Card *, int>::iterator {
    public:
        iterator(typename map<Card *, int>::iterator it = map<Card *, int>::iterator()) : map<Card *, int>::iterator(
                it) {}
    };

    iterator begin() { return iterator(deck.begin()); }

    iterator end() { return iterator(deck.end()); }

    bool RemoveCard(int i,Player &p);
 //   void GetDescription();
};

class EXDesk:public Desk{
protected:


public:
 EXDesk();


};


class PlayGame {
private:
    vector<Player *> person;
    //vector<AI *> aip;
    int p_num;
    int ai_num;
    Desk *d;
    int touzi;
    bool Newturn=true;
    string winer="";

public:
    PlayGame();
    void chosse(int i =1);
    void start(int version=1);
    void roll(const Player &p);
    void rollext( Player *p);
    void Income(Player &p);
    void Buy(Player &p,int version =1 );
    void B_G(Player *p,int version=2 );
    void AIroll(Player &p);
    int AIbuy(Player & p);
    void endturn();
    void BaseVersion(int ver =1);
    void EXVexsion(int ver=2 );
    bool over(Player & p);
    void guanjun();

};


#endif //INC_0000_GAME_H
