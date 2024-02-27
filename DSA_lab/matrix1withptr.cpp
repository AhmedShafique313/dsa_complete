#include <iostream>
using namespace std;

void print_array_ptr(int row, int col, int *ptr)
{
    for (int i = 0; i < row; i++)
    {
       cout<<"[";
       for(int j=0; j<col; j++)
       {
            cout<<" "<< *ptr;
            ptr = ptr + 1;
       } 
       cout<<" ]"<<endl;
    }
}

int main ()
{
    int a[3][4] = {
        {1,2,3,5},
        {6,5,3,6},
        {4,8,9,8}
    };
    print_array_ptr(3, 4, &a[0][0]);
    return 0;
}