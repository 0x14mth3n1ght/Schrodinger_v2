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
        double h=Hermite(n,z*sqrt(m*omega/hbar));
        double e=exp(-m*omega*z*z/(2*hbar));
        double c=pow(m*omega/(M_PI*hbar),0.25)/sqrt(fact(n)*pow(2,n));
        double phi_sol=c*e*h;
        return phi_sol;
}

/* wi et zi dans headers/constantes.h*/
double ortho(double l,double n){
        double c = 1/sqrt(pi*pow(2,n+l)*fact(n)*fact(l));
        double sum=0;
        for(int i=0;i<10;i++){
                sum+=wi[i]*Hermite(n,zi[i])*Hermite(l,zi[i]);
        }
        return c*sum;

}

int main(){
        double n=2;
        double l=3;
        //double phi_n = phi(n,z);
        //double phi_l = phi(l,z);
        double ortho_diff = ortho(l,n);
        double ortho_same = ortho(l,l);
        std::cout << ortho_diff;
        std::cout << ortho_same;
	return 0;
}
