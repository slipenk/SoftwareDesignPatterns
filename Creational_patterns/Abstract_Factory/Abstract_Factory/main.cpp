//
//  main.cpp
//  Abstract_Factory
//
//  Created by Yura Slipenkyi on 5/10/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

class Tournament
{
protected:
    string name;
public:
    Tournament(string name)
    {
        this->name = name;
    }
};

class Trophy_UCL : public Tournament
{
public:
    Trophy_UCL() : Tournament("Трофей Ліги чемпіонів")
    {
        cout << this->name << endl;
    }
};
class Striker_UCL : public Tournament
{
public:
    Striker_UCL() : Tournament("Бомбардир Ліги чемпіонів")
    {
        cout << this->name << endl;
    }
};
class Trophy_UEL : public Tournament
{
public:
    Trophy_UEL() : Tournament("Трофей Ліги Європи")
    {
        cout << this->name << endl;
    }
};
class Striker_UEL : public Tournament
{
public:
    Striker_UEL() : Tournament("Бомбардир Ліги Європи")
    {
        cout << this->name << endl;
    }
};

class TournamentFactory
{
public:
    virtual Tournament * Get_Trophy() = 0;
    virtual Tournament * Get_Striker() = 0;
};

class UCL_Factory : TournamentFactory
{
public:
    virtual Tournament * Get_Trophy()
    {
        return new Trophy_UCL();
    }
    virtual Tournament * Get_Striker()
    {
        return new Striker_UCL();
    }
};

class UEL_Factory : TournamentFactory
{
public:
    virtual Tournament * Get_Trophy()
    {
        return new Trophy_UEL();
    }
    virtual Tournament * Get_Striker()
    {
        return new Striker_UEL();
    }
};

int main()
{
    UCL_Factory A;
    A.Get_Trophy();
    A.Get_Striker();
    
    UEL_Factory B;
    B.Get_Trophy();
    B.Get_Striker();
    
    return 0;
}

