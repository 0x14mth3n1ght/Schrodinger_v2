#include <iostream>
#include <math.h>
#include <armadillo>

/**
 * @brief Renvoie les résultats du polynome d'Hermite de i=0 à un entier donné
 *  appliqué à un vecteur colonne, sous forme d'une matrice.
 *
 * @return arma::mat
 */
arma::mat hermiteMat(int, arma::vec);