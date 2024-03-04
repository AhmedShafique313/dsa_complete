#include <iostream>
#include <new>
using namespace std;

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