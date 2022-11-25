//
// Created by dell on 2022/11/3.
//

#include "Game.h"

Desk::Desk() {

    Card *c;

    c = new Cafe();
    deck[c] = 6;
    c = new FamilyRestaurant();
    deck[c] = 6;

    c = new WheatField();
    deck[c] = 6;
    c = new Ranch();
    deck[c] = 6;
    c = new Forest();
    deck[c] = 6;
    c = new Mine();
    deck[c] = 6;
    c = new Orchard();
    deck[c] = 6;

    c = new Bakery();
    deck[c] = 6;
    c = new ConvenienceStore();
    deck[c] = 6;
    c = new CheeseFactory();
    deck[c] = 6;
    c = new FurnitureFactory();
    deck[c] = 6;
    c = new FruitAndVegetableMarket();
    deck[c] = 6;


    c = new BusinessCenter();
    deck[c] = 4;
    c = new TVStation();
    deck[c] = 4;
    c = new Stadium();
    deck[c] = 4;

}

void Desk::showDeck(ostream &f) {
    int i = 0;
    cout<<endl;
    cout<<"show the card"<<endl;
    for (auto it = deck.begin(); it != deck.end(); ++it) {
        i++;
        cout << i << ". ";
        f << it->first->GetName() << ":" << it->second << "(num)  " << "cost:" << it->first->GetCost() << endl;
    }
    cout<<endl;
    cout<<endl;
}

void Desk::change(Card *c) {
    auto it = deck.find(c);
    if (it->second == 0) {
        cout << c->GetName() << ":number is 0 .Please select another card" << endl;
    } else it->second--;
}

bool Desk::RemoveCard(int i, Player &p) {
    auto it = deck.begin();
    i--;
    while (i > 0) {
        i--;
        it++;
    }
    if (it->second == 0) {
        cout << "the number of " << it->first->GetName() << " is 0" << endl;
        return false;
    } else {
        if (p.GetMoney() >= it->first->GetCost()) {
            it->second--;
            p.withdraw(it->first->GetCost());
            return true;
        } else {
            cout << "You don't have enough money" << endl;
            return false;
        }
    }

}
//void Desk::GetDescription() {
//    int i=0;
//    for(auto it = deck.begin();it!=deck.end();++it){
//        i++;
//        cout<<i<<". ";
//        cout<<it->first->GetName()<<"  roll:"<<it->first->GetLroll()<<"-"<<it->first->GetHroll();
//
//
//
//    }
//}
EXDesk::EXDesk()//:Desk()
{
    Card *c;
    deck.clear();
    c = new Cafe();
    deck[c] = 6;
    c = new FamilyRestaurant();
    deck[c] = 6;
    c= new Hamburgershop();
    deck[c] = 6;
    c= new Pizzeria();
    deck[c] = 6;
    c= new Sushibar();
    deck[c] = 6;


    c = new WheatField();
    deck[c] = 6;
    c = new Ranch();
    deck[c] = 6;
    c = new Forest();
    deck[c] = 6;
    c = new Mine();
    deck[c] = 6;
    c = new Orchard();
    deck[c] = 6;
    c = new Flowerfield();
    deck[c] = 6;
    c = new Mackerelboat();
    deck[c] = 6;
    c = new Tunaboat();
    deck[c] = 6;


    c = new Bakery();
    deck[c] = 6;
    c = new ConvenienceStore();
    deck[c] = 6;
    c = new CheeseFactory();
    deck[c] = 6;
    c = new FurnitureFactory();
    deck[c] = 6;
    c = new FruitAndVegetableMarket();
    deck[c] = 6;
    c = new Florist();
    deck[c] = 6;
    c = new Foodmarket();
    deck[c] = 6;

    c = new BusinessCenter();
    deck[c] = 4;
    c = new TVStation();
    deck[c] = 4;
    c = new Stadium();
    deck[c] = 4;
    c = new Publisher();
    deck[c] = 4;
    c = new Taxoffice();
    deck[c] = 4;

}

