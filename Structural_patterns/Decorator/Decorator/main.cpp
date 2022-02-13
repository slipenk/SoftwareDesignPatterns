//
//  main.cpp
//  Decorator
//
//  Created by Yura Slipenkyi on 5/13/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>
using namespace std;

class Stadium
{
public:
    virtual void Show() = 0;
};

class MinimumStadium : public Stadium
{
public:
    virtual void Show()
    {
        cout << "Стадіон \"Дін Курт\" у Борнмуті";
    }
};

class Decorator : public Stadium
{
private:
    Stadium * st;
public:
    Decorator(Stadium * s) : st(s) {}
    virtual void Show()
    {
        st->Show();
    }
};

class Сapacity : public Decorator
{
public:
    Сapacity(Stadium * s) : Decorator(s) {}
    virtual void Show()
    {
        Decorator::Show();
        cout << " збільшився за місткістю з 11,329 до 32,766";
    }
};
class HeatedSeats : public Decorator
{
public:
    HeatedSeats(Stadium * s) : Decorator(s) {}
    virtual void Show()
    {
        Decorator::Show();
        cout << " та обладнаний підігрівом сидінь!";
    }
};
int main()
{
    Stadium * s = new MinimumStadium;
    s->Show(); cout << endl;
    
    Stadium * sC = new Сapacity(s);
    sC->Show(); cout << endl;
    
    Stadium * sH = new HeatedSeats(sC);
    sH->Show(); cout << endl;
    
    
    
    return 0;
}

