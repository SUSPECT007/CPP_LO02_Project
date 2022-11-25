//
// Created by dell on 2022/11/3.
//

#ifndef INC_0000_PLAYER_H
#define INC_0000_PLAYER_H

#include "Card.h"
#include "Game.h"


class PlayGame;
using namespace std;

class Card;
class Desk;
class EXDesk;

class Player{
protected:
    map <Card*,int>  Cbag;
    int Money;
    string P_Name;
    bool trainStation;
    bool shoppingMall;
    bool amusementPark;
    bool radioTower;
public:
    Player();
    Player( Desk *d );
    virtual~Player();
    void deposit(int val);//得到钱财
    int withdraw(int val);//支出钱财
    int GetMoney() const {return Money; }
    void SETName(const string& name) { P_Name=name; }
    string GetPName() const  { return P_Name; };

    virtual int Show();

    bool RemoveCard(int i );
    bool AddCard(int i );

    bool GettrainStation() const {return trainStation; }
    bool GetshoppingMall() const {return shoppingMall; }
    bool GetamusementPark() const {return amusementPark; }
    bool GetradioTower() const {return radioTower; }

    virtual bool Iswon();
    virtual void SetTrainStation(bool b){trainStation=b;}
    virtual void SetShoppingMall(bool b){shoppingMall=b;}
    virtual void SetAmusementPark(bool b){amusementPark=b;}
    virtual void SetRadioTower(bool b){radioTower=b;}
public:
    class iterator:public map <Card*,int>::iterator{
    public:
        iterator (typename map <Card*,int>::iterator it = map <Card*,int>::iterator()): map <Card*,int>::iterator(it){}
    };
    iterator begin () {return iterator(Cbag.begin()); }
    iterator end () {return iterator(Cbag.end()); }
     int  GetCn(Card* c)  {return this->Cbag[c]; }
public://AIaction


};


class EXPlayer:public Player{
protected:
    bool Port;
    bool Airport;
public:
    EXPlayer( Desk *d );//:Player(d)
    /*{  Port=false;
    Airport=false; }*/
    EXPlayer(){}
~EXPlayer(){}
    bool GetPort() const {return Port; }
    bool GetAirport() const {return Airport; }


    virtual void SetPortA(bool b){Port=b;}
    virtual void SetAirport(bool b){Airport=b;}

     virtual int Show();
     bool Iswon();


};


ostream & operator<<(ostream& f,const Player & p);

#endif //INC_0000_PLAYER_H
