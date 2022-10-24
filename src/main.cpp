#include <iostream>
#include <armadillo>
#include "../headers/dataExporter.h"
#include "../headers/hermite.h"

int main()
{
    //std::cout << "Hello world\n";
    //arma::mat A={{1,2},{3,4}};
    //A.print("Matrice");
    hermiteMat(1, {{1}, {5}}).print("Matrice Hermite n_max=1, z=(1 5)");
    return 0;
}