#include "../headers/psiSolution.h"
#include <math.h>
#include <constantes.h>


//temporaire
double fact(double n){
        if (n<=1){
                return 1;
        }
        else{
                return n*fact(n-1);
        }
}
/**
 * @brief retourne une matrice à 2 dimensions, contenant les valeurs de psi_i(z) ;
 * La ième colonne correspond aux valeurs de psi_i évalué à une valeur de z différente à chaque ligne;
 * Les valeurs de z sont données par le vecteur [vecteurZ] placé en argument
 * 
 * @param hermiteMat contient les valeurs du polynôme d'Hermite H_i(z) pour tout i tel que 0 <= i <= n
 * La ième colonne correspond aux valeurs de H_i évalué à une valeur de z différente à chaque ligne;
 * Les valeurs de z sont données par le vecteur [vecteurZ]
 * @param n_max est l'entier maximum pour lequel on possède les valeurs du polynome d'Hermite
 * stocké dans [hermiteMat]
 * @param vecteurZ est le vecteur de rééls pour lesquels on possède les valeurs d'évaluation du polynome
 * d'Hermite
 * @return arma::mat 
 */
arma::mat calculeSolution(arma::mat hermiteMat, int n_max, arma::vec vecteurZ)
{   
    int tailleZ = vecteurZ.size();
    //On créer une matrice contenant le facteur manquant pour la valeur de psi_s(z)
    arma::mat res(tailleZ, n_max, arma::fill::zeros);
    //Variables
    double e,c;
    for(int z_i=0; z_i<tailleZ; z_i++)
    {
        for(int n=0; n<n_max; n++)
        {
            e=exp(-m*omega*z_i*z_i/(2*hbar));
            c=pow(m*omega/(pi*hbar),0.25) / sqrt(fact(n)*pow(2,n));
            res(z_i,n) = hermiteMat(z_i,n) * c*e;
        }
    }
    return res;
};