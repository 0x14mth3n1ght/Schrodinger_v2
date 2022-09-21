#include <iostream>
#include <armadillo>

int main()
{
    std::cout << "Hello world\n";
    arma::mat A={{1,2},{3,4}};
    A.print("Matrice");
    return 0;
}