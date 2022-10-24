#include <iostream>
#include <math.h>
#include <armadillo>

/**
 * @brief Renvoie les résultats du polynome d'Hermite d'indice i=0 à un entier donné n_max
 *  appliqué à un vecteur colonne Z, sous forme d'une matrice.
 *
 * @return arma::mat La matrice avec les résultats du polynome d'Hermite
 */
arma::mat hermiteMat(int, arma::vec);