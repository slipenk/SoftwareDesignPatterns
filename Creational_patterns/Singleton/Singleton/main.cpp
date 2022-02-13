//
//  main.cpp
//  Singleton
//
//  Created by Yura Slipenkyi on 5/13/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>

using namespace std;

class Manager
{
    Manager()
    {
        cout << "Найняли!\n";
    }
public:
    static Manager * ManagerUnique;
    static Manager GetManager()
    {
        if(ManagerUnique == NULL)
        {
            ManagerUnique = new Manager();
        }
        return * ManagerUnique;
    }
};
Manager * Manager::ManagerUnique = NULL;

int main(void)
{
    for(int i = 0; i < 10; ++i)
    {
        Manager::GetManager();
    }
    return 0;
}

