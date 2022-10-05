#ifndef PSISOLUTION_H
#define PSISOLUTION_H

#include <armadillo>

class psiSolution
{
public :

    int n_max;

    arma::mat calculeSolution(arma::mat, int, arma::vec);

};

#endif