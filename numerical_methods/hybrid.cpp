// Marta Dzięgielewska
// Hybrid method
// 11.04.2020

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x){
	return (6435.0*pow(x,8)-12012.0*pow(x,6)+6930.0*pow(x,4)-1260.0*pow(x,2)+35)/128.0;
}

double derivedf(double x){
	return (6435.0*8.0*pow(x,7)-12012.0*6.0*pow(x,5)+6930.0*4.0*pow(x,3)-1260.0*2.0*x)/128.0;
}

int main() {
	double x = 0.4;
	double xl = 0.4;
	double xr = 0.7;
	double tolerance = 0.00000001;

	while(fabs((f(x)/derivedf(x))) >= tolerance){
        if((((x-xl)*derivedf(x)-f(x))*((x-xr)*derivedf(x)-f(x)))<0.0){
			x = x - (f(x)/derivedf(x));
			cout << "Newton-Raphson x = " << x <<endl;
		} else {
			x = (xr+xl)/2;
			cout << "Bisection x = " << x <<endl;
		}
		if((f(xl)*f(x)) < 0){
			xr = x;
		} else {
			xl = x;
		}
		x = x;
	}
	cout << "Root found at " << setprecision(8) << x << endl;
	return 0;
}