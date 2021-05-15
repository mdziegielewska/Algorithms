// Marta Dzięgielewska
// Numerical integration
// 21.05.2020

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x){
	return sin(x);
}

double fp(double x){
	return cos(x);
}

double fppp(double x){
	return -1.0*cos(x);
}

void Trapezoid(){
	double h,I,x;
	double PI=3.14159265358979323846;
	
	cout << "Trapezoid: " << endl;
		
	for(int N=4;N<=1024;N*=2){
		h=PI/(1.0*N);
		x=0.0;
		I=0.0;
		for(int i=0;i<=N;i++){
			if((i==0)||(i==N)){
				I=I+f(x)/2.0;
			}
			else {
				I=I+f(x);
			}
			x=x+h;
		}
		I=I*h;
		
		cout << "N = " << N << ", Integral = " << setprecision(13) << I << endl;
	}
}

void Simpson(){
	double h,I,x;
	double PI=3.14159265358979323846;
	
	cout << "Simpson: " << endl;
			
	for(int N=4;N<=1024;N*=2){
		h=PI/(1.0*N);
		x=0.0;
		I=0.0;
		for(int i=0;i<=N;i++){
			if((i==0)||(i==N)){
				I=I+f(x);
			}
			else if(i%2==0){
				I=I+2.0*f(x);
			}
			else{
				I=I+4.0*f(x);
			}
			x=x+h;
		}
		I=I*h/3.0;
		
		cout << "N= " << N << ", Integral = " << setprecision(13) << I << endl;
	}
}

void Boole(){
	double h,I,x;
	double PI=3.14159265358979323846;
	
	cout << "Boole: " << endl;
			
	for(int N=4;N<=1024;N*=2){
		h=PI/(1.0*N);
		x=0.0;
		I=0.0;
		for(int i=0;i<=N;i++){
			if((i==0)||(i==N)){
				I=I+7.0*f(x);
			}
			else if(i%2!=0){
				I=I+32.0*f(x);
			}
			else if(i%4==0){
				I=I+14.0*f(x);
			}
			else{
				I=I+12.0*f(x);
			}
			x=x+h;
		}
		I=I*(2.0*h/45.0);
		
		cout << "N= " << N << ", Integral = " << setprecision(13) << I << endl;
	}
}

void EulerMacLaurin(){
	double PI=3.14159265358979323846;
	double h,I,x,x0=0.0,xN=PI;
	
	cout << "Euler-MacLaurin: " << endl;
			
	for(int N=4;N<=1024;N*=2){
		h=PI/(1.0*N);
		x=0.0;
		I=0.0;
		for(int i=0;i<=N;i++){
			if((i==0)||(i==N)){
				I=I+f(x)/2.0;
			}
			else {
				I=I+f(x);
			}
			x=x+h;
		}
		I=I*h;
		I=I+(h*h/12.0)*(fp(x0)-fp(xN))-(h*h*h*h/720.0)*(fppp(x0)-fppp(xN));
		
		cout << "N= " << N << ", Integral = " << setprecision(13) << I << endl;
	}
}


int main() {
    Trapezoid();
    cout << endl;
	Simpson();
	cout << endl;
	Boole();
	cout << endl;
	EulerMacLaurin();
	cout << endl;

	return 0;
}