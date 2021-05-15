// Marta Dzięgielewska
// Insertion sort
// 25.11.2019

#include <iostream>
#include <cmath>

using namespace std;

void insertionsort(int a[],int n)
{
    int i,value,index;
    for(i=1;i<n;i++) {
        value=a[i];
        index=i;
        while(index>0 && a[index-1]>value){
            a[index]=a[index-1];
            index=index-1;
        }
        a[index]=value;
    }
}

int main()
{
    int i;
    int n=100;
    int tab[n];
    insertionsort(tab,n);
    cout << "Oto twoja posortowana tablica: " << endl;
    for (i=0; i<n; i++){
        cout << i+1 << ". " << tab[i] << endl;
    }

    return 0;
}
