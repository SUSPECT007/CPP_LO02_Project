//
// Created by dell on 2022/11/3.
//

#include "Function.h"

class Player;
int getrandom(){
    unsigned  seed;
    seed=time(0);srand(seed);
    int x ; x=rand()%6 +1;
    return x;
}


bool MyCompare::operator()(const Card * c1, const Card *c2) {
    if(c1->GetLroll()==c2->GetLroll()) return c1->GetCost()<c2->GetCost();
    else return c1->GetLroll()<c2->GetLroll();

}

vector<Card*> GetCard(int r,Desk*d){
    vector<Card*> v;int i=0;
    for(auto it=d->begin();it!=d->end();++it){
        if(r>=it->first->GetLroll()&&r<=it->first->GetHroll()){
            v[i]=(it->first);
        }
        i++;
    }

    return v;
}
void getcard(vector<Card*>&v,int r,Desk * d){
    for(auto it=d->begin();it!=d->end();++it){
        if(r>=it->first->GetLroll()&&r<=it->first->GetHroll()){
            v.push_back(it->first);
        }
    }

}