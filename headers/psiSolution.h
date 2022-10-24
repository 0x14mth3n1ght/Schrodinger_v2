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

    //
    arma::mat calculeSolution(const arma::vec&);

};

#endif