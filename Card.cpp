//
// Created by dell on 2022/11/3.
//

#include "Card.h"

void Card::SETCard(int Lroll, int Hroll, int Cost, int Value, int Num, Color color, Icon icon, bool Renovation,
                   string Name) {
    this->Lroll = Lroll;
    this->Hroll = Hroll;
    this->Cost = Cost;
    this->Value = Value;
    this->Num = Num;
    this->color = color;
    this->icon = icon;
    this->Renovation = Renovation;
    this->Name = Name;

}

void BlueCard::action(vector<Player *> v, Player *p1) {
    //cout<<"bluecard is achieved"<<endl;
    for (Player *p :v) {
        int x = 0, n = 0;
        n = p->GetCn(this);
        x = n * this->GetValue();
        p->deposit(x);
        if (x > 0) {
            cout << p->GetPName() << " get money : " << x << " coins. through the card : " << this->GetName() << endl;
        }
    }
}

//void BlueCard::action(Player *p1, Player *p2, Card *c1, Card *c2, int val) {
//    p1->deposit(this->GetValue());
//}
WheatField::WheatField() {
    this->Lroll = 1;
    this->Hroll = 1;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::wheat;
    this->Renovation = false;
    this->Name = "WheatField";
    //this->Description="All players will get one gold coin for each this they own,Icon::wheat";
}

Ranch::Ranch() {
    this->Lroll = 2;
    this->Hroll = 2;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::cow;
    this->Renovation = false;
    this->Name = "Ranch";
    //this->Description="All players will get one gold coin for each this they own,Icon::cow";
}

Forest::Forest() {
    this->Lroll = 5;
    this->Hroll = 5;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::gear;
    this->Renovation = false;
    this->Name = "Forest";
    //this->Description="All players will get one gold coin for each this they own,Icon::cow";
}

Mine::Mine() {
    this->Lroll = 9;
    this->Hroll = 9;
    this->Cost = 6;
    this->Value = 5;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::gear;
    this->Renovation = false;
    this->Name = "Mine";
}

Orchard::Orchard() {
    this->Lroll = 10;
    this->Hroll = 10;
    this->Cost = 3;
    this->Value = 3;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::wheat;
    this->Renovation = false;
    this->Name = "Orchard";
}


//**************************************************

void GreenCard::action(vector<Player *> v, Player *p1) {
    //cout<<"greencard is achieved"<<endl;
    int x = 0, n = 0, val = 0;
    n = p1->GetCn(this);
    if (p1->GetshoppingMall()) val = 1;
    x = n * (this->GetValue() + val);
    p1->deposit(x);
    if (x > 0) {
        cout << p1->GetPName() << " get money : " << x << " coins. through the card : " << this->GetName() << endl;
    }

}
//    int bonus = 0;
//    if (c1 != NULL) bonus = 1;
//    if (this->multiplier == Icon::none)
//    {
//        p1->deposit(this->GetValue() + bonus);
//    }
//    else
//    {
//        p1->deposit((this->GetValue() * val) + bonus);
//    }}

Bakery::Bakery() {
    this->Lroll = 2;
    this->Hroll = 3;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::store;
    this->Renovation = false;
    this->Name = "Bakery";
}

ConvenienceStore::ConvenienceStore() {
    this->Lroll = 4;
    this->Hroll = 4;
    this->Cost = 2;
    this->Value = 3;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::store;
    this->Renovation = false;
    this->Name = "ConvenienceStore";
}

CheeseFactory::CheeseFactory() {
    this->Lroll = 7;
    this->Hroll = 7;
    this->Cost = 5;
    this->Value = 3;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::factory;
    this->Renovation = false;
    this->Name = "CheeseFactory";

}

void CheeseFactory::action(vector<Player *> v, Player *p1) {
    //cout<<"chesse-action is achieved"<<endl;
    int x = 0, n = 0, m = 0;
    m = p1->GetCn(this);
    for (auto it = p1->begin(); it != p1->end(); ++it) {
        if (it->first->GetIcon() == Icon::cow) {
            n = it->second;
            x += this->GetValue() * n;
        }
    }
    p1->deposit(x * m);
    if (x * m > 0) {
        cout << p1->GetPName() << " get money : " << x * m << " coins. through the card : " << this->GetName() << endl;
    }

}

FurnitureFactory::FurnitureFactory() {
    this->Lroll = 8;
    this->Hroll = 8;
    this->Cost = 3;
    this->Value = 3;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::factory;
    this->Renovation = false;
    this->Name = "FurnitureFactory";

}

