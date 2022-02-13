//
//  main.cpp
//  Strategy
//
//  Created by Yura Slipenkyi on 5/27/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>

using namespace std;

class Strategy_Tactic
{
public:
    virtual void SetTactic() = 0;
};

class Strategy_1: public Strategy_Tactic
{
public:
    void SetTactic(){
        cout << "Тактика: 4-3-3" << endl;
    }
};

class Strategy_2: public Strategy_Tactic
{
public:
    void SetTactic(){
        cout << "Тактика: 4-5-1" << endl;
    }
};

class Strategy_3: public Strategy_Tactic
{
public:
    void SetTactic(){
        cout << "Тактика: 4-4-2" << endl;
    }
};

class Strategy_4: public Strategy_Tactic
{
public:
    void SetTactic(){
        cout << "Тактика: 3-4-3" << endl;
    }
};

class Context
{
protected:
    Strategy_Tactic* object;
public:
    virtual void useTactic() = 0;
    virtual void setTactic(Strategy_Tactic* st) = 0;
};

class Client: public Context
{
public:
    void useTactic()
    {
        object->SetTactic();
    }
    
    void setTactic(Strategy_Tactic* o)
    {
        object = o;
    }
};

int main()
{
    Client I;
    Strategy_1 t1;
    Strategy_2 t2;
    Strategy_3 t3;
    Strategy_4 t4;
    
    I.setTactic(&t1);
    I.useTactic();
    I.setTactic(&t2);
    I.useTactic();
    I.setTactic(&t3);
    I.useTactic();
    I.setTactic(&t4);
    I.useTactic();
    
    return 0;
}
