/**
 * @file constantes.h
 * @brief Ce fichier contient les constantes utiles pour le projet
 */

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
 * @brief Tableau contenant les valeurs des x_i pour un degré de 10
 * xi[i] = x_i
 * 
 * Pour obtenir ces valeurs, on a utiliser la bibliothèque numpy de Python
 * via la fonction : numpy.polynomial.hermite.hermgauss(10)
 * 
 */
double xi[10] = {-3.43615912, -2.53273167, -1.75668365, -1.03661083, -0.34290133,
        0.34290133,  1.03661083,  1.75668365,  2.53273167,  3.43615912};
 
/**
 * @brief Tableau contenant la valeurs des w_i pour un degré de 10
 * wi[i] = w_i
 * 
 * Pour obtenir ces valeurs, on a utiliser la bibliothèque numpy de Python
 * via la fonction : numpy.polynomial.hermite.hermgauss(10)
 */
double wi[10] = {7.64043286e-06, 1.34364575e-03, 3.38743945e-02, 2.40138611e-01,
       6.10862634e-01, 6.10862634e-01, 2.40138611e-01, 3.38743945e-02,
       1.34364575e-03, 7.64043286e-06};