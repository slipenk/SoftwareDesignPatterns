//
//  main.cpp
//  Command
//
//  Created by Yura Slipenkyi on 5/27/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Command
{
public:
    virtual void Choose() = 0;
};

class ChoosePosition : public Command
{
public:
    string position;
    ChoosePosition(string p)
    {
        position = p;
    }
    virtual void Choose()
    {
        cout << "Обрана позиція: " << position << endl;
    }
};
class ChoosePrice : public Command
{
public:
    string price;
    ChoosePrice(string p)
    {
        price = p;
    }
    virtual void Choose()
    {
        cout << "Обрана цінова категорія: " << price << endl;
    }
};
class ChooseClub : public Command
{
public:
    string club;
    ChooseClub(string c)
    {
        club = c;
    }
    virtual void Choose()
    {
        cout << "Обраний клуб: " << club << endl;
    }
};

class ChooseFootballer : public Command
{
public:
    string footballer;
    ChooseFootballer(string f)
    {
        footballer = f;
    }
    virtual void Choose()
    {
        cout << "Обраний футболіст: " << footballer << endl;
    }
};

class Purchase : public Command
{
public:
    virtual void Choose()
    {
        cout << "Покупка успішна!";
    }
};

class TransferMarket
{
private:
    vector<Command*> v;
public:
    void AddCommands(Command* c)
    {
        v.push_back(c);
    }
    void RunCommands()
    {
        auto it = v.begin();
        while (it != v.end())
        {
            (*it++)->Choose();
        }
    }
};

int main()
{
    TransferMarket market;
    market.AddCommands(new ChoosePosition("Нападник"));
    market.AddCommands(new ChoosePrice("64 млн євро"));
    market.AddCommands(new ChooseClub("РБ Лейпциг"));
    market.AddCommands(new ChooseFootballer("Тімо Вернер"));
    market.AddCommands(new Purchase());
    market.RunCommands();
    return 0;
}