void FurnitureFactory::action(vector<Player *> v, Player *p1) {
    int x = 0, n = 0, m = 0;
    m = p1->GetCn(this);
    for (auto it = p1->begin(); it != p1->end(); ++it) {
        if (it->first->GetIcon() == Icon::gear) {
            n = it->second;
            x += this->GetValue() * n;
        }
    }
    p1->deposit(x * m);
    if (x * m > 0) {
        cout << p1->GetPName() << " get money : " << x * m << " coins. through the card : " << this->GetName() << endl;
    }

}

FruitAndVegetableMarket::FruitAndVegetableMarket() {
    this->Lroll = 11;
    this->Hroll = 12;
    this->Cost = 2;
    this->Value = 2;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::fruit;
    this->Renovation = false;
    this->Name = "FruitAndVegetableMarket";

}

void FruitAndVegetableMarket::action(vector<Player *> v, Player *p1) {
    //cout <<"fruit-action"<<endl;
    int x = 0, n = 0, m = 0;
    m = p1->GetCn(this);
    for (auto it = p1->begin(); it != p1->end(); ++it) {
        if (it->first->GetIcon() == Icon::wheat) {
            n = it->second;
            x += this->GetValue() * n;
        }
    }
    p1->deposit(x * m);
    if (x * m > 0) {
        cout << p1->GetPName() << " get money : " << x * m << " coins. through the card : " << this->GetName() << endl;
    }
}

//**************************************************
void RedCard::action(vector<Player *> v, Player *p1) {
    //cout<<"redcard-action is achieved"<<endl;
    int x = 0, n = 0, val = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if ((*it)->GetshoppingMall()) {
            val = 1;
            cout << (*it)->GetPName() << " you have shoppingmall card " << endl;
        }
//        for (auto itc=(*it)->begin();itc!=(*it)->end();++itc){
//            if (itc->first->GetIcon()==Icon::coffeeCup) {
//                n=itc->second;
//                x+=(itc->first->GetValue()+val)*n;
//            }
//        }
        n = (*it)->GetCn(this);
        x = (this->GetValue() + val) * n;
        int temp = 0;
        temp = p1->withdraw(x);
        if (temp > 0) {
            if (*it != p1) {
                cout << p1->GetPName() << " lose money : " << temp << " coins. through the card : " << this->GetName()
                     << endl;
                cout << (*it)->GetPName() << " get money : " << temp << " coins. through the card : " << this->GetName()
                     << endl;
            }
            (*it)->deposit(temp);
            if (p1->GetMoney() == 0) {
                cout << p1->GetPName() << " is a poor man, let him go" << endl;
                break;
            }
        }
        x = 0;
        n = 0;
        val = 0;
    }

}
//{
////    int bonus = 0;
////    if (c1 != NULL) bonus = 1;
////    p1->deposit(p2->withdraw(this->get_value()+bonus));
//}

Cafe::Cafe() {
    this->Lroll = 3;
    this->Hroll = 3;
    this->Cost = 2;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::red;
    this->icon = Icon::coffeeCup;
    this->Renovation = false;
    this->Name = "Cafe";
}

FamilyRestaurant::FamilyRestaurant() {
    this->Lroll = 9;
    this->Hroll = 10;
    this->Cost = 3;
    this->Value = 2;
    this->Num = 1;
    this->color = Color::red;
    this->icon = Icon::coffeeCup;
    this->Renovation = false;
    this->Name = "FamilyRestaurant";
}

//**************************************************
BusinessCenter::BusinessCenter() {
    this->Lroll = 6;
    this->Hroll = 6;
    this->Cost = 8;
    this->Value = 0;
    this->Num = 1;
    this->color = Color::purple;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "BusinessCenter";
}

