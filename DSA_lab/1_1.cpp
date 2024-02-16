#include<iostream>
using namespace std;


double arithmeticSeriesSum(double a, double d, int n)
{
    double sum = (n/2) * (2 * a + (n - 1) * d);
    return sum;
}

int main() 
{
    double a = 3.0;  
    double d = 2.0;  
    int n = 5;      

    double result = arithmeticSeriesSum(a, d, n);

    cout<<"Sum of the arithmetic series: "<<result<<endl;

    return 0;
}