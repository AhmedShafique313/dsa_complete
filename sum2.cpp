#include <iostream>
#include <math.h>

using namespace std;
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

int main() {
    double a, r, n;

    a = 5.0;

    r = 6.0;

    n = 4;

    double sum = geometric_series(a, r, n);

    if (sum != -1) {
        cout << "The sum of the geometric series is: " << sum << endl;
    }

    return 0;
}