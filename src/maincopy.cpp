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
    targetVals = { -4.76676832e+03, -3.88909760e+02,  8.00000000e+00, -3.17577600e+01,
                1.18403200e+01,  3.48375818e+04,  1.98557479e+06,  1.50339793e+07};
    targetVals.print("targetvals");
    zVals = {0.1, 0.3, 1.2, 1.8, 2.0, 2.5, 7.1, 11.1};
    poly.calcLaguerre(6, 4, zVals); // compute generalized Laguerre polynomials for m in {0 ... 5} and n in {0 ... 3}
    calcVals   = poly.laguerre(4, 2); // m = 4, n = 2
    calcVals.print("laguerre m=4 n=2");
    targetVals = {  14.405,  13.245,  8.52 ,  5.82 ,  5.,  3.125,  -2.395,  10.005};
    targetVals.print("targetvals");
    return 0;
}
