//
//  main.cpp
//  Flyweight
//
//  Created by Yura Slipenkyi on 5/14/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Footballer_image
{
    static Footballer_image load(string path)
    {
        return Footballer_image();
    }
};

class Footballer
{
protected:
    string name;
    string surname;
    string state;
    int age;
    string club;
    int Price;
    Footballer_image picture;
};

class Factory_of_footballers
{
private:
    static map<string, Footballer_image> Images;
    static Factory_of_footballers ff;
    Factory_of_footballers()
    {
        Images["Salah"] = Footballer_image::load("Salah.jpg");
        Images["Mane"] = Footballer_image::load("Mane.jpg");
    }
public:
    static Footballer_image Create_Image_Salah()
    {
        return Images["Salah"];
    }
    static Footballer_image Create_Image_Mane()
    {
        return Images["Mane"];
    }
};
map<string, Footballer_image> Factory_of_footballers::Images;
Factory_of_footballers Factory_of_footballers::ff;

class Salah : public Footballer
{
public:
    Salah(string name, string surname, string state, int age, string club, int Price)
    {
        this->name = name;
        this->surname = surname;
        this->state = state;
        this->age = age;
        this->club = club;
        this->Price = Price;
        picture = Factory_of_footballers::Create_Image_Salah();
    }
};
class Mane : public Footballer
{
public:
    Mane(string name, string surname, string state, int age, string club, int Price)
    {
        this->name = name;
        this->surname = surname;
        this->state = state;
        this->age = age;
        this->club = club;
        this->Price = Price;
        picture = Factory_of_footballers::Create_Image_Mane();
    }
};
int main()
{
    cout<<"Початок..."<<endl;
    vector<Footballer *> s;
    vector<Footballer *> m;
    for (int i = 0; i < 12; i++)
    {
        s.push_back(new Salah("Мохаммед", "Салах", "Єгипет", 27, "Ліверпуль", 120000000));
    }
    for (int i = 0; i < 10; i++)
    {
        m.push_back(new Mane("Садіо", "Мане", "Сенегал", 28, "Ліверпуль", 120000000));
    }
    cout<<"Кінець!"<<endl;
}
