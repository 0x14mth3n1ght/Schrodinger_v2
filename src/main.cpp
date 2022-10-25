#include <iostream>
#include <armadillo>
#include "../headers/dataExporter.h"
#include "../headers/hermite.h"
#include "../headers/psiSolution.h"

int main()
{
    //std::cout << "Hello world\n";
    //arma::mat A={{1,2},{3,4}};
    //A.print("Matrice");
    hermiteMat(1, {{1}, {5}}).print("Matrice Hermite n_max=1, z=(1 5)");

    psiSolution testpsi(5);
    arma::mat res;
    arma::mat energy;
    arma::vec vec(100, arma::fill::zeros);
    double step= 10./100.;
    vec[0] = -5.;
    for (int i = 1; i<100; i++)
    {
        vec[i] = vec[i-1]+step;
    }
    vec.print("voici le vecteur des valeurs de z");
    res = testpsi.calculeSolution(vec);
    res.print("matrice test psisolution");
    char filename[255]="psiSolutions";
    exportToCsv(vec, res, filename);
    testpsi.orthoMat().print("ortho");
    testpsi.energyMat().print("energie");
    return 0;
}