void BusinessCenter::action(vector<Player *> v, Player *p1) {
    //cout<<"Businescenter-action "<<endl;
    int n = p1->GetCn(this);
    if (n > 0) {
        cout << p1->GetPName() << " you can exchange your card with others(cant't be the icon of tower) "
             << " through the card : " << this->GetName() << endl;
    }
    //cout<<"BBB"<<endl;
    while (n > 0) {
        int i, j;
        n--;
        cout << "Do you want to exchange?" << endl;
        cout << "1.YES         2.NO" << endl;
        cin >> i;
        if (i == 2) break;
        else {
            cout << "the palyer is:?";
            for (int i = 0; i < v.size(); ++i) {
                cout << i + 1 << ".";
                v[i]->Show();
                cout << endl;
            }
            cin >> j;
            cout << "the card is:?" << endl;
            cin >> i;
            while (!v[j - 1]->RemoveCard(i)) {
                cout << "Please re-enter" << endl;
                cout << "the palyer is:?" << endl;
                cin >> j;
                cout << "the card is:?" << endl;
                cin >> i;
            }
            p1->AddCard(i);
            cout << endl;
            do {
                cout << "what card you choose to lose " << endl;
                cout << "the card is:?" << endl;
                cin >> i;
            } while (!p1->RemoveCard(i));
            v[j - 1]->AddCard(i);


        }

    }

}


Stadium::Stadium() {
    this->Lroll = 6;
    this->Hroll = 6;
    this->Cost = 6;
    this->Value = 2;
    this->Num = 1;
    this->color = Color::purple;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "Stadium";
}

void Stadium::action(vector<Player *> v, Player *p1) {
    //cout<<"stadium-action"<<endl;
    int n = 0;
    n = p1->GetCn(this);
    for (auto it = v.begin(); it != v.end(); ++it) {
        int temp = 0;
        int x = 0;
        x = n * this->GetValue();
        temp = (*it)->withdraw(x);
        p1->deposit(temp);
        if (temp > 0) {
            cout << p1->GetPName() << " get money : " << temp << " coins. through the card : " << this->GetName() <<
                 " by " << (*it)->GetPName() << endl;
        }
    }

}
//    //p1->deposit(p2->withdraw(this->get_value()));
//}

TVStation::TVStation() {
    this->Lroll = 6;
    this->Hroll = 6;
    this->Cost = 7;
    this->Value = 5;
    this->Num = 1;
    this->color = Color::purple;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "TVStation";
}

void TVStation::action(vector<Player *> v, Player *p1) {
    //cout<<"TV-action"<<endl;
    int n = p1->GetCn(this);
    //cout<<"TV"<<endl;
    while (n > 0) {
        int i, j;
        n--;
        cout << "Do you want to get money from others ?" << endl;
        cout << "1.YES         2.NO";
        cin >> i;
        if (i == 2) break;
        else {
            cout << "the palyer is:?" << endl;
            for (int i = 0; i < v.size(); ++i) {
                cout << i + 1 << ".";
                v[i]->Show();
                cout << endl;
            }

            cin >> j;
            int temp = 0;
            temp = v[j - 1]->withdraw(5);
            p1->deposit(temp);
            if (temp > 0) {
                cout << p1->GetPName() << " get money : " << temp << "coins. through the card : " << this->GetName()
                     << endl;
            }
//            cout <<"the card is:?"<<endl;
//            cin>>i;
//            while(!v[j-1]->RemoveCard(i)){
//                cout<<"Please re-enter"<<endl;
//                cout <<"the palyer is:?"<<endl;
//                cin>>j;
//                cout <<"the card is:?"<<endl;
//                cin>>i;
            //}
            //p1->AddCard(i);


        }

    }


}
//    //p1->deposit(p2->withdraw(this->get_value()));
//}

//**************************************************

void YellowCard::action(vector<Player *> v, Player *p1) {}
//{
//    // Nothing to really do here yet because yellow cards dont perform actions in the same manner
//}

TrainStation::TrainStation() {
    this->Lroll = 0;
    this->Hroll = 0;
    this->Cost = 4;
    this->Value = 0;
    this->Num = 1;
    this->color = Color::yellow;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "TrainStation";
}

ShoppingMall::ShoppingMall() {
    this->Lroll = 0;
    this->Hroll = 0;
    this->Cost = 10;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::yellow;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "ShoppingMall";
}

AmusementPark::AmusementPark() {
    this->Lroll = 0;
    this->Hroll = 0;
    this->Cost = 16;
    this->Value = 0;
    this->Num = 1;
    this->color = Color::yellow;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "AmusementPark";
}

RadioTower::RadioTower() {
    this->Lroll = 0;
    this->Hroll = 0;
    this->Cost = 20;
    this->Value = 0;
    this->Num = 1;
    this->color = Color::yellow;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "RadioTower";
}

//****************************************************扩展包
Flowerfield::Flowerfield() {
    this->Lroll = 4;
    this->Hroll = 4;
    this->Cost = 2;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::wheat;
    this->Renovation = false;
    this->Name = "Flowerfield";

}

