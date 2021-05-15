// Marta Dzięgielewska
// Monte Carlo integration
// 21.05.2020

#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

double f(double x)
{
	return exp(x);
}

double f2(double y)
{
	return exp(sqrt(1.0+2.0*y)-1.0)/sqrt(1.0+2.0*y);
}

int main() {
	int D[200];
	double I,a,b,xi,I2,fxi,SN,IR,IL;
	
	a=0.0;
	b=1.0;
	
	for(int N=10;N<=10000000;N=N*10)
	{
		I=0.0;
		I2=0.0;
		for(int i=1;i<=N;i++)
		{	
			xi=((double) rand())/RAND_MAX;
			fxi=f(xi);
			I=I+fxi;
			I2=I2+(fxi*fxi);
		}
		I=I/N;
		I2=I2/N;
		SN=sqrt((I2-I*I)/(N-1));
		I=I*(b-a);
		cout << "I= " << setprecision(8) << I << ", SN= " << setprecision(8) << SN << endl;		
	}
	
	cout << "Exact= " << setprecision(8) << exp(1.0)-1.0 << endl;
	cout << endl;

	cout << "Importance sampling:" << endl;
	a=0.0;
	b=1.5;
	for(int N=10;N<=10000000;N=N*10)
	{
		I=0.0;
		I2=0.0;
		for(int i=1;i<=N;i++)
		{	
			xi=(((double) rand())/RAND_MAX)*1.5;
			fxi=f2(xi);
			I=I+fxi;
			I2=I2+(fxi*fxi);
		}
		I=I/N;
		I2=I2/N;
		SN=sqrt((I2-I*I)/(N-1));
		I=I*(b-a);
		cout << "I= " << setprecision(8) << I << ", SN= " << setprecision(8) << SN << endl;
	}
	cout << "Exact= " << setprecision(8) << exp(1.0)-1.0 << endl;
	
	
	for(int j=0;j<200;j++)
	{
		D[j]=0;
	}
	
	int N=1000;
	a=0.0;
	b=1.0;
	for(int e=1;e<=10000;e++)
	{
		I=0.0;
		for(int i=1;i<=N;i++)
		{	
			xi=((double) rand())/RAND_MAX;
			fxi=f(xi);
			I=I+fxi;
		}
		I=(b-a)*I/N;
		if((I<1.5)||(I>1.9)) { 
			cout << I<< endl;
		} else {
			IR=1.502;
			for(int j=0;j<200;j++) {
 				if(I<=IR) {
					D[j]+=1;
					break;
				}
				IR=IR+0.002;
			}	
		}
	}
	
	cout << endl;
	cout << "Distribution: " << endl;
	IL=1.5;
	for(int j=0;j<200;j++)
	{
		cout << IL << "  " << D[j] << endl;
		IL=IL+0.002;
	}
	
	return 0;
}