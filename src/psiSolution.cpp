#include "../headers/psiSolution.h"
#include <math.h>
#include "../headers/constantes.h"
#include "../headers/hermite.h"
#include <iostream>


psiSolution::psiSolution() : n_max(1)
{};

psiSolution::psiSolution(int n) : n_max(n)
{};


/**
 * @brief fonction factoriel
 * 
 * @param n un entier
 * @return double, n! 
 * @warning retourne 1 si n<0
 */
double fact(double n)
{
    if (n<=1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}


/**
 * @brief retourne une matrice à 2 dimensions, contenant les valeurs de psi_i(z) ;
 * La ième colonne correspond aux valeurs de psi_i évalué à une valeur de z différente à chaque ligne;
 * Les valeurs de z sont données par le vecteur [vecteurZ] placé en argument
 *
 * @param vecteurZ est le vecteur de rééls pour lesquels on possède les valeurs d'évaluation du polynome
 * d'Hermite
 * @return arma::mat Retourne une matrice de la forme suivante : exemple n_max=2
 $ \begin{matrix}
    psi_0(z_0) & psi_1(z_0) & psi_2(z_0) \\
    psi_0(z_1) & psi_1(z_1) & psi_2(z_1) \\
    psi_0(z_2) & psi_1(z_2) & psi_2(z_2)
    \end{matrix}  $
 */

arma::mat psiSolution::calculeSolution(const arma::vec &vecteurZ)
{
    //Récupération de la matrice Hermite
    arma::mat hermiteMatrix = hermiteMat(n_max, vecteurZ);
    int tailleZ = vecteurZ.size();
    //On crée une matrice contenant le facteur manquant pour la valeur de psi_s(z)
    arma::mat res(tailleZ, n_max, arma::fill::zeros);
    //Variables
    double e,c;
    for(int z_i=0; z_i<tailleZ; z_i++)
    {
        for(int n=0; n<n_max; n++)
        {
            e=exp(-(m*omega*vecteurZ[z_i]*vecteurZ[z_i])/(2*hbar));
            c=pow((m*omega)/(pi*hbar),0.25) / sqrt(fact(n)*pow(2,n));
            res(z_i,n) = hermiteMatrix(z_i,n) * c * e;
        }
    }
    return res;
};

/**
 * @brief Verifie l'orthonormalité des psi-solutions. On vérifie pour tous les 
 * couples n,m <= n_max. On retourne les résultats dans une matrice dont les
 * numéros de lignes et les colonnes correspondent aux valeurs de n et m.
 * 
 * @return arma::mat Retourne une matrice de la forme suivante : exemple n_max=1
 $ \begin{matrix}
    \int \psi^*_0(z)\psi_0(z) dz & \int \psi^*_0(z)\psi_1(z) dz \\
    \int \psi^*_1(z)\psi_0(z) dz & \int \psi^*_1(z)\psi_1(z) dz \\
    \end{matrix}  $
 */
arma::mat psiSolution::orthoMat()
{
    //On transfère les valeurs des zi dans un vecteur armadillo
    //pour pouvoir appliquer hermiteMat
    int i;
    
    arma::vec vecZi(degQuadrature, arma::fill::zeros);
    for (i=0; i<degQuadrature; i++)
    {
        vecZi[i]=zi[i];
    }
    
    //Récupération de la matrice Hermite
    arma::mat hermiteMatrix = hermiteMat(n_max, vecZi);
    
    //On crée une matrice contenant les valeurs d'orthonormalité
    arma::mat res(n_max, n_max, arma::fill::zeros);
    
    int n,l;
    double sum,c;

    for (n=0; n<n_max; n++)
    {
        for (l=0; l<=n ; l++)
        {
            c = 1/sqrt(pi*pow(2,n+l)*fact(n)*fact(l));
            sum=0;
            for(i=0;i<degQuadrature;i++)
            {
                sum+=wi[i]*hermiteMatrix(i,n)*hermiteMatrix(i,l);
            }
            res(n,l)=c*sum;
        }
    }

    // On copie les valeurs répétées dans le symétrique de la matrice
    // par rapport à la diagonale

    for (l=1; l<n_max; l++)
    {
        for (n=0; n<l ; n++)
        {
            res(n,l)=res(l,n);
        }
    }

    return res;
}