Mackerelboat::Mackerelboat() {
    this->Lroll = 8;
    this->Hroll = 8;
    this->Cost = 2;
    this->Value = 3;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::boat;
    this->Renovation = false;
    this->Name = "Mackerelboat";

}
void Mackerelboat::action(vector<Player *> v, Player *p1) {
    for (Player *p :v) {
        EXPlayer*p0= dynamic_cast<EXPlayer*>(p);
        int x = 0, n = 0;
        if(p0->GetPort()){
            n = p0->GetCn(this);
            x = n * this->GetValue();
            if (x > 0) {
                cout << p->GetPName() << " get money : " << x << " coins. through the card : " << this->GetName() << endl;
                p0->deposit(x);
            }
        }
        else cout<<p0->GetPName()<<" don't have a port yet, "<< this->GetName()<<" can't be executed"<<endl;


    }
    //EXPlayer*p0= dynamic_cast<EXPlayer*>(p1);
//    if(p0->GetPort()){
//
//    }
//    else cout<<"You don't have a port yet, this card can't be executed"<<endl;

}

Tunaboat::Tunaboat() {
    this->Lroll = 12;
    this->Hroll = 14;
    this->Cost = 5;
    this->Value = 0;
    this->Num = 1;
    this->color = Color::blue;
    this->icon = Icon::boat;
    this->Renovation = false;
    this->Name = "Tunaboat";
}
void Tunaboat::action(vector<Player *> v, Player *p1) {
    int t1,t2,x=0;
    t1 = getrandom();Sleep(1000);
    t2 = getrandom();
    cout << "first roll=" << t1 << "  " << "second roll=" << t2 << endl;
    x=t1+t2;
    cout << p1->GetPName() << " you roll the" <<x;
    for (Player *p :v) {
        EXPlayer*p0= dynamic_cast<EXPlayer*>(p);
        int  n = 0;x=t1+t2;
        if(p0->GetPort()){
            n = p0->GetCn(this);
            x = n * x;
            if (x > 0) {
                cout << p->GetPName() << " get money : " << x << " coins. through the card : " << this->GetName() << endl;
                p0->deposit(x);
            }
        }
        else cout<<p0->GetPName()<<" don't have a port yet, "<< this->GetName()<<" can't be executed"<<endl;


    }


}

Florist::Florist() {
    this->Lroll = 6;
    this->Hroll = 6;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::store;
    this->Renovation = false;
    this->Name = "Florist";

}

void Florist::action(vector<Player *> v, Player *p1) {
    int x = 0, n = 0, m = 0,val=0;
    m = p1->GetCn(this);if (p1->GetshoppingMall()) val = 1;
    for (auto it = p1->begin(); it != p1->end(); ++it) {
        if (it->first->GetName() == "Flowerfield") {
            n = it->second;
            x += (this->GetValue() +val)* n;
            break;
        }
    }
    p1->deposit(x * m);
    if (x * m > 0) {
        cout << p1->GetPName() << " get money : " << x * m << " coins. through the card : " << this->GetName() << endl;
    }

}

Foodmarket::Foodmarket() {
    this->Lroll = 12;
    this->Hroll = 13;
    this->Cost = 2;
    this->Value = 2;
    this->Num = 1;
    this->color = Color::green;
    this->icon = Icon::factory;
    this->Renovation = false;
    this->Name = "Foodmarket";

}
void Foodmarket::action(vector<Player *> v, Player *p1) {
    int x = 0, n = 0, m = 0;
    m = p1->GetCn(this);
    for (auto it = p1->begin(); it != p1->end(); ++it) {
        if (it->first->GetIcon() == Icon::coffeeCup) {
            n = it->second;
            x += this->GetValue() * n;
        }
    }
    p1->deposit(x * m);
    if (x * m > 0) {
        cout << p1->GetPName() << " get money : " << x * m << " coins. through the card : " << this->GetName() << endl;
    }

}

Hamburgershop::Hamburgershop() {
    this->Lroll = 8;
    this->Hroll = 8;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::red;
    this->icon = Icon::coffeeCup;
    this->Renovation = false;
    this->Name = "Hamburgershop";
}

Pizzeria::Pizzeria() {
    this->Lroll = 7;
    this->Hroll = 7;
    this->Cost = 1;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::red;
    this->icon = Icon::coffeeCup;
    this->Renovation = false;
    this->Name = "Pizzeria";

}

