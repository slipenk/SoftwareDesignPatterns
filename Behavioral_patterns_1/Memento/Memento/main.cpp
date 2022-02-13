//
//  main.cpp
//  Memento
//
//  Created by Yura Slipenkyi on 5/26/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

class State {
public:
    int level;
    double money;
    State(int l, double m) : level(l), money(m){}
    void Show()
    {
        cout << "Рівень = " << level << ", гроші = " << money << endl;
    }
};

class Memento {
private:
    State * state;
public:
    Memento(State * _state)
    {
        state = _state;
    }
    State * GetState()
    {
        return state;
    }
};

class Originator {
private:
    State * state = new State(0, 0.0);
public:
    void Play()
    {
        state->Show();
        state = new State(state->level+1, (state->money + 200) * 3);
    }
    Memento * Save()
    {
        return new Memento(state);
    }
    void LoadGame(Memento * m)
    {
        state = m->GetState();
    }
};

class Caretaker {
private:
    Originator * game = new Originator();
    Memento * mementos;
    string path = "/Users/yuraslipenkyi/Desktop/MyBin.bin";
    ofstream fout;
    ifstream fin;
public:
    void Run()
    {
        game->Play();
    }
    void Save()
    {
        mementos = game->Save();
        fout.open(path);
        if(!fout.is_open())
        {
            cout << "Файл для запису не було відкрито!" << endl;
        }
        else
        {
        fout.write((char*)&mementos, sizeof(mementos));
        fout.close();
        }
    }
    void Load()
    {
        fin.open(path);
        if(!fin.is_open())
        {
            cout << "Файл для запису не було відкрито!" << endl;
        }
        else
        {
            fin.read((char*)&mementos, sizeof(mementos));
            game->LoadGame(mementos);
        }
        fin.close();
    }
};

int main()
{
    Caretaker G;
    G.Run();
    G.Save();
    G.Run();
    G.Run();
    G.Run();
    G.Load();
    G.Run();
    G.Run();
    G.Run();
    return 0;
}

