//
// Created by dell on 2022/11/3.
//

#ifndef INC_0000_CARD_H
#define INC_0000_CARD_H
#include <vector>
#include "Enums.h"

#include "Player.h"

using namespace std;
class Player;
class EXPlayer;
class Card{
protected:
    int Lroll;
    int Hroll;
    int Cost;
    int Value;
    int Num;
    Color color;
    Icon icon;
    bool Renovation;
    string Name;
    string Description;
public:
    virtual void action ( vector<Player*> v,Player *p1=NULL) =0;
    Card()=default;
    int GetLroll() const{return Lroll; }
    int GetHroll() const{return Hroll; }
    int GetCost() const{return Cost; }
    int GetValue() const{return Value; }
    int GetNum() const{return Num; }
    Icon GetIcon() const{return icon; }
    string GetName() const{return Name; }
    bool GetRenovation() const{return Renovation; }
    void SETNum(int n)  { Num=n;}
    void SETCard( int Lroll,int Hroll,int Cost,int Value,int Num,Color color,Icon icon,bool Renovation,string Name );
    string GetDescription(){return Description;};
};

//*************************************************************************************
class BlueCard: public Card {
public:
     virtual void action(vector<Player*> v,Player *p1=NULL);
};
class WheatField : public BlueCard {
public:
    WheatField();
};

class Ranch : public BlueCard {
public:
    Ranch();
};

class Forest : public BlueCard {
public:
    Forest();
};

class Mine : public BlueCard {
public:
    Mine();
};

class Orchard : public BlueCard {   //果园
public:
    Orchard();
};

//********************************************
class GreenCard : public Card {
public:
     virtual void action(vector<Player*> v,Player *p1=NULL);
    //void set_multiplier_icon(Icon icon);
//private:
//    Icon multiplier = Icon::none;

};
class Bakery : public GreenCard {
public:
    Bakery();
};

class ConvenienceStore : public GreenCard {
public:

    ConvenienceStore();
};

class CheeseFactory : public GreenCard {
public:
    virtual void action(vector<Player*> v,Player *p1=NULL) ;
    CheeseFactory();
};

class FurnitureFactory : public GreenCard {
public:
    FurnitureFactory();
    virtual void action(vector<Player*> v,Player *p1=NULL);
};

class FruitAndVegetableMarket : public GreenCard {
public:
    FruitAndVegetableMarket();
    virtual void action(vector<Player*> v,Player *p1=NULL);
};
//*****************************************************************
class RedCard : public Card {
public:
     virtual void action( vector<Player*> v,Player *p1=NULL);

};

class Cafe : public RedCard {
public:
    Cafe();
};

class FamilyRestaurant : public RedCard {
public:
    FamilyRestaurant();
};
//**************************************************

class PurpleCard : public Card {
public:
    virtual void action(vector<Player*> v,Player *p1=NULL) =0;
};

class BusinessCenter : public PurpleCard {
public:
    BusinessCenter();
    virtual void action(vector<Player*> v,Player *p1=NULL);

};

class Stadium : public PurpleCard {
public:
    Stadium();
    virtual void action(vector<Player*> v,Player *p1=NULL);

};

class TVStation : public PurpleCard {
public:
    TVStation();
    virtual void action(vector<Player*> v,Player *p1=NULL);
};

//**************************************************
class YellowCard : public Card {
public:
    virtual void action(vector<Player*> v,Player *p1=NULL);
    bool active;
private:
};

class AmusementPark : public YellowCard {
public:
    AmusementPark();

};

class RadioTower : public YellowCard {
public:
    RadioTower();

};

class ShoppingMall : public YellowCard {
public:
    ShoppingMall();

};

class TrainStation : public YellowCard {
public:
    TrainStation();

};
//****************************************************扩展包
class Flowerfield : public BlueCard {
public:
    Flowerfield();
};

class Mackerelboat: public BlueCard {
public:
    Mackerelboat();
    virtual void action( vector<Player*> v,Player *p1=NULL);
};

class Tunaboat: public BlueCard {
public:
    Tunaboat();
    virtual void action( vector<Player*> v,Player *p1=NULL);
};


class Florist:public GreenCard{
public:
    Florist();
    virtual void action( vector<Player*> v,Player *p1=NULL);
};

class Foodmarket:public GreenCard{
public:
    Foodmarket();
    virtual void action( vector<Player*> v,Player *p1=NULL);
};

class Hamburgershop:public RedCard{
public:
    Hamburgershop();
};

class Pizzeria:public RedCard{
public:
    Pizzeria();
};

class Sushibar:public RedCard{
public:
    Sushibar();
    virtual void action( vector<Player*> v,Player *p1=NULL);
};

class Publisher:public PurpleCard{
public:
    Publisher();
    virtual void action(vector<Player*> v,Player *p1=NULL);
};

class Taxoffice:public PurpleCard{
public:
    Taxoffice();
    virtual void action(vector<Player*> v,Player *p1=NULL);
};

#endif //INC_0000_CARD_H
