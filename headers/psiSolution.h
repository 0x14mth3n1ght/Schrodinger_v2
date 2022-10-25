#ifndef PSISOLUTION_H
#define PSISOLUTION_H

#include <armadillo>

class psiSolution
{
public :

    //Constructeurs
    psiSolution();
    psiSolution(int);

    /**
     * @brief Jusqu'à quel niveau d'énergie max seront calculés les solutions de l'équation
     *
     */
    int n_max;

    /**
     * @brief Calcule les psi-solutions
     *
     * @return arma::mat
     */
    arma::mat calculeSolution(const arma::vec&);

    /**
     * @brief Vérifie l'orthonormalité des psi-solutions
     *
     * @return arma::mat une matrice avec les résultats des différents produits scalaires des solutions
     */
    arma::mat orthoMat();

    /**
     * @brief Calcule la dérivée seconde de la solution en des points du vecteur. On peut utiliser
     * l'approximation discrète : https://fr.wikipedia.org/wiki/D%C3%A9riv%C3%A9e_seconde_discr%C3%A8te
     *
     * @return arma::vec Les résultats de la dérivée seconde en ces points.
     */
    arma::vec derivee_seconde(const arma::vec&);

    /**
     * @brief Calcule les niveaux d'énergie pour les solutions psi de l'équation à l'aide
     * de l'équation 1D
     *
     * @return arma::vec les niveaux d'énergies sous forme d'un vecteur colonne
     *  \f[Z=
            \begin{bmatrix}
            E_0 \\ E_1 \\ ... \\ E_{n_{max}}
            \end{bmatrix}
        \f]
     */
    arma::vec energyMat();
};

#endif