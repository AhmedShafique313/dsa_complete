#include <iostream>
#include <time.h>
using namespace std;

void fun(){

    cout<<"Fun() start \n";
    
    while (1)
    {
        if (getchar())
        {
        }    
    }    
    
   cout<<"Fun() ends \n";
}

// main function here
int main()
{
    clock_t t1,t2;
    t1 = clock();
    fun();
    t2 = clock() - t1;
    double time_taken = ((double) t2) / CLOCKS_PER_SEC;
    cout<<"fun() took of seconds to execute \n"<<time_taken;
    return 0;
}