#include <iostream>
#include "Game.h"
/*void test(Desk * d){
    Player p(d);
    vector<Player*> v; v.push_back(&p);
   // p.RemoveCard(3);
    p.AddCard(1);
    auto it =p.begin();
    it->first->action(v,&p);
    it++;it++;
    it->first->action(v,&p);
    it++;it++;it++;it++;it++;
    it->first->action(v,&p);
    it++;it++;
    it->first->action(v,&p);
    it++;it++;
    it->first->action(v,&p);
    it++;
    it->first->action(v,&p);
    it++;
    it->first->action(v,&p);
    it++;
    it->first->action(v,&p);
    p.Show();
}*/
void test()
{

//Desk*x=new Desk;
//Player p(x);
    //p.Show();
//    Desk *d=new EXDesk;
//    d->showDeck();
//    Player p(d);
//    p.Show();
//    EXPlayer exp( d );
//    exp.Show();
Desk* d=new Desk;
    EXPlayer exp( d );
    exp.Show();

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    //test();
//Desk * d=new Desk;
//Player p(d);
//p.Show();
//test(d);
//cout<<endl;
//d->showDeck();
//  Desk d;
//  d.showDeck();
int i=0;
PlayGame *game=new PlayGame();
cin>>i;
if(i==1){ game->BaseVersion(1);  }
if(i==2){ game->EXVexsion(2);   }
    return 0;
}
