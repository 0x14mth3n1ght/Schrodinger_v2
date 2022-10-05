#include <iostream>
#include <math.h>
#include <armadillo>

/**
 * @brief Renvoie les résultats du polynome d'Hermite de i=0 à un entier donné
 *  appliqué à un vecteur colonne, sous forme d'une matrice.
 * 
 * @return arma::mat 
 */
arma::mat hermiteMat(int n_max, arma::vec Z)
{
        arma::mat res(Z.size(), n_max, arma::fill::zeros);
        for(int i=0;i<n_max;i++)
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