PlayGame::PlayGame() {
//     Desk::getinstance();
    //Desk *d = new Desk();
//cout <<"look";
    d=new Desk ;
    cout<<"You can choose the version"<<endl;
    cout<<"1. Standard version          2. Port expansion version"<<endl;

}
void PlayGame::chosse(int i) {
    if(i==1) {cout<<"You have selected the standard version and loaded the game"<<endl;}
    else if(i==2){cout<<"You have selected the extended version, and the game is loaded"<<endl;
    d= new EXDesk;
    }
}
void PlayGame::start(int version ) {
    cout << "Please enter the number of real players and AI(No more than four in total)" << endl;
    bool Ngo = false;
    while (!Ngo) {
        cout << "number of real players:" << endl;
        cin >> p_num;
        cout << "number of AI:" << endl;
        cin >> ai_num;
        if (p_num + ai_num < 2||p_num + ai_num>4) cout << "Wrong number of people!Please re-enter" << endl;
        else Ngo = true;
    }
    //Player t(d);
    //person.resize(p_num + ai_num,new Player(d));
    string temp;
    for (int i = 0; i < p_num; i++) {
        //person[i]=(new Player(d));
        temp="";
        //Player t(d);
        if(version==1){
        person.push_back(new Player(d));}
        if(version==2){
            person.push_back(new EXPlayer(d));}
        cout << i + 1 << "th player's name: " << endl;
        cin >> temp; // t.SETName(temp);
        person[i]->SETName(temp);
        person[i]->Show();


    }
    for (int i = p_num; i < p_num + ai_num; i++) {
        if(version==1){
            person.push_back(new Player(d));}
        if(version==2){
            person.push_back(new EXPlayer(d));}
        temp = "AI";
        temp += to_string(i - p_num + 1);
        person[i]->SETName(temp);
        cout << "the AI's name: " << person[i]->GetPName() << endl;
        //cin>>temp; person[i]->SETName(temp);
    }
    //aip.resize(ai_num,new AI());
}
void PlayGame::roll(const Player &p) {
    int t = 1, t1, t2;
    cout<<"roll begin "<<endl;
    if (p.GettrainStation()) {
        cout<<"you build trainStation, can shoose the number of dice"<<endl;
        cout << "How many dice do you want? " << endl;
        cout << "1.one  2.two" << endl;
        cin >> t;
        t1 = getrandom();Sleep(1000);
        t2 = (t - 1) * getrandom();
        cout << "first roll=" << t1 << "  " << "second roll=" << t2 << endl;
        touzi = t1 + t2;
        cout << p.GetPName() << " you roll the" << touzi;
    } else {
        touzi = getrandom();
        cout << p.GetPName() << " you roll the " << touzi;
    }
    if (p.GetradioTower()) {
        cout<<"you build radioTower"<<endl;
        cout << "You have a chance to roll the dice again. Do you want to use it? " << endl;
        cout << "1.YES      2.NO" << endl;
        int i;
        cin >> i;
        if (i == 1) {
            if (p.GettrainStation()) {
                cout << "How many dice do you want? " << endl;
                cout << "1.one  2.two" << endl;
                cin >> t;
                t1 = getrandom();Sleep(1000);
                t2 = (t - 1) * getrandom();
                cout << "first roll=" << t1 << "  " << "second roll=" << t2 << endl;
                touzi = t1 + t2;
                cout << p.GetPName() << "you roll the" << touzi<<endl;
            } else {
                touzi = getrandom();
                cout << p.GetPName() << "you roll the" << touzi<<endl;
            }
        }

    }
    if (p.GetamusementPark()) {
        if (t1 == t2) Newturn = true; else Newturn = false;
    } else Newturn = false;

    cout<<endl;
    cout<<"roll end"<<endl;
}

