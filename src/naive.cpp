#include "../headers/poly.h"
#include "../headers/constantes.h"
#include <iostream>

Poly::Poly(){
    arma::mat mat(0,0,arma::fill::zeros);
    arma::cube cube(0,0,0,arma::fill::zeros);

    internHermiteMat = mat;
    internLaguerreMat = cube;
};

arma::mat result = arma::zeros(nbR, nbZ); // number of points on r- and z- axes
Basis basis(1.935801664793151, 2.829683956491218, 14, 1.3);

for (int m = 0; m < basis.mMax; m++)
{
  for (int n = 0; n < basis.nMax(m); n++)
  {
    for (int n_z = 0; n_z < basis.n_zMax(m, n); n_z++)
    {
      for (int mp = 0; mp < basis.mMax; mp++)
      {
        for (int np = 0; np < basis.nMax(mp); np++)
        {
          for (int n_zp = 0; n_zp < basis.n_zMax(mp, np); n_zp++)
          {
            arma::mat funcA = basis.basisFunc( m,  n,  n_z, zVals, rVals);
            arma::mat funcB = basis.basisFunc(mp, np, n_zp, zVals, rVals);
            result += funcA % funcB * rho(m, n, n_z, mp, np, n_zp); // mat += mat % mat * double
          }
        }
      }
    }
  }
}
