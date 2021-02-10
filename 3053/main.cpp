#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
int main() {
    double r;
    cin >> r;

    cout << fixed;
    cout.precision(6);

    cout << r*r*M_PI << '\n' << r*r*2 << endl;

    return 0;
}
