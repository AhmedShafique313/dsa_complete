#include <iostream>
#include <new>
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

int main()
{
    int c, *p;
    cout<<"How many columns?: ";
    cin>>c;

    p = new int [c];
    int k;
    cout<<"Enter numbers till you're done. "<<endl;
    for (int j = 0; j < c; j++)
    {
        cin>>k;
        *(p + j) = k;
    }
    cout<<"Your Matrix: "<<endl;
    print_array_ptr(1, c, p);
    delete [] p;
    return 0;
}