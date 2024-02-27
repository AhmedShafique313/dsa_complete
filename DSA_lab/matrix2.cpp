// A = p + (I x C) + J
// where j = index, p = base, I = row, C = column

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
    int r, c, *p;
    cout<<"Rows?: ";cin>>r;cout<<endl;
    cout<<"Columns?: ";cin>>c;cout<<endl;
    p = new int [r*c];
    int k;
    cout<<"Enter the numbers till you're done..."<<endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>k;
            *(p+i*c + j)= k;
        }
    }
    cout<<"Your matrix: "<<endl;
    print_array_ptr(r, c, p);
    delete [] p;
    return 0;
}