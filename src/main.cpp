#include <iostream>
#include <armadillo>
#include "../headers/dataExporter.h"
#include "../headers/poly.h"

int main()
{
    Poly poly;
    arma::vec zVals, calcVals, targetVals;
    zVals = {-3.1, -2.3, -1.0, -0.3, 0.1, 4.3, 9.2, 13.7};
    poly.calcHermite(6, zVals); // compute Hermite polynomials for n in {0 ... 5}
    calcVals   = poly.hermite(4); // n = 4
    calcVals.print("hermite n=4");
    targetVals = {  1.02835360e+03,  2.05825600e+02, -2.00000000e+01,  7.80960000e+00,
                    1.15216000e+01,  4.59456160e+03,  1.10572154e+05,  5.54643458e+05};
    targetVals.print("targetvals");
    zVals = {0.1, 0.3, 1.2, 1.8, 2.0, 2.5, 7.1, 11.1};
    poly.calcLaguerre(6, 4, zVals); // compute generalized Laguerre polynomials for m in {0 ... 5} and n in {0 ... 3}
    calcVals   = poly.laguerre(4, 2); // m = 4, n = 2
    calcVals.print("laguerre m=4 n=2");
    targetVals = {  14.405,  13.245,  8.52 ,  5.82 ,  5.,  3.125,  -2.395,  10.005};
    targetVals.print("targetvals");
    return 0;
}
