#include <iostream>
using namespace std;

void print_array(int row, int col, int d[][2])
{
    for (int i = 0; i < row; i++)
    {
        cout<<"[";
        for (int j = 0; j < col; j++)
        {
            cout<<" "<<d[i][j];
        }
        cout<<" ]"<<endl;
    }
    return;
}

int main()
{
    int a[2][2] = {
        {6, 7},
        {4, 5}
    };
    print_array(2, 2, a);
    return 0;
}