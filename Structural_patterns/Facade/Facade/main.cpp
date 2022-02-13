//
//  main.cpp
//  Facade
//
//  Created by Yura Slipenkyi on 5/14/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>

using namespace std;

class Footballer
{
private:
    string name;
public:
    Footballer(string name)
    {
        this->name = name;
    }
protected:
    void output(string text)
    {
        cout << this->name << ": " << text<< endl;
    }
};

class Origi : public Footballer
{
public:
    Origi(string name) : Footballer(name) {}
    void Score_first_goal()
    {
        output("тер Штеген відбиває, але прямо на ДІВОКАААААА ГОООООЛЛЛ!");
    }
    void Score_second_goal()
    {
        output("ОРІГІ ШВИДКО ЗМЕТИКУВАВ І ЗАБИВ 4 ГОЛ БАРСЕЛОНІ!!! ААААААА");
    }
};
class Wijnaldum : public Footballer
{
public:
    Wijnaldum(string name) : Footballer(name) {}
    void Changes_Robertson()
    {
        output("Виходить на заміну замість Робертсона");
    }
    void Jini_first_goal()
    {
        output("ГОООООООООЛ ВЕЙНАААЛДУУУУУММММММ  2:0!!!!! ");
    }
    void Jini_second_goal()
    {
        output("АААААААА!!!! ДЖІІІНІНІНІНІНІ! Неймовірний удар головою! ЦЕ 3:0");
    }
};
class Alexander_Arnold : public Footballer
{
public:
    Alexander_Arnold(string name) : Footballer(name) {}
    void First_asisst()
    {
        output("Простріл з правого флангу");
    }
    void Legendary_corner()
    {
        output("Corner taken quickly, ORIGIIII, YEAAHHAHHHH");
    }
};
class Shaq_Hendo : public Footballer
{
public:
    Shaq_Hendo(string name) : Footballer(name) {}
    void Hendo()
    {
        output("Гендо пробиваєєєє іі");
    }
    void  Shaq()
    {
        output("Шакірі подачаааа");
    }
};

class Facade_Liverpool
{
private:
    Origi* Divoc;
    Wijnaldum* Georginio;
    Alexander_Arnold* Trent;
    Shaq_Hendo* Xherdan_Jordan;
public:
    Facade_Liverpool()
    {
        Divoc = new Origi("Орігі");
        Georginio = new Wijnaldum("Вейналдум");
        Trent = new Alexander_Arnold("Александер-Арнольд");
        Xherdan_Jordan = new Shaq_Hendo("Шакірі й Гендерсон");
    }
    void Legendary_game()
    {
        Xherdan_Jordan->Hendo();
        Divoc->Score_first_goal();
        Georginio->Changes_Robertson();
        Trent->First_asisst();
        Georginio->Jini_first_goal();
        Xherdan_Jordan->Shaq();
        Georginio->Jini_second_goal();
        Trent->Legendary_corner();
        Divoc->Score_second_goal();
    }
};
int main()
{
    Facade_Liverpool* Klopp_gang = new Facade_Liverpool();
    Klopp_gang->Legendary_game();
}
