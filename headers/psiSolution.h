#ifndef PSISOLUTION_H
#define PSISOLUTION_H

#include <armadillo>

class psiSolution
{
public :

    //Constructeurs
    psiSolution();
    psiSolution(int);

    //Valeur de n_max
    int n_max;

    //Calcule les psi-solutions
    arma::mat calculeSolution(const arma::vec&);

    //Vérifie l'orthonormalité des psi-solutions
    arma::mat orthoMat();

    /**
     * @brief Calcule la dérivée seconde de la solution en des points du vecteur. On peut utiliser
     * l'approximation discrète : https://fr.wikipedia.org/wiki/D%C3%A9riv%C3%A9e_seconde_discr%C3%A8te
     * 
     * @return arma::vec Les résultats de la dérivée seconde en ces points.
     */
    arma::vec derivee_seconde(const arma::vec&);

    arma::vec energyMat();
};

#endif