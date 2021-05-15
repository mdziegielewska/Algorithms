// Marta Dzięgielewska
// Newton Raphson 3 method
// 04.03.2020

#include <iostream>
#include <cmath>

using namespace std;

long double funct(long double x)
{
    return pow(x, 3)-169;
}

long double deriv(long double x)
{
    return 3*pow(x, 2);
}

void newtonraphson (long double x) {
    long double h = funct(x)/deriv(x);
    while (fabs(h) >= pow(10, -8)) {
        h = funct(x)/deriv(x); //x(i+1)=x(i)-f(x)/f'(x)
        x = x - h;
    };
    cout << "the value of the root is: " << x;
}

int main()
{
    cout.precision(9);
    long double x0 = pow(13, 2/3);
    newtonraphson(x0);
    return 0;
}
