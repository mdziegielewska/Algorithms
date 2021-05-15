// Marta Dziêgielewska
// Cubic spline function
// 16.05.2020

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void check_diagonals(const vector<double> &a, const vector<double> &b, const vector<double> &c, int n) {
    double suma = 0;
    double sumb = 0;
    double sumc = 0;
    for (int i = 0; i<n; i++) {
        suma += a[i];
    }
    for (int i = 0; i<n; i++) {
        sumb += b[i];
    }
    for (int i = 0; i<n; i++) {
        sumc += c[i];
    }
    if (fabs(suma)+fabs(sumc)>=fabs(sumb)) {
        cout << "Incorrect coefficients!" << endl;
    }
}

void solve(const vector<double> &a, const vector<double> &b, const vector<double> &c, const vector<double> &d, vector<double> &z, int n) {
    vector<double> alpha(n,0);
    vector<double> beta(n,0);
    vector<double> v;

    v = alpha;
    alpha[0] = -c[0] / b[0]; // alpha
    beta[0] = d[0] / b[0]; // beta

    for (int i = 1; i < n; i++) {
        alpha[i] = -c[i] / (b[i] + a[i]*alpha[i-1]);
        beta[i] = (d[i] - a[i]*beta[i-1]) / (b[i] + a[i]*alpha[i-1]);
    }

    v[n-1] = beta[n-1];
    for (int i = n-2; i >= 0; i--){
        v[i] = beta[i] + alpha[i]*v[i+1];
    }
    for (int i = 0; i<v.size(); i++) {
        z[i] = v[i];
    }
}

double f(double x){
	return sin(x);
}

int main() {
    vector<double> t = {-6, -5, -3, -2, 0, 1.5, 3, 4, 6, 7, 8};
    int n = t.size();
    cout << "f(x) = sin(x)" << endl;
    vector<double> y(n,0);
    for (int i=0; i<n; i++) {
        y[i] = f(t[i]);
    }
    for (int i = 0; i<y.size(); i++) {
        cout << y[i];
        if(i<y.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
    vector <double> h(n,0);
    for (int i = 0; i<n-1; i++) {
        h[i] = t[i+1]-t[i];
    }
    vector<double> F(n,0);
    for(int i=1; i<n-1; i++){
		F[i]=(6/h[i])*(y[i+1]-y[i])-(6/h[i-1])*(y[i]-y[i-1]);
    }
    vector<double> A(n,0);
    for(int i=2; i<n-1; i++) {
        A[i]=h[i-1];
    }
    vector<double> B(n,1);
    for(int i=1; i<n-1; i++) {
        B[i]=2*(h[i-1]+h[i]);
    }
    vector<double> C(n,0);
    for(int i=1; i<n-2; i++) {
        C[i]=h[i];
    }
    vector<double> Z(n,0);
    check_diagonals(A,B,C,n);
    solve(A,B,C,F,Z,n);
    cout << endl;
    cout << "Druga pochodna" << endl;
    for(int i = 0; i<Z.size(); i++) {
        cout << Z[i];
        if(i<Z.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << endl;
    double x;
    cout << "Funkcja sklejona" << endl;
    for(int i = 0; i<n; i++) {
        x = t[i];
        double p = (Z[i]/(6*h[i]))*((t[i+1]-x)*(t[i+1]-x)*(t[i+1]-x))+(Z[i+1]/(6*h[i]))*((x-t[i])*(x-t[i])*(x-t[i]))+((f(x+1)/h[i])-(Z[i+1]*h[i]/6))*(x-t[i])+((f(x)/h[i])-(Z[i]*h[i]/6))*(t[i+1]-x);
        cout << p << " ";
    }
    cout << endl;
    return 0;
}
