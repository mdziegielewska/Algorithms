// Marta Dzięgielewska
// Richardson-Romberg method
// 11.04.2020

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x)
{
	return (x*exp(x));
}

double f2(double x)
{
	return sin(x);
}

void fpRichardson(double h, int n){
	double ** D = new double * [n];
	for(int i=0;i<n;i++) D[i] = new double[n];
	
	cout << "fp richardson: " << endl;
	
	for(int i=0;i<n;i++){
		cout << h << "  ";
		for(int j=0;j<=i;j++){
			if(j==0) D[i][j]=(f(2.0+h)-f(2.0-h))/(2.0*h);
			if(j!=0) D[i][j]=(pow(4.0,j)*D[i][j-1]-D[i-1][j-1])/(pow(4.0,j)-1.0);
			cout << setprecision(12) << D[i][j] << "  ";
		}
		h=h/2.0;
		cout << endl;
	}
	cout << "Exact= " << setprecision(12) << exp(2.0)+2.0*exp(2.0) << endl;
}

void fppRichardson(double h, int n){
	double ** D = new double * [n];
	for(int i=0;i<n;i++) D[i] = new double[n];
	
	cout << "fpp richardson: " << endl;

	for(int i=0;i<n;i++){
		cout << h << "  ";
		for(int j=0;j<=i;j++){
			if(j==0) D[i][j]=(f(2.0+h)-2.0*f(2.0)+f(2.0-h))/(h*h);
			if(j!=0) D[i][j]=(pow(4.0,j)*D[i][j-1]-D[i-1][j-1])/(pow(4.0,j)-1.0);
			cout << setprecision(12) << D[i][j] << "  ";
		}
		h=h/2.0;
		cout << endl;
	}
	cout << "Exact= " << setprecision(12) << 4.0*exp(2.0) << endl;
}

double CalT(int m){
	double h,I,x;
	double PI=3.14159265358979323846;
	int N=2;
	N=pow(2,m);
	h=PI/(1.0*N);
	x=0.0;
	I=0.0;
	
	for(int i=0;i<=N;i++){
		if((i==0)||(i==N)){
			I=I+f2(x)/2.0;
		}
		else {
			I=I+f2(x);
		}
		x=x+h;
	}
	I=I*h;
	return I;
}

void Romberg(int mMax){
	double ** T = new double * [mMax+1];
	for(int i=0;i<=mMax;i++) T[i] = new double[mMax+1];
	
	cout << "romberg: " << endl;
	
	for(int m=2;m<=mMax;m++){
		cout << m << "  ";
		for(int k=0;k<=m-2;k++){ 
			if(k==0) T[m][k]=CalT(m);
			if(k!=0) T[m][k]=(pow(4.0,1.0*k)*T[m][k-1]-T[m-1][k-1])/(pow(4.0,1.0*k)-1.0);
			cout << setprecision(13) << T[m][k] << "  ";
		}
		cout << endl;
	}
}	

int main() {
	double h = 0.4;
	int n = 4;
	int mMax = 5;
	
    fpRichardson(h,n);
    cout << endl;
	fppRichardson(h,n);
	cout << endl;
	Romberg(mMax);
	cout << endl;
		
	return 0;
}