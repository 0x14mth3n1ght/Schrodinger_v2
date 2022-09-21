#include <iostream>
#include <math.h>
#include <armadillo>
#include "headers/constantes.h"

/*relation de recurrence
@param n>=0 : nème solution phi, z : position abscisse 
@returns H(n,z)
*/
double Hermite(double n, double z){
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
/*
@param n>=0
@returns fact(n)
*/
double fact(double n){
        if (n<=1){
                return 1;
        }
        else{
                return n*fact(n-1);
        }
}

/*m,omega,hbar dans headers/constantes.h*/
/*
@param n>=0 : nème solution phi, z : position abscisse 
@returns solution 1D schrödinger en (n,z)

*/
double phi(double n, double z){
        double h=Hermite(n,sqrt(z*m*omega/hbar));
        double e=exp(-m*omega*z*z/(2*hbar));
        double c=pow(m*omega/(M_PI*hbar),0.25)/sqrt(fact(n)*pow(2,n));
        double phi_sol=c*e*h;
        return phi_sol;
}

int main(){
        std::cout << 2*1.2;
        std::cout << pow(2.0,0.25); /*attention pow renvoie 1 si int*/
	return 0;
}
