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
    const double tolerance=1e-3;
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
        const arma::mat res= arma::eye(arma::size(mat_prod_scalaires));
        //On teste si ||mat_prod_scalaires - res||_infinie <= tolerance
        TS_TRACE("Début du test : calcul matrice orthonormal");
        TS_ASSERT(arma::norm(mat_prod_scalaires - res, "inf") <= tolerance);
        TS_TRACE("Fin du test : calcul matrice orthonormal");
    }

    /**
     * @brief Test des énergies déduits des solutions de l'équation.
     * 
     */
    void testEnergies( void )
    {
        psiSolution solutions(10);
        const arma::vec energies=solutions.energyMat();
        const arma::vec res= arma::eye(size(energies));
        
        res(0)=hbar * omega /2;
        for(int i=1;i<size(res);i++)
            res(i)=res(0) + hbar * omega * i;
        
        TS_TRACE("Début du test : énergies");
        TS_ASSERT(arma::norm(energies - res, "inf") <= tolerance);
        TS_TRACE("Fin du test : énergies");
    }

};
