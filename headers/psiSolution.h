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

    arma::mat energyMat();
};

#endif