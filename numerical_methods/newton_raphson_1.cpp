// Marta Dzięgielewska
// Newton Raphson 1 method
// 04.03.2020

#include <iostream>
#include <cmath>
#define tolerance 0.00000001

using namespace std;

double funct(double x)
{
    return cos(x) - x;
}

double deriv(double x)
{
    return -sin(x)-1;
}

void newtonraphson (double x) {
    double h = funct(x)/deriv(x);
    while (fabs(h) >= tolerance) {
        h = funct(x)/deriv(x); //x(i+1)=x(i)-f(x)/f'(x)
        x = x - h;
    };
    cout << "the value of the root is: " << x;
}

int main()
{
    double x0 = 0;
    newtonraphson(x0);
    return 0;
}
