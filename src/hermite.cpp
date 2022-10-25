/**
 * @file hermite.cpp
 * @brief Implémentation d'hermite.h
 *
 */

#include <iostream>
#include <math.h>
#include <armadillo>
/**
 * @brief Renvoie les résultats du polynome d'Hermite d'indice i=0 à un entier donné n_max
 *  appliqué à un vecteur colonne Z, sous forme d'une matrice.
 *
 * @param n_max Indice max des polynomes d'Hermites utilisés dans la matrice
 * @param Z Vecteur colonne contenant les points à appliquer aux polynomes d'Hermite
 * @return arma::mat Retourne une matrice de la forme suivante : \f$Z=\begin{bmatrix} z_0 & ... & z_m \end{bmatrix}\f$
    \f[
    \begin{bmatrix}
    H_0(z_0) & .. & H_{n_{max}}(z_0) \\
    .. & .. & .. \\
    H_0(z_m) & .. & H_{n_{max}}(z_m)
    \end{bmatrix}
    \f]
 */
arma::mat hermiteMat(int n_max, arma::vec Z)
{
    //n_max+1 parce que il faut commencer à n=0
    arma::mat res(Z.size(), n_max+1, arma::fill::zeros);
    for(int i=0; i<n_max+1; i++)
    {
        //1er cas i = 0; H_0(z)=1
        //2e cas i=1; H_1(z)=2z
        //3e cas i>1; H_i(z)=2z*H_(i-1)(z) - 2(i-1)*H_(i-2)(z)
        if(i==0)
            res.col(0)=arma::vec(arma::size(Z), arma::fill::value(1));
        else if(i==1)
            res.col(1)=2*Z;
        else
        {
            res.col(i)=2*(Z % res.col(i-1))-2*(i-1)*res.col(i-2);
        }
    }
    return res;
}
