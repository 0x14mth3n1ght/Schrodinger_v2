#ifndef CONSTANTES_H
#define CONSTANTES_H

/**
 * @file constantes.h
 * @brief Ce fichier contient les constantes utiles pour le projet
 */

/**
 * @brief Constante utilisée comme pas pour la dérivée seconde
 *
 */
double pas_der=1e-7;

/**
 * @brief Constante hbar
 *
 */
double hbar = 1.0;

/**
 * @brief Constante omega
 *
 */
double omega = 1.0;

/**
 * @brief Constante m
 *
 */
double m = 1.0;

/**
 * @brief Contante pi
 *
 */
double pi = 3.141592653589793;

/**
 * @brief Degré utilisé pour la quadrature
 *
 */
int degQuadrature = 50;

/**
 * @brief Vecteur contenant les valeurs des z_i pour un degré de 50
 * Contient 50 valeurs
 * zi[i] = z_i
 *
 * Pour obtenir ces valeurs, on a utilisé la bibliothèque numpy de Python
 * via la fonction : numpy.polynomial.hermite.hermgauss(50)
 *
 */
arma::vec zi = {-9.18240696, -8.52277103, -7.97562237, -7.48640943, -7.03432351,
                -6.60864797, -6.20295252, -5.81299468, -5.43578609, -5.06911758,
                -4.71129367, -4.36097316, -4.01706817, -3.67867706, -3.34503831,
                -3.01549777, -2.6894847, -2.3664939, -2.04607197, -1.72780655,
                -1.41131775, -1.09625113, -0.78227173, -0.46905906, -0.15630255,
                0.15630255,  0.46905906,  0.78227173,  1.09625113,  1.41131775,
                1.72780655,  2.04607197,  2.3664939,  2.6894847,  3.01549777,
                3.34503831,  3.67867706,  4.01706817,  4.36097316,  4.71129367,
                5.06911758,  5.43578609,  5.81299468,  6.20295252,  6.60864797,
                7.03432351,  7.48640943,  7.97562237,  8.52277103,  9.18240696
                };

/**
 * @brief Vecteur contenant la valeurs des w_i pour un degré de 50
 * Contient 50 valeurs
 * wi[i] = w_i
 *
 * Pour obtenir ces valeurs, on a utilisé la bibliothèque numpy de Python
 * via la fonction : numpy.polynomial.hermite.hermgauss(50)
 */
arma::vec wi = {1.83379405e-37, 1.67380167e-32, 1.21524412e-28, 2.13765831e-25,
                1.41709360e-22, 4.47098437e-20, 7.74238296e-18, 8.09426189e-16,
                5.46594403e-14, 2.50665552e-12, 8.11187736e-11, 1.90904054e-09,
                3.34679340e-08, 4.45702997e-07, 4.58168271e-06, 3.68401905e-05,
                2.34269892e-04, 1.18901178e-03, 4.85326383e-03, 1.60319411e-02,
                4.30791592e-02, 9.45489355e-02, 1.70032456e-01, 2.51130856e-01,
                3.05085129e-01, 3.05085129e-01, 2.51130856e-01, 1.70032456e-01,
                9.45489355e-02, 4.30791592e-02, 1.60319411e-02, 4.85326383e-03,
                1.18901178e-03, 2.34269892e-04, 3.68401905e-05, 4.58168271e-06,
                4.45702997e-07, 3.34679340e-08, 1.90904054e-09, 8.11187736e-11,
                2.50665552e-12, 5.46594403e-14, 8.09426189e-16, 7.74238296e-18,
                4.47098437e-20, 1.41709360e-22, 2.13765831e-25, 1.21524412e-28,
                1.67380167e-32, 1.83379405e-37
               };


#endif
