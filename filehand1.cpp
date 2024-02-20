#include <iostream>
#include <time.h>
using namespace std;

void fun()
{
    cout<<"Fun() start \n";
    cout<<"Press enter to stop fun() \n";
    while (1)
    {
        if (getchar())
        {
            break;
        }
    }
    cout<<"Fun() ends \n";
}

// main function here