void PlayGame::rollext( Player *p) {
    EXPlayer* p0= dynamic_cast<EXPlayer*>(p);
    if(p0->GetPort()){
        cout<<p->GetPName()<<" have Port ."
                             "Do you want to add 2 to your dice?"<<endl;
        cout<<"1.YES      2.NO"<<endl;
        int i=0;cin>>i;
        if(i==1) touzi+=2;
    }

}
void PlayGame::Income(Player &p) {
    //cout<<"1.run"<<endl;
    cout<<"Do action of cards"<<endl;
    vector<Card *> v ;
    //cout<<"2.run"<<endl;
    //v= GetCard(touzi, d);
    //getcard(v,touzi,d);
    //v.resize(5);
    //v[0]=new WheatField();
    //auto it=
            //d->begin();
    //cout<<"3.run"<<endl;
    //v= GetCard(touzi, d);
    //int i=0;
    for(auto it=d->begin();it!=d->end();++it){
        if(touzi>=it->first->GetLroll()&&touzi<=it->first->GetHroll()){
            v.push_back(it->first);
        }

    }
   // v= GetCard(touzi, d);
    //cout<<"4.run"<<endl;
    for (int i = 0; i < v.size(); i++) {
        //cout<<"5.run"<<endl;
        v[i]->action(person, &p);
        //cout<<"6.run"<<endl;
    }
    //cout<<"7.run"<<endl;
    v.clear();
    cout<<"action of cards over"<<endl;
    cout<<endl;
    //cout<<"8.run"<<endl;
//    for(auto it=p.begin();it!=p.end();it++ ){
//        if(it->second!=0&&it->first->GetLroll()<=touzi&&it->first->GetHroll()>=touzi){
//            it->first->action(&p);
//        }
}
void PlayGame::Buy(Player &p,int version) {
    d->showDeck();
    int a= p.Show();int ex=0;
    //if(version==1) {ex=4;} else ex=6;
    cout << "Select the building you want to build(if nothing want to buy : enter 666)" << endl;
    cout << "if you want to know the description of card enter 0" << endl;
    int i = 0;
    bool f = true;
    while (f) {
        cout << "Select the building you want to build" << endl;
        cin >> i;
        if (i >19) {
            f = false;
            cout<<"nothing build"<<endl;
            break;
        }
        if (i == 0) {
            //descriotion
            cout << "Select the building you want to build" << endl;
            cin >> i;
        }
        if (i >= 16 && i <= 19) {
            if (i == 16) {
                if (p.GetMoney() >= 4) {
                    p.SetTrainStation(true);
                    p.withdraw(4);
                    cout<<p.GetPName()<<" build the radioTower"<<endl;
                    f = false;
                } else { cout << "You don't have enough money" << endl; }
            }
            if (i == 17) {
                if (p.GetMoney() >= 10) {
                    p.SetShoppingMall(true);
                    p.withdraw(10);
                    f = false;
                    cout<<p.GetPName()<<" build the shoppingMall"<<endl;
                } else { cout << "You don't have enough money" << endl; }
            }
            if (i == 18) {
                if (p.GetMoney() >= 16) {
                    p.SetAmusementPark(true);
                    p.withdraw(16);
                    f = false;
                    cout<<p.GetPName()<<" buy the AmusementPark"<<endl;
                } else { cout << "You don't have enough money" << endl; }
            }
            if (i == 19) {
                if (p.GetMoney() >= 22) {
                    p.SetRadioTower(true);
                    p.withdraw(22);
                    cout<<p.GetPName()<<" build the RadioTower"<<endl;
                    f = false;
                }
                else { cout << "You don't have enough money" << endl; }
            }
//            if (i == a+5) {
//                if (p.GetMoney() >= 22) {
//                    p.SetRadioTower(true);
//                    p.withdraw(22);
//                    cout<<p.GetPName()<<" build the RadioTower"<<endl;
//                    f = false;
//                }
//                else { cout << "You don't have enough money" << endl; }
//            }
//            if (i == a+6) {
//                if (p.GetMoney() >= 22) {
//                    p.SetRadioTower(true);
//                    p.withdraw(22);
//                    cout<<p.GetPName()<<" build the RadioTower"<<endl;
//                    f = false;
//                }
//                else { cout << "You don't have enough money" << endl; }
//            }

        } else if (i != 0&&f) {
            while (!d->RemoveCard(i, p)) {
                cout << "Select the building you want to build" << endl;
                cin >> i;
            }

            p.AddCard(i);
            f = false;
        }
    }


}
void PlayGame::B_G(Player *p, int version) {
    if(!p->GetamusementPark()){p->SetAmusementPark(false);}
    if(!p->GetshoppingMall()){person[0]->SetShoppingMall(false);}
    if(!p->GetradioTower()){person[0]->SetRadioTower(false);}
    if(!p->GettrainStation()){ person[0]->SetTrainStation(false);}
    bool a1=p->GetamusementPark(),b1=p->GetshoppingMall(),c1=p->GetradioTower(),d1=p->GettrainStation();
    EXPlayer* p0= dynamic_cast<EXPlayer*>(p);
    d->showDeck();
    int a= p->Show();int ex=0;
    //if(version==1) {ex=4;} else ex=6;
    cout << "Select the building you want to build(if nothing want to buy : enter 666)" << endl;
    cout << "if you want to know the description of card enter 0" << endl;
    int i = 0;
    bool f = true;
    while (f) {
        cout << "Select the building you want to build" << endl;
        cin >> i;
        if (i >31) {
            f = false;
            cout<<"nothing build"<<endl;
            break;
        }
        if (i == 0) {
            //descriotion
            cout << "Select the building you want to build" << endl;
            cin >> i;
        }
        if (i >= 26 && i <= 31) {
            if (i == 26) {
                if (p->GetMoney() >= 4) {
                    p->SetTrainStation(true);
                    p->withdraw(4);
                    cout<<p->GetPName()<<" build the radioTower"<<endl;
                    f = false;
                } else { cout << "You don't have enough money" << endl; }
            }
            if (i == 27) {
                if (p->GetMoney() >= 10) {
                    p->SetShoppingMall(true);
                    p->withdraw(10);
                    f = false;
                    cout<<p->GetPName()<<" build the shoppingMall"<<endl;
                } else { cout << "You don't have enough money" << endl; }
            }
            if (i == 28) {
                if (p->GetMoney() >= 16) {
                    p->SetAmusementPark(true);
                    p->withdraw(16);
                    f = false;
                    cout<<p->GetPName()<<" buy the AmusementPark"<<endl;
                } else { cout << "You don't have enough money" << endl; }
            }
            if (i == 29) {
                if (p->GetMoney() >= 22) {
                    p->SetRadioTower(true);
                    p->withdraw(22);
                    cout<<p->GetPName()<<" build the RadioTower"<<endl;
                    f = false;
                }
                else { cout << "You don't have enough money" << endl; }
            }
            if (i == 30) {
                if (p->GetMoney() >= 2) {
                    p0->SetPortA(true);
                    p->withdraw(2);
                    cout<<p->GetPName()<<" build the Port"<<endl;
                    f = false;
                }
                else { cout << "You don't have enough money" << endl; }
            }
            if (i == 31) {
                if (p->GetMoney() >= 30) {
                    p0->SetAirport(true);
                    p->withdraw(22);
                    cout<<p->GetPName()<<" build the Airport"<<endl;
                    f = false;


                }
                else { cout << "You don't have enough money" << endl; }
            }

        } else if (i != 0&&f) {
            while (!d->RemoveCard(i, *p)) {
                cout << "Select the building you want to build" << endl;
                cin >> i;
            }

            p->AddCard(i);
            f = false;

        }
    }

p->SetAmusementPark(a1);
 person[0]->SetShoppingMall(b1);
   person[0]->SetRadioTower(c1);
 person[0]->SetTrainStation(d1);

}

