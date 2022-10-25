#include "../headers/psiSolution.h"
#include <math.h>
#include "../headers/constantes.h"
#include "../headers/hermite.h"
#include <iostream>


psiSolution::psiSolution() : n_max(1)
{};

psiSolution::psiSolution(int n) : n_max(n)
{};


/**
 * @brief fonction factorielle
 *
 * @param n un entier
 * @return double, n!
 * @warning retourne 1 si n<0
 */
double fact(double n)
{
    if (n<=1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}


/**
 * @brief retourne une matrice à 2 dimensions, contenant les valeurs de psi_i(z) ;
 * La ième colonne correspond aux valeurs de psi_i évalué à une valeur de z différente à chaque ligne;
 * Les valeurs de z sont données par le vecteur [vecteurZ] placé en argument
 *
 * @param vecteurZ est le vecteur de rééls pour lesquels on possède les valeurs d'évaluation du polynome
 * d'Hermite
 * @return arma::mat Retourne une matrice de la forme suivante : exemple n_max=2
    \f[
    \begin{bmatrix}
    psi_0(z_0) & psi_1(z_0) & psi_2(z_0) \\
    psi_0(z_1) & psi_1(z_1) & psi_2(z_1) \\
    psi_0(z_2) & psi_1(z_2) & psi_2(z_2)
    \end{bmatrix}
    \f]
 */

arma::mat psiSolution::calculeSolution(const arma::vec &vecteurZ)
{
    //Récupération de la matrice Hermite
    arma::mat hermiteMatrix = hermiteMat(n_max, pow(m*omega/hbar,0.5)*vecteurZ);
    int tailleZ = vecteurZ.size();
    //On crée une matrice contenant le facteur manquant pour la valeur de psi_s(z)
    arma::mat res(tailleZ, n_max, arma::fill::zeros);

    double c;
    for(int n=0; n<n_max; n++)
    {
        c=pow((m*omega)/(pi*hbar),0.25) / sqrt(fact(n)*pow(2,n));

        res.col(n) = c * hermiteMatrix.col(n)
                     % (exp(-m*omega*square(vecteurZ)/(2*hbar)));
        // '%' est la multiplication termes à termes
    }

    return res;
};
/**
 * @brief Calcule la dérivée seconde de la solution en des points du vecteur. On peut utiliser
 * l'approximation discrète : https://fr.wikipedia.org/wiki/D%C3%A9riv%C3%A9e_seconde_discr%C3%A8te
 * @param Z Les points où seront calculés la dérivée seconde
 * @return arma::vec Les résultats de la dérivée seconde
 */
arma::vec psiSolution::derivee_seconde(const arma::vec& Z)
{
    //En fait on travaille avec des vecteurs colonnes, sauf que les résultats de psiSolution ici sont dans des vecteurs lignes, peut être on ferait
    //mieux d'utiliser des vecteurs lignes dans le futur uniquement
    arma::vec numerator=calculeSolution(Z + pas_der).row(0).as_col() + calculeSolution(Z - pas_der).row(0).as_col() - 2*calculeSolution(Z).row(0).as_col();
    arma::vec res=numerator/pow(pas_der, 2);
    return res;
};

/**
 * @brief Verifie l'orthonormalité des psi-solutions. On vérifie pour tous les
 * couples n,m <= n_max. On retourne les résultats dans une matrice dont les
 * numéros de lignes et les colonnes correspondent aux valeurs de n et m.
 *
 * @return arma::mat Retourne une matrice de la forme suivante : exemple n_max=1
    \f[
    \begin{bmatrix}
    \int \psi^*_0(z)\psi_0(z) dz & \int \psi^*_0(z)\psi_1(z) dz \\
    \int \psi^*_1(z)\psi_0(z) dz & \int \psi^*_1(z)\psi_1(z) dz \\
    \end{bmatrix}
    \f]
 */
arma::mat psiSolution::orthoMat()
{
    //Récupération de la matrice Hermite avec les valeurs de zi
    arma::mat hermiteMatrix = hermiteMat(n_max, zi);

    //On crée une matrice contenant les valeurs d'orthonormalité
    arma::mat res(n_max, n_max, arma::fill::zeros);

    int i,n,l;
    double sum,c;

    for (n=0; n<n_max; n++)
    {
        for (l=0; l<=n ; l++)
        {
            c = 1/sqrt(pi*pow(2,n+l)*fact(n)*fact(l));
            sum=0;
            // Calcul de la somme approximant l'intégrale
            for(i=0; i<degQuadrature; i++)
            {
                sum+=wi[i]*hermiteMatrix(i,n)*hermiteMatrix(i,l);
            }
            // On stock le résultat à la case correspondante dans la matrice
            res(n,l)=c*sum;
        }
    }

    // On copie les valeurs répétées dans le symétrique de la matrice
    // par rapport à la diagonale

    for (l=1; l<n_max; l++)
    {
        for (n=0; n<l ; n++)
        {
            res(n,l)=res(l,n);
        }
    }

    return res;
};

/**
 * @brief Calcule les niveaux d'énergie pour les solutions psi de l'équation à l'aide
 * de l'équation 1D
 *
 * @return arma::vec les niveaux d'énergies sous forme d'un vecteur colonne
 *  \f[Z=
        \begin{bmatrix}
        E_0 \\ E_1 \\ ... \\ E_{n_{max}}
        \end{bmatrix}
    \f]
 */
arma::vec psiSolution::energyMat()
{
    //On va calculer l'énergie à partir du point Z=0.1 pour tous les niveaux d'énergie
    arma::vec Z(n_max, arma::fill::zeros);
    double z_calcul=0.17;
    Z.fill(z_calcul);
    arma::vec derivee_2nde=derivee_seconde(Z);
    arma::vec calculPsi=calculeSolution(Z).row(0).as_col();

    arma::vec numerator=-pow(hbar, 2)*derivee_2nde / (2*m) + 1/2*m*pow(omega, 2)*pow(z_calcul, 2) * calculPsi;
    arma::vec denominator=calculPsi;

    return numerator / denominator;
}
