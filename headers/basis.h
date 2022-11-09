#include <armadillo>

#ifndef BASIS
#define BASIS

/**
 * @brief 
 * 
 */
class Basis
{
    public:
        /**
         * @brief Construit un objet fonction base
         * 
         */
        Basis(double, double, int, double);
        /**
         * @brief Indice de base max des m
         * 
         */
        int mMax;
        /**
         * @brief Matrice contenant les indices de base max des n.
         * 
         * 
         */
        arma::ivec nMax;
        /**
         * @brief Matrice contenant les indices de base max des n pour la partie z.
         * 
         */
        arma::mat n_zMax;
        /**
         * @brief 
         * 
         * @return arma::vec 
         */
        arma::vec rPart(arma::vec, int, int);
        /**
         * @brief 
         * 
         * @return arma::vec 
         */
        arma::vec zPart(arma::vec, int);
    private:
        
};
#endif