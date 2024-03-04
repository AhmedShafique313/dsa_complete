#include <iostream>
#include <new>
using namespace std;

struct element
{
    int c, r;
    int *p;
};

void initialize_matrix(int row, int col, int *ptr)
{
    int k=0;
    for(int i=0;i<row;i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>k;
            *(ptr + (i*col)+ j) = k;
        }
    }
    return;
}

element matrices_multiplication(int r1, int c1, int r2, int c2, int *p1, int *p2)
{
    element matrix;
    if (c1 == r2)
    {
        matrix.c = c2;
        matrix.r = r1;
        matrix.p = new int [r1*c2];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                long long sum = 0;
                for (int k = 0; k < r2; k++)
                {
                    sum += *(p1 + i*r2 + k) * *(p2 + k * c2 + j);
                }
                *(matrix.p + i *c2 + j) =  sum;
                sum = 0;
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

void printing(int row, int col, int *ptr)
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

double determinant(int m, int *p)
{
    double ans = 0;
    double inner_determinant, inner_sol;
    int a, b, c, d;
    if ((m == 1) || (m = 2))
    // stopping criteria
    {
        if (m == 1)
        {
            ans = *p;
        }
        else
        {
            a = *p;
            b = *(p+1);
            c = *(p+2);
            d = *(p+3);
            ans = (a*d) - (b*c);
        }
    }
    else
    {
        int n, l, sign, basic, element;
        n = 0;
        sign = +1;
        int *q;
        q = new int [(m-1)*(m-1)];
        for (int i = 0; i < m; i++)
        {
            l = 0;
            n = 0;
            basic = *(p+i);
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    element = *(p+l);
                    cout<<element<<" ";
                    if ((j==0) || (i==k));
                    else
                    {
                        *(q + n) = element;
                        n = n + 1;
                    }
                    l = l + 1;  
                }
            }
            
            cout<<endl<<basic<<"x"<<endl;
            printing((m-1),(m-1), q);
            inner_determinant = determinant(m-1, q);
            inner_sol = sign * basic * inner_determinant;
            cout<<" sign "<<sign<<" x basic "<<basic<<" x Determinant "<<inner_determinant<<" = "<<inner_sol<<endl;
            ans = ans + inner_sol;
            sign = sign * -1;
        }
        delete [] q;
    }    
    return ans;
}





int main()
{
    int row1, row2, col1, col2, *ptr1, *ptr2;
    cout<<"Enter dimensions of First Matrix: "<<endl;
    cin>>row1>>col1;cout<<endl;
    cout<<"Enter dimensions of Second Matrix: "<<endl;
    cin>>row2>>col2;cout<<endl;
    ptr1 = new int [row1*col1];
    ptr2 = new int [row2*col2];
    initialize_matrix(row1, col1, ptr1);
    initialize_matrix(row2,col2,ptr2);
    element matrix;
    matrix = matrices_multiplication(row1, col1, row2, col2, ptr1, ptr2);
    cout << "Resultant Matrix:" << endl;
    printing(matrix.r, matrix.c, matrix.p);
    double ans = determinant(matrix.r,matrix.p);
    cout<<"Determinant: "<<ans<<endl;
    delete [] ptr1;
    delete [] ptr2;
    return 0;
}