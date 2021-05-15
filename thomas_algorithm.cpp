// Marta Dziêgielewska
// Thomas algorithm
// 30.04.2020

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

void solve(const vector<double> &a, const vector<double> &b, const vector<double> &c, const vector<double> &d, int n) {
    vector<double> v;
    vector<double> alpha(n,0);
    vector<double> beta(n,0);

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
    cout << "Wyniki: " << endl;
    for (int i = 0; i<n; i++) {
        cout << "x" << i+1 << " = " << v[i] << endl;
    }
}

int main() {
    int n = 5;
	vector<double> A = {0, -1, -1, -1, -1};
	vector<double> B = {2, 2, 2, 2, 2};
	vector<double> C = {-1, -1, -1, -1, 0};
	vector<double> F = {0, 1, 2, 3, 4};
	check_diagonals(A, B, C, n);
	solve(A, B, C, F, n);
}
