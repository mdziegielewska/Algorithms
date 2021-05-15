// Marta Dzięgielewska
// Comb sort
// 26.11.2019

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int nextgap(int gap){
    gap = gap/1.3;
    return gap;
}

void combsort(int a[], int n){
    int gap = n;
    int i;
    bool swapped = true;
    while (gap > 1  || swapped == true){
        gap = nextgap(gap);
        swapped = false;
        for (i=0 ; i< n-gap;i++){
			if(a[i]>a[i+gap]){
                swap(a[i], a[i+gap]);
                swapped = true;
            } else if(a[i+gap]>(a[i])){
            continue;
			}
        }
    }
}

int main()
{
    
    srand(time(NULL));
    int n = 100;
    int a[n];
    int i;
    combsort(a,n);
    
    cout << "Oto twoje posortowana tablica:" << endl;
    for (i=0; i<n; i++){
        cout <<  a[i] << endl;
    }
    return 0;

}
