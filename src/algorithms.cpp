#include "../headers/basis.h"
#include "../headers/algorithms.h"
#include "../headers/constantes.h"
#include <iostream>
#include <armadillo>

arma::mat naive(arma::mat rho, arma::vec zVals, arma::vec rVals)
{
  arma::mat result = arma::zeros(rVals.size(), zVals.size()); // number of points on r- and z- axes
  Basis basis(1.935801664793151, 2.829683956491218, 14, 1.3);

  //Il faut incrémenter a et b à la fin de la dernière boucle qui change funcA et funcB respectivement
  int a=0;
  int b=0;
  for (int m = 0; m < basis.mMax; m++)
  {
    for (int n = 0; n < basis.nMax(m); n++)
    {
      for (int n_z = 0; n_z < basis.n_zMax(m, n); n_z++)
      {
        b=0;
        for (int mp = 0; mp < basis.mMax; mp++)
        {
          for (int np = 0; np < basis.nMax(mp); np++)
          {
            for (int n_zp = 0; n_zp < basis.n_zMax(mp, np); n_zp++)
            {
              arma::mat funcA = basis.basisFunc( m,  n,  n_z, zVals, rVals);
              arma::mat funcB = basis.basisFunc(mp, np, n_zp, zVals, rVals);
              result += rho(a, b) * funcA % funcB; // mat += mat % mat * double
              b++;
            }
          }
        }
        a++;
      }
    }
  }
  return result;
}