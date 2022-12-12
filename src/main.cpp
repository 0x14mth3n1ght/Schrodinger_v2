#include <iostream>
#include <armadillo>
#include "../headers/dataExporter.h"
#include "../headers/poly.h"
#include "../headers/basis.h"
#include "../headers/algorithms.h"

#define MINVALUE -5
#define MAXVALUE 5
#define STEPS 100

int main()
{
    Basis basis(1.935801664793151,      2.829683956491218,     14,     1.3);
    arma::vec r = {3.1, 2.3, 1.0, 0.0, 0.1, 4.3, 9.2, 13.7};
    arma::vec res00 = { 8.08521235111303e-02,
                        1.43887615825118e-01,
                        2.55045100912706e-01,
                        2.91450097294984e-01,
                        2.91061479407116e-01,
                        2.47240792330589e-02,
                        3.63004153921473e-06,
                        3.87659726026123e-12};
    (basis.rPart(r, 0, 0)).print("1e calcul rPart");
    res00.print("1e res rPart");
    arma::vec res82 = { 5.87858442372438e-02,
                        1.35240488413384e-02,
                        4.06810074575519e-05,
                        0.00000000000000e+00,
                        4.92817669085478e-13,
                        8.52011998934850e-02,
                        5.20525909328609e-02,
                        1.44615166152252e-05};
    (basis.rPart(r, 8, 2)).print("2e calcul rPart");
    res82.print("2e res rPart");
    arma::vec z = {-10.1, -8.4, -1.0, 0.0, 0.1, 4.3, 9.2, 13.7};
    arma::vec res001 = { 7.64546544834383e-04,
                        5.44886272162148e-03,
                        4.19492564268520e-01,
                        4.46522724110539e-01,
                        4.46243982300708e-01,
                        1.40736821086932e-01,
                        2.26186220733178e-03,
                        3.62929640195959e-06};
    (basis.zPart(z, 0)).print("1e calcul zPart");
    (res001).print("1e res zPart");
    arma::vec res15 = {-9.48674551049192e-02,
                    -1.40338701953237e-03,
                        1.85620628040096e-01,
                    -0.00000000000000e+00,
                    -3.93028470685214e-02,
                    -1.79526868763440e-01,
                        2.15604096600475e-01,
                        2.44977220882127e-01};
    (basis.zPart(z, 15)).print("2e calcul zPart");
    (res15).print("2e res zPart");

    arma::mat rho;
    rho.load("rho.arma", arma::arma_ascii);
    std::cout<<"taille de rho:"<<size(rho)<<"\n";
    arma::vec zVals=arma::linspace(MINVALUE, MAXVALUE, STEPS);
    arma::vec rVals=arma::linspace(MINVALUE, MAXVALUE, STEPS);

    arma::wall_clock timer;
    timer.tic();
    arma::mat res_0=naive(rho, zVals, rVals);
    std::cout<<"Algorithme naif : "<<timer.toc()<<"s\n";
    timer.tic();
    arma::mat res_1=algo_opti(rho, zVals, rVals);
    std::cout<<"Algorithme opti : "<<timer.toc()<<"s\n";

    return 0;
}
