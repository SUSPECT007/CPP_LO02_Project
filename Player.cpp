//
// Created by dell on 2022/11/3.
//

#include "Player.h"
class Card;
using namespace std;
void Player::deposit(int val) {
    Money+=val;

}

int Player::withdraw(int val) {
    if (Money <val){
        int a=Money;
        Money=0;
        return a;
    }

    else Money-=val;
    return val;
}
Player::Player() {
    P_Name="";
    Money=3;
     trainStation= false;
     shoppingMall=false;
     amusementPark=false;
     radioTower=false;
    Card * c;

    c = new Cafe();Cbag[c]=0;
    c = new FamilyRestaurant();Cbag[c]=0;

    c = new WheatField(); Cbag[c]=1;
    c = new Ranch(); Cbag[c]=0;
    c = new Forest(); Cbag[c]=0;
    c = new Mine(); Cbag[c]=0;
    c = new Orchard();Cbag[c]=0;

    c = new Bakery(); Cbag[c]=1;
    c = new ConvenienceStore();Cbag[c]=0;
    c = new CheeseFactory(); Cbag[c]=0;
    c = new FurnitureFactory(); Cbag[c]=0;
    c = new FruitAndVegetableMarket(); Cbag[c]=0;



    c = new BusinessCenter(); Cbag[c]=0;
    c = new TVStation();Cbag[c]=0;
    c = new Stadium(); Cbag[c]=0;

//for (auto it = Desk::getinstance().begin();it!=Desk::getinstance().end();++it){
//    Cbag.insert(make_pair(it->first,0));
//}
}
Player::Player( Desk* d) {
    P_Name="";
    Money=3;
    trainStation= false;
    shoppingMall=false;
    amusementPark=false;
    radioTower=false;
    //EXDesk*p0= dynamic_cast<EXDesk*>(d);
    for (auto it= d->begin();it!=d->end();++it){
        if(it->first->GetName() == "WheatField"  ||it->first->GetName() =="Bakery" )
            Cbag.insert(make_pair(it->first,1));
        else Cbag.insert(make_pair(it->first,0));

    }
//    if(p0){
//        for (auto it= p0->begin();it!=p0->end();++it){
//            if(it->first->GetName() == "WheatField"  ||it->first->GetName() =="Bakery" )
//                Cbag.insert(make_pair(it->first,1));
//            else Cbag.insert(make_pair(it->first,0));
//
//        }
//
//    }
//    else{
//        for (auto it= d->begin();it!=d->end();++it){
//            if(it->first->GetName() == "WheatField"  ||it->first->GetName() =="Bakery" )
//                Cbag.insert(make_pair(it->first,1));
//            else Cbag.insert(make_pair(it->first,0));
//
//        }
//
//    }

}
bool Player::Iswon() {
    if(trainStation && shoppingMall && amusementPark && radioTower)  return true;
    else return false;
}
int Player::Show() {
    int i=0;
    cout<<endl;
    cout<<"Name:"<<P_Name<<"    money:"<<Money<<endl;
    for(auto it = Cbag.begin();it!=Cbag.end();++it){
        i++;cout<<i<<". ";
        cout<<it->first->GetName()<<":"<<it->second;
        cout<<endl;

    }
    if(trainStation==true ) cout<<++i<<". trainStation:open"<<endl; else cout<<++i<<". trainStation:close (cost:4)"<<endl;
    if(shoppingMall==true ) cout<<++i<<". shoppingMall:open"<<endl;else cout<<++i<<". shoppingMall:close (cost:10)"<<endl;
    if(amusementPark==true ) cout<<++i<<". amusementPark:open"<<endl;else cout<<++i<<". amusementPark:close (cost:16)"<<endl;
    if(radioTower==true ) cout<<++i<<". radioTower:open"<<endl;else cout<<++i<<". radioTower:close (cost:22)"<<endl;
    return i;
}

bool Player::RemoveCard(int i) {
    auto it = Cbag.begin();i--;
    while(i>0){
        i--;it++;
    }
    if (it->second==0) {cout<<"the number of "<<it->first->GetName()<<" is 0"<<endl; return false;}
    else {it->second--;
    cout<<this->GetPName()<<" lose the card :"<<it->first->GetName()<<endl;

    return true;}
}
bool Player::AddCard(int i) {
    auto it = Cbag.begin();i--;
    while(i>0){
        i--;it++;
    }
 it->second++;
    cout<<this->GetPName()<<" get the card :"<<it->first->GetName()<<endl;
    return true;

}
Player::~Player() {
//    for (auto it = Cbag.begin();it!=Cbag.end();++it){
//        delete it->first;
//    }
}


//*********************************************************EXP


bool EXPlayer::Iswon() {
    if(Player::Iswon() && Airport && Port ) return true;
    else return false;
}




EXPlayer::EXPlayer(Desk *d) {//已验证正常
    P_Name="";
    Money=3;
    trainStation= false;
    shoppingMall=false;
    amusementPark=false;
    radioTower=false;
    Port=false;
    Airport=false;
    //EXDesk*p0= dynamic_cast<EXDesk*>(d);
    Cbag.clear();
    for (auto it= d->begin();it!=d->end();++it){
        if(it->first->GetName() == "WheatField"  ||it->first->GetName() =="Bakery" )
        { Cbag.insert(make_pair(it->first,1));}
        else {Cbag.insert(make_pair(it->first,0)); }

    }

}

int EXPlayer::Show() {
    int i=Player::Show();
//    int i=0;
//    cout<<endl;
//    cout<<"Name:"<<P_Name<<"    money:"<<Money<<endl;
//    for(auto it = Cbag.begin();it!=Cbag.end();++it){
//        //cout<<"zhengqueshuchu";
//        i++;cout<<i<<". ";
//        cout<<it->first->GetName()<<":"<<it->second;
//        cout<<endl;
//
//    }


//    if(trainStation==true ) cout<<++i<<". trainStation:open"<<endl; else cout<<++i<<". trainStation:close (cost:4)"<<endl;
//    if(shoppingMall==true ) cout<<++i<<". shoppingMall:open"<<endl;else cout<<++i<<". shoppingMall:close (cost:10)"<<endl;
//    if(amusementPark==true ) cout<<++i<<". amusementPark:open"<<endl;else cout<<++i<<". amusementPark:close (cost:16)"<<endl;
//    if(radioTower==true ) cout<<++i<<". radioTower:open"<<endl;else cout<<++i<<". radioTower:close (cost:22)"<<endl;
    if(Port) cout<<++i<<" Port:open"<<endl;else cout<<++i<<". Port:close (cost:2)"<<endl;
    if(Airport ) cout<<++i<<" Airport:open"<<endl;else cout<<++i<<". Airport:close (cost:30)"<<endl;
    return i;

}