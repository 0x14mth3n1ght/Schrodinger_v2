#include <cxxtest/TestSuite.h>
#include <armadillo>
#include "../headers/hermite.h"
#include "../headers/psiSolution.h"

class TestProprietes : public CxxTest::TestSuite
{
private:
    /**
     * @brief Variable tolérance globale
     *
     */
    const double tolerance=1e-10;
public:
    /**
     * @brief Test de l'orthonormalité des solutions de l'équation.
     * 
     * On génère la matrice des produits scalaires des différentes solutions et on compare
     * avec la matrice identitée.
     *
     */
    void testOrthonormalite( void )
    {
        psiSolution solutions(10);
        const arma::mat mat_prod_scalaires=solutions.orthoMat();
        const arma::mat res= arma::eye(arma::size(Z));
        //On teste si ||hermiteMat - res||_infinie <= tolerance
        TS_TRACE("Début du test : calcul matrice hermite");
        TS_ASSERT(arma::norm(mat_prod_scalaires - res, "inf") <= tolerance);
        TS_TRACE("Fin du test : calcul matrice hermite");
    }

};