#include <iostream>
#include <math.h>

using namespace std;

double geometric_series(double a, double r) {
    if (r < 1) {
        return a / (1 - r);
    } else if (r > 1) {
        return a / (r - 1);
    } else {
        cout << "The common ratio cannot be 1." << endl;
        return -1;
    }
}

int main() {
    double a, r;

    a= 5.0;

    r = 7.0;
    double sum = geometric_series(a, r);

    if (sum != -1) {
        cout << "The sum of the infinite geometric series is: " << sum << endl;
    }

    return 0;
}