//
//  main.cpp
//  Prototype
//
//  Created by Yura Slipenkyi on 5/10/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>

using namespace std;

class Club
{
public:
    Club(){}
    Club(string Name, string Nickname, string Stadium, string Colors, string Manager);
    Club * clone();
    void print();
    string Name;
    string Nickname;
    string Stadium;
    string Colors;
    string Manager;
};
Club * Club::clone()
{
    Club * Best_Club = new Club;
    Best_Club->Name = this->Name;
    Best_Club->Nickname = this->Nickname;
    Best_Club->Stadium = this->Stadium;
    Best_Club->Colors = this->Colors;
    Best_Club->Manager = this->Manager;
    return Best_Club;
}
Club::Club(string Name, string Nickname, string Stadium, string Colors, string Manager)
{
    this->Name = Name;
    this->Nickname = Nickname;
    this->Stadium = Stadium;
    this->Colors = Colors;
    this->Manager = Manager;
}

void Club::print()
{
    cout << "Назва: " << this->Name << endl;
    cout << "Прізвисько: " << this->Nickname << endl;
    cout << "Стадіон: " << this->Stadium << endl;
    cout << "Колір: " << this->Colors << endl;
    cout << "Тренер: " << this->Manager << endl;
}

int main()
{
    Club * A = new Club("Ліверпуль", "Червоні", "Енфілд", "Червоний", "Юрген Клопп");
    A->print();
    cout<<endl;
    Club * B = A->clone();
    B->print();
    
    return 0;
}
