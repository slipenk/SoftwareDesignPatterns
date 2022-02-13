//
//  main.cpp
//  Thread_safe_ singleton
//
//  Created by Yura Slipenkyi on 5/13/20.
//  Copyright © 2020 Yura Slipenkyi. All rights reserved.
//

#include <iostream>
#include <pthread.h>

#define threads_number 10

using namespace std;

class Manager
{
    Manager()
    {
        cout << "Найняли!\n";
    }
public:
    static Manager * ManagerUnique;
    static pthread_mutex_t mutex;
    static void * GetManager(void *)
    {
        pthread_mutex_lock(&mutex);
        if(ManagerUnique == NULL)
        {
            ManagerUnique = new Manager();
        }
        pthread_mutex_unlock(&mutex);
        return ManagerUnique;
    }
};
Manager * Manager::ManagerUnique = NULL;
pthread_mutex_t Manager::mutex = PTHREAD_MUTEX_INITIALIZER;



int main(void)
{
    pthread_t *threads = new pthread_t[threads_number];
    pthread_attr_t *threads_att = new pthread_attr_t[threads_number];
    for (int i = 0; i < threads_number; ++i)
    {
        pthread_attr_init(&threads_att[i]);
        pthread_create(&threads[i], &threads_att[i], Manager::GetManager, NULL);
    }
        
    for (int i = 0; i < threads_number; ++i)
    {
        pthread_join(threads[i], 0);
    }
    
    delete [] threads;
    delete [] threads_att;

    return 0;
}
