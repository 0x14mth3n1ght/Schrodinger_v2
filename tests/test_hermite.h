#include <cxxtest/TestSuite.h>
#include <armadillo>
#include "../headers/hermite.h"

class TestHermiteSuite : public CxxTest::TestSuite 
{
  public:
  /**
   * @brief Test du calcul de la matrice Hermite avec n_max=5 et 
      \f$Z=\
          begin{matrix}
          1 & 5
          \end{matrix}}
      \f$
      
      Ce calcul normalement donne le résultat suivant :
      \f$
      \begin{matrix}
      1 &  2 &  2 & -4 & -20
      1 &  10 & 98 & 940 & 8812
      \end{matrix}
      \f$
   * 
   */
  void testHermite1( void )
  {
    const arma::mat res={{1, 2, 2, -4, -20}, {1, 10, 98, 940, 8812}};
    //On teste si ||hermiteMat - res||_infinie <= tolerance
    TS_TRACE("Début du test : calcul matrice hermite");
    TS_ASSERT(arma::norm(hermiteMat(4, {{1}, {5}}) - res, "inf") <= tolerance);
    TS_TRACE("Fin du test : calcul matrice hermite");
  }
  /**
   * @brief Test du calcul de la matrice Hermite avec n_max=0 et 
      Z=\begin{bmatrix}
          1 & 1 & 1
          \end{bmatrix}}
      
      Ce calcul normalement donne le résultat suivant :
      1
      1
      1
   * 
   */
  void testHermite2( void )
  {
    const arma::vec res={{1}, {1}, {1}};
    //On teste si ||hermiteMat - res||_infinie <= tolerance
    TS_TRACE("Début du test : calcul matrice hermite n=0");
    TS_ASSERT(arma::norm(hermiteMat(0, {{1}, {1}, {1}}) - res, "inf") <= tolerance);
    TS_TRACE("Fin du test : calcul matrice hermite n=0");
  }

  private:
  /**
   * @brief Variable tolérance globale
   * 
   */
  const double tolerance=1e-5;
};