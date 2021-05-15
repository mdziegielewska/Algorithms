// Marta Dzięgielewska
// Secant method
// 11.04.2020

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x)
{
	return cos(x) - x;
}

int main()
{
    double x_new;
    double x_old;
    double x_older;
	double xl = 0;
	double xr = 1;
	double tolerance = 0.00000001;
    int i = 0;

	x_old = xl;
	while(fabs((x_new-x_old)/x_new) > tolerance) {
	    x_new=(xl*f(xr)-xr*f(xl))/(f(xr)-f(xl));
        i++;
        cout << "new x = " << setprecision(8) << x_new << endl;
        if((f(xl)*f(x_new)) < 0)
		{
			xr = x_new;
		} else {
			xl = x_new;
		}
		x_old = x_new;
	}
	cout << "Root found at " << setprecision(8) << x_new <<endl;

	while(fabs((x_new-x_old)/x_new) > tolerance) {
	    x_new = (x_older*f(x_old)-x_old*f(x_older))/(f(x_old)-f(x_older));
		x_older = x_old;
		x_old = x_new;
        cout << "new x = " << setprecision(8) << x_new << endl;
	}
	cout << "Root found at " << setprecision(8) << x_new <<endl;
    return 0;
}
