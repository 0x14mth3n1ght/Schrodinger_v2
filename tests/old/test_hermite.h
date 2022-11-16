#include <cxxtest/TestSuite.h>
#include <armadillo>
#include "../headers/hermite.h"

class TestHermiteSuite : public CxxTest::TestSuite
{
private:
    /**
     * @brief Variable tolérance globale
     *
     */
    const double tolerance=1e-10;
public:
    /**
     * @brief Test du calcul de la matrice Hermite avec n_max=5 et
        \f[Z=
            \begin{bmatrix}
            1 \\ 5
            \end{bmatrix}
        \f]

        Ce calcul normalement donne le résultat suivant :
        \f[
        \begin{bmatrix}
        1 &  2 &  2 & -4 & -20 \\
        1 &  10 & 98 & 940 & 8812
        \end{bmatrix}
        \f]
     *
     */
    void testHermite1( void )
    {
        const arma::vec Z= {{1}, {5}};
        const arma::mat res= {{1, 2, 2, -4, -20}, {1, 10, 98, 940, 8812}};
        //On teste si ||hermiteMat - res||_infinie <= tolerance
        TS_TRACE("Début du test : calcul matrice hermite");
        TS_ASSERT(arma::norm(hermiteMat(4, Z) - res, "inf") <= tolerance);
        TS_TRACE("Fin du test : calcul matrice hermite");
    }
    /**
     * @brief Test du calcul de la matrice Hermite avec n_max=1 et
        \f[
        Z=\begin{bmatrix}
            1 \\ 5 \\ 2 \\ 8
            \end{bmatrix}
        \f]
        Ce calcul normalement donne le résultat suivant :
        \f[
          \begin{bmatrix}
            1 & 2\\
            1 & 10\\
            1 & 4\\
            1 & 16
            \end{bmatrix}
        \f]
     *
     */
    void testHermite2( void )
    {
        const arma::vec Z= {{1}, {5}, {2}, {8}};
        const arma::mat res= {{1, 2}, {1, 10}, {1, 4}, {1, 16}};
        //On teste si ||hermiteMat - res||_infinie <= tolerance
        TS_TRACE("Début du test : calcul matrice hermite n=1");
        TS_ASSERT(arma::norm(hermiteMat(1, Z) - res, "inf") <= tolerance);
        TS_TRACE("Fin du test : calcul matrice hermite n=1");
    }

};