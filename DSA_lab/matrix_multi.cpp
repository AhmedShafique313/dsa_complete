// row1 of matrix one should be equals to column of matrix two

#include <iostream>
#include <new>
using namespace std;

struct element
{
    int c, r;
    long long *p;
};

void intialize(int row, int col, int *ptr)
{
    int k=0;
    for(int i=0;i<row;i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>k;
            *(ptr + i*col + j) = k;
        }
    }
    return;
}

element matrices_multiplication(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    if (c1 == r2)
    {
        matrix.c = c1;
        matrix.r = r1;
        matrix.p = new long long [r1*c2];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                long long sum = 0;
                for (int k = 0; k < c1; k++)
                {
                    sum += *(p1 + i*c1 + k) * *(p2 + k + c2 + j);
                }
                *(matrix.p + i *c2 + j) =  sum;
            }
            
        }
                
    }
    else
    {
        cout << "Can't perform multiplication" << endl;
        matrix.c = 0;
        matrix.r = 0;
        matrix.p = NULL;
    }
    return matrix;
}

void printing(int row, int col, long long *ptr)
{
    for (int i = 0; i < row; i++)
    {
        cout << "[";
        for (int j = 0; j < col; j++)
        {
            cout << " " << *ptr; // Corrected dereferencing here
            ptr = ptr + 1;
        }
        cout << " ]" << endl;
    }
    return;
}

int main()
{
    int row1, row2, col1, col2, *ptr1, *ptr2;
    cout<<"First Matrix"<<endl;
    cin>>row1;
    cin>>col1;
    cout<<"Second Matrix"<<endl;
    cin>>row2;
    cin>>col2;
    ptr1 = new int [row1*col1];
    ptr2 = new int [row2*col2];
    intialize(row1, col1, ptr1);
    intialize(row2,col2,ptr2);
    element matrix;
    matrix = matrices_multiplication(row1, col1, row2, col2, ptr1, ptr2);
    cout << "Resultant Matrix:" << endl;
    printing(matrix.r, matrix.c, matrix.p);
    delete [] ptr1;
    delete [] ptr2;
    return 0;
}