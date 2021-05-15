// Marta Dzięgielewska
// Bisection method
// 26.02.2020

#include<iostream>
#include<cmath>

using namespace std; 

double func(double x) 
{ 
    return cos(x)-x; 
} 

void bisection(double xl, double xr, double tolerance) 
{ 
    if (func(xl) * func(xr) >= 0) 
    { 
        cout << "incorrect xl and xr"; 
        return; 
    } 
  
    double xm = xl; 
    while (fabs((xr-xl)/xm) >= tolerance) 
    { 
        xm = (xl+xr)/2; 
        if (func(xm) == 0.0) 
            break; 
        else if (func(xm)*func(xl) < 0) 
            xr = xm; 
        else
            xl = xm; 
    } 
    cout << "The value of root is : " << xm; 
} 
  
 
int main() 
{ 
    double xl =0, xr = 1, tolerance = 0.00000001; 
    bisection(xl, xr, tolerance); 
    return 0; 
}