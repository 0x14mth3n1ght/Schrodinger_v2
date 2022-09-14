#include <iostream>
#include <math.h>
#include <armadillo>

double m = 1.00;
double w = 1.00;
double pi = 3.14;

int Hermite(int n, int z){
        if (n==0){
                return 1;
        }
        else if (n==1){
                return 2*z;
        }
        else {
                int res = 2*z*Hermite(n-1,z) - 2*(n-1)*Hermite(n-2,z);
                return res;
        }
}

int main(){
	return 0;
}
