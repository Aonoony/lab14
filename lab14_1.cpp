#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[]){

    double arithsum = 0;
    for(int i = 0; i<n ; i++){
        arithsum += a[i];
    }
    b[0] = arithsum/n;

    double stdsum = 0;
    for(int i = 0; i<n ; i++){
        stdsum += pow(a[i]-b[0], 2);
    }
    b[1] = sqrt(stdsum/n);

    double geomul = 1;
    for(int i = 0; i<n ; i++){
        geomul *= a[i];
    }
    b[2] = pow(geomul,(double)1/n);

    double harmosum = 0;
    for(int i = 0; i<n ; i++){
        harmosum += 1/a[i];
    }
    b[3] = n/harmosum;

    double max = a[0], min = a[0];
    for(int i = 1; i<n ; i++){
        if(a[i] > max) max = a[i];       
        if(a[i] < min) min = a[i];
        b[4] = max;
        b[5] = min;
    }
}
