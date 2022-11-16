#ifndef POLY_H
#define POLY_H

#include <armadillo>

class poly
{
private:
    /**
     * @brief 
     * 
     */
    arma::mat internHermiteMat;

    /**
     * @brief 
     * 
     */
    arma::cube internLaguerreMat;

public:

    //Constructeur
    poly();

    /**
     * @brief Construct a new arma::calc Hermite object
     *
     */
    void calcHermite(int, const arma::vec &);

    /**
     * @brief
     *
     * @return arma::mat
     */
    void calcLaguerre(int, int, const arma::vec &);

    /**
     * @brief Renvoie les résultats du polynome d'Hermite d'indice i=0 à un entier donné n_max
     *  appliqué à un vecteur colonne Z, sous forme d'une matrice.
     *
     * @return arma::mat La matrice avec les résultats du polynome d'Hermite
     */
    const arma::vec hermite(int);

    /**
     * @brief
     *
     * @return arma::mat
     */
    const arma::vec laguerre(int, int);
};

#endif