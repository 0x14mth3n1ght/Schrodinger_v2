/**
 * @file hermite.h
 * @brief Interface qui donne toutes les fonctions nécessaires pour calculer des polynomes d'Hermites en des points donnés.
 *
 *
 */
#include <iostream>
#include <math.h>
#include <armadillo>
#ifndef HERMITE
#define HERMITE
/**
 * @brief Renvoie les résultats du polynome d'Hermite d'indice i=0 à un entier donné n_max
 *  appliqué à un vecteur colonne Z, sous forme d'une matrice.
 *
 * @return arma::mat La matrice avec les résultats du polynome d'Hermite
 */
arma::mat hermiteMat(int, arma::vec);
#endif