Sushibar::Sushibar() {
    this->Lroll = 1;
    this->Hroll = 1;
    this->Cost = 2;
    this->Value = 3;
    this->Num = 1;
    this->color = Color::red;
    this->icon = Icon::coffeeCup;
    this->Renovation = false;
    this->Name = "Sushibar";

}
void Sushibar::action(vector<Player *> v, Player *p1) {
    EXPlayer*p0= dynamic_cast<EXPlayer*>(p1);
    if(p0->GetPort()){
        int x = 0, n = 0, val = 0;
        for (auto it = v.begin(); it != v.end(); ++it) {
            if ((*it)->GetshoppingMall()) {
                val = 1;
                cout << (*it)->GetPName() << " you have shoppingmall card " << endl;
            }
//        for (auto itc=(*it)->begin();itc!=(*it)->end();++itc){
//            if (itc->first->GetIcon()==Icon::coffeeCup) {
//                n=itc->second;
//                x+=(itc->first->GetValue()+val)*n;
//            }
//        }
            n = (*it)->GetCn(this);
            x = (this->GetValue() + val) * n;
            int temp = 0;
            temp = p1->withdraw(x);
            if (temp > 0) {
                if (*it != p1) {
                    cout << p1->GetPName() << " lose money : " << temp << " coins. through the card : " << this->GetName()
                         << endl;
                    cout << (*it)->GetPName() << " get money : " << temp << " coins. through the card : " << this->GetName()
                         << endl;
                }
                (*it)->deposit(temp);
                if (p1->GetMoney() == 0) {
                    cout << p1->GetPName() << " is a poor man, let him go" << endl;
                    break;
                }
            }
            x = 0;
            n = 0;
            val = 0;
        }
    }
    else cout<<p0->GetPName()<<" don't have a port yet, "<< this->GetName()<<" can't be executed"<<endl;

}

Publisher::Publisher() {
    this->Lroll = 7;
    this->Hroll = 7;
    this->Cost = 5;
    this->Value = 1;
    this->Num = 1;
    this->color = Color::purple;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "Publisher";

}

void Publisher::action(vector<Player *> v, Player *p1) {
    int x = 0, n = 0, val = 0;
    int m = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
//        if((*it)->GetshoppingMall()){val=1;cout<<(*it)->GetPName()<<" you have shoppingmall card "<<endl; }
        for (auto itc = (*it)->begin(); itc != (*it)->end(); ++itc) {
            if (itc->first->GetIcon() == Icon::coffeeCup || itc->first->GetIcon() == Icon::store) {
                n = itc->second;
                x += (this->GetValue() + val) * n;
            }
        }
        m = p1->GetCn(this);
        x = x * m;
        int temp = 0;
        if ((*it) != p1) {
            temp = (*it)->withdraw(x);
            if (temp > 0) {

                cout << (*it)->GetPName() << " lose money : " << temp << " coins. through the card : "
                     << this->GetName() << endl;
                cout << p1->GetPName() << " get money : " << temp << " coins. through the card : " << this->GetName()
                     << endl;
                p1->deposit(temp);
//            if (p1->GetMoney()==0){
//                cout<<p1->GetPName()<<" is a poor man, let him go"<<endl;
//                //break;
//            }
            }
            x = 0;
            n = 0;
            val = 0;
            m = 0;
        }

    }

}

Taxoffice::Taxoffice() {
    this->Lroll = 8;
    this->Hroll = 9;
    this->Cost = 4;
    this->Value = 10;
    this->Num = 1;
    this->color = Color::purple;
    this->icon = Icon::tower;
    this->Renovation = false;
    this->Name = "Taxoffice";

}

void Taxoffice::action(vector<Player *> v, Player *p1) {
    int x = 0, n = 0, val = 0;
    int m = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if ((*it) != p1) {
            if ((*it)->GetMoney() >= 10) {
                int i = 0;
                x = 0;
                cout << (*it)->GetPName() << " has hte money: " << (*it)->GetMoney() << endl;
                cout << p1->GetPName() << " Are you willing to take half of his assets " << endl;
                cout << "1.YES        2.NO" << endl;
                cin >> i;
                if (i == 1) {
                    x = (*it)->GetMoney() / 2;
                    (*it)->withdraw(x);
                    cout << (*it)->GetPName() << " lose money : " << x << " coins. through the card : "
                         << this->GetName() << endl;
                    cout << p1->GetPName() << " get money : " << x << " coins. through the card : " << this->GetName()
                         << endl;
                    p1->deposit(x);
                }
            }

        }
    }
}