void PlayGame::AIroll(Player &p) {
    cout<<"roll begin"<<endl;
    int t = 1, t1, t2;
    if (p.GettrainStation()) {
        cout << "How many dice do you want? " << endl;
        cout << "1.one  2.two" << endl;
        cout << "2" << endl;
//        cin >> t;
        t = 2;
        t1 = getrandom(); Sleep(1000);
        t2 = (t - 1) * getrandom();
        cout << "first roll=" << t1 << "  " << "second roll=" << t2 << endl;
        touzi = t1 + t2;
        cout << p.GetPName() << " you roll the " << touzi;
    } else {
        touzi = getrandom();
        cout << p.GetPName() << " you roll the " << touzi;
    }
    if (p.GetradioTower()) {
        cout << "You have a chance to roll the dice again. Do you want to use it? " << endl;
        cout << "1.YES      2.NO" << endl;
        cout << "2.NO" << endl;
        int i = 2;
//        cin >> i;
//        if (i == 1) {
//            if (p.GettrainStation()) {
//                cout << "How many dice do you want? " << endl;
//                cout << "1.one  2.two" << endl;
//                cin >> t;
//                t1 = getrandom();
//                t2 = (t - 1) * getrandom();
//                cout << "first roll=" << t1 << "  " << "first roll=" << t1 << endl;
//                touzi = t1 + t2;
//                cout << p.GetPName() << "you roll the" << touzi;
//            } else {
//                touzi = getrandom();
//                cout << p.GetPName() << "you roll the" << touzi;
//            }
//        }
    }
    if (p.GetamusementPark()) {
        if (t1 == t2) Newturn = true;
        else Newturn = false;
    }
    else Newturn=false;
    cout<<endl;
cout<<"roll end "<<endl;
}
int PlayGame::AIbuy(Player &p) {
    d->showDeck();
    p.Show();
    cout << "Select the building you want to build(if nothing want to buy : enter 666)" << endl;
    cout << "if you want to know the description of card enter 0" << endl;
    int i = 0;
    if (p.GetMoney() > 21) {
        if (p.GetMoney() >= 4 && !p.GettrainStation()) {
            p.SetTrainStation(true);
            p.withdraw(4);
            cout<<p.GetPName()<<" build the TrainStation"<<endl;
            return 0;
        }
        if (p.GetMoney() >= 10 && !p.GetshoppingMall()) {
            p.SetShoppingMall(true);
            p.withdraw(10);
            cout<<p.GetPName()<<" build the shoppingMall"<<endl;
            return 0;
        }
        if (p.GetMoney() >= 16 && !p.GetamusementPark()) {
            p.SetAmusementPark(true);
            p.withdraw(16);
            cout<<p.GetPName()<<" build the amusementPark"<<endl;

            return 0;
        }
        if (p.GetMoney() >= 22 && !p.GetradioTower()) {
            p.SetRadioTower(true);
            p.withdraw(22);
            cout<<p.GetPName()<<" build the radioTower"<<endl;
            return 0;
        }
    } else {
        for (auto it = d->begin(); it != d->end(); ++it) {
            i++;
            if (p.GetMoney() >= it->first->GetCost() && it->second > 0) {
                d->RemoveCard(i, p);
                p.AddCard(i);
                cout<<p.GetPName()<<" build the "<<it->first->GetName()<<endl;
                return 0;
            }
        }
//            while (!d->RemoveCard(i)) {
//                cout << "Select the building you want to build" << endl;
//                cin >> i;
//            }
//            p.AddCard(i);

    } return 0;
}
void PlayGame::endturn() {
    this-> Newturn = true;

}
bool PlayGame::over(Player & p) {
    if (p.Iswon()){
        winer=p.GetPName();
        return true;
    } else return false;

}
void PlayGame::guanjun() {
    cout<<"Congratulations on "<<winer<<" is winning the championship !!!"<<endl;

}
void PlayGame::BaseVersion(int ver) {
    cout << "         Welcome to Machi Koro and become the most successful person!!!"<<endl;
    this->chosse(ver);
    this->start(ver);
    system("pause");
    system("cls");
    while (1) {
        for (int i = 0; i < p_num; i++) {
            while (Newturn) {
                this->roll(*person[i]);
                system("pause");
                this->Income(*person[i]);
                system("pause");
                this->Buy(*person[i]);
                system("pause");

                if (this->over(*person[i])) { break; }
            }
            this->endturn();
            system("cls");

        }
        if (winer != "") { break; }

        for (int i = p_num; i < p_num + ai_num; i++) {
            while (Newturn) {
                this->AIroll(*person[i]);
                //system("pause");
                this->Income(*person[i]);
                system("pause");
                this->AIbuy(*person[i]);
                system("pause");
                if (this->over(*person[i])) { break; }
            }
            this->endturn();
            system("cls");
        }
        if (winer != "") { break; }
    }
this->guanjun();

}
void PlayGame::EXVexsion(int ver) {
    cout << "         Welcome to Machi Koro and become the most successful person!!!"<<endl;
    this->chosse(ver);
    this->start(ver);
    system("pause");
    system("cls");
    while (1) {
        for (int i = 0; i < p_num; i++) {
            while (Newturn) {
                this->roll(*person[i]);
                this->rollext(person[i]);
                system("pause");
                this->Income(*person[i]);
                system("pause");
                this->B_G(person[i],ver);
                system("pause");
                /*person[0]->SetShoppingMall(true);
                person[0]->SetRadioTower(true);
                person[0]->SetAmusementPark(true);
                person[0]->SetTrainStation(true);
                person[0]->deposit(200);*/
                if (this->over(*person[i])) { break; }
            }
            this->endturn();
            system("cls");

        }
        if (winer != "") { break; }

        for (int i = p_num; i < p_num + ai_num; i++) {
            while (Newturn) {
                this->AIroll(*person[i]);
                //system("pause");
                this->Income(*person[i]);
                system("pause");
                this->AIbuy(*person[i]);
                system("pause");
                if (this->over(*person[i])) { break; }
            }
            this->endturn();
            system("cls");
        }
        if (winer != "") { break; }
    }
    this->guanjun();
}
