#include <iostream>
#include <math.h>
using namespace std;

double arithmeticSeriesSum(double a, double d, int n)
{
    double sum = (n/2) * (2 * a + (n - 1) * d);
    return sum;
}

double geometric_series(double a, double r, int n) {
    if (r > 1) {
        return a * (pow(r, n) - 1) / (r - 1);
    } else if (r < 1) {
        return a * (1 - pow(r, n)) / (1 - r);
    } else {
        cout << "The common ratio cannot be 1." << endl;
        return -1;
    }
}
double geometric_infinite_series(double a, double r) {
    if (r < 1) {
        return a / (1 - r);
    } else if (r > 1) {
        return a / (r - 1);
    } else {
        cout << "The common ratio cannot be 1." << endl;
        return -1;
    }
}


int main()
{
    int choice;
    cout<<"Hello! What you want to calculate from the following? type(1 or 2 or 3)";cin>>choice;
    double a, d, r;
    int n;
    if (choice==1)
    {
        cout<<"Enter the value of a : ";cin>>a;
        cout<<"Enter the value of d : ";cin>>d;
        cout<<"Enter the value of n : ";cin>>n;
        double sum1 = arithmeticSeriesSum(a,d,n);
        cout<<"Sum of Arithmatic Series: "<<sum1<<endl;
    } 
    else if (choice ==2)
    {
        cout<<"Enter the value of a : ";cin>>a;
        cout<<"Enter the value of r : ";cin>>r;
        cout<<"Enter the value of n : ";cin>>n;
        double sum2 = geometric_series(a, r, n);
        cout<<"Sum of Geometric Series: "<<sum2<<endl;
    }
    else 
    {
        cout<<"Enter the value of a : ";cin>>a;
        cout<<"Enter the value of r : ";cin>>r;
        double sum3 = geometric_infinite_series(a,r);
        cout<<"Sum of Infinite Geometric Series: "<<sum3<<endl;
    }
    return 0;
}