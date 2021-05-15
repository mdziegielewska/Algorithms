// Marta Dzięgielewska
// Gaussian elimination
// 21.05.2020

#include <iostream>

using namespace std;

int main ()
{
    double a[5]={0.0,-1.0,-1.0,-1.0,-1.0};
	double b[5]={2.0,2.0,2.0,2.0,2.0};
	double c[5]={-1.0,-1.0,-1.0,-1.0,0.0};
	double r[5]={0.0,1.0,2.0,3.0,4.0};
	double x[5], Beta[5], Rho[5];
	
	Beta[0]=b[0];
	Rho[0]=r[0];
	
	for(int j=1;j<5;j++)
	{
		Beta[j]=b[j]-(a[j]/Beta[j-1])*c[j-1];
		Rho[j]=r[j]-(a[j]/Beta[j-1])*Rho[j-1];
	}
	
	x[4]=Rho[4]/Beta[4];
	
	for(int j=1;j<5;j++)
	{
		x[4-j]=(Rho[4-j]-c[4-j]*x[4-j+1])/Beta[4-j];
	}
	
	for(int j=0;j<5;j++)
	{
		cout << "x" << j+1 << "= " << x[j] << endl;
	}
	
	cout << endl;
	cout << "Verifying the obtained solution: " << endl;
	cout << "r1= " << b[0]*x[0]+c[0]*x[1] << endl;
	cout << "r2= " << a[1]*x[0]+b[1]*x[1]+c[1]*x[2] << endl;
	cout << "r3= " << a[2]*x[1]+b[2]*x[2]+c[2]*x[3] << endl;
	cout << "r4= " << a[3]*x[2]+b[3]*x[3]+c[3]*x[4] << endl;
	cout << "r5= " << a[4]*x[3]+b[4]*x[4] << endl;
	return 0;
}