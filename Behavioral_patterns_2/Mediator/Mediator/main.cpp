//
//  main.cpp
//  Mediator
//
//  Created by Yura Slipenkyi on 5/27/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Player;

class Mediator
{
public:
    virtual void Processing(string text, Player *f) = 0;
};
class Player
{
protected:
    Mediator* mediator;
public:
     Player(Mediator *mediator) :mediator(mediator) {}
};


class Player1 : public Player
{
public:
    Player1 (Mediator* mediator) :Player(mediator) {}
    void Send(string  message)
    {
        mediator->Processing(message, this);
    }
    void Notification(string  message)
    {
        cout << "Перший гравець отримав повідомлення: " << message<< endl;
    }
};
class Player2 :public Player
{
public:
    Player2(Mediator *mediator) : Player(mediator) {}
    void Send(string  message)
    {
        mediator->Processing(message, this);
    }
    void Notification(string  message)
    {
        cout << "Другий гравець отримав повідомлення: " << message << endl;
    }
};
class ConcreteMediator :public Mediator
{
protected:
    Player1 * player1;
    Player2 * player2;
public:
    void SetPlayer1(Player1 * u)
    {
        player1 = u;
    }
    void SetPlayer2(Player2 *u)
    {
        player2 = u;
    }
    virtual void Processing(string message, Player * player)
    {
        if (player == player1)
        {
            player2->Notification(message);
        }
        else if (player == player2)
        {
            player1->Notification(message);
        }
    }
};
int main()
{
    ConcreteMediator m;
    Player1 f1(&m);
    Player2 f2(&m);
    m.SetPlayer1(&f1);
    m.SetPlayer2(&f2);
    f1.Send("You'll Never");
    f2.Send("Walk Alone!");
    return 0;
}
