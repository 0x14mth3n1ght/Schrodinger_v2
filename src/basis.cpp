#include "../headers/basis.h"
#include "../headers/poly.h"
#include "../headers/constantes.h"
#include <math.h>
#include <assert.h>

/**
 * @brief Fonction nu définie dans le sujet du projet.
 * 
 * @param N paramètre >=0
 * @param Q paramètre >=0
 * @param i argument en entrée de la fonction
 * @return double Résultat de nu(i)
 */
double nu(const uint N, const double Q, const uint i)
{
    return (N+2)*pow(Q, 2.0/3.0) + 1/2 - i * Q;
}

/**
 * @brief Retourne l'indice mMax pour la troncature de base.
 * 
 * @todo Vérifier que les arguments soient positifs ou nuls.
 * 
 * @return L'indice mMax pour la troncature de base
 */
int calcule_mMax(const uint N, const double Q)
{
    //Vérifier que Q est bien positif ou nul
    assert (Q>=0);

    //Initialisation
    int res=1;
    double nu_i=nu(N, Q, 1);
    
    //On incrémente res tant que nu_i est supérieur/égal à 1
    for(int i=1; nu_i >= 1.0; i++)
    {
        nu_i=nu(N, Q, i);
        res=i;
    }
    return res;
};

/**
 * @brief Construct a new Basis:: Basis object
 * 
 * @param br paramètre de déformation de base
 * @param bz 2e paramètre de déformation de base
 * @param N paramètre de troncation de base
 * @param Q paramètre de troncation de base
 */
Basis::Basis(double br, double bz, uint N, double Q) 
{
    /* Préparation de la troncature */
    //Calcul de mMax
    mMax=calcule_mMax(N, Q);
    //Calcul de nMax
    nMax.zeros(mMax);
    for(uint m=0; m<mMax; m++)
    {
        nMax(m)=1.0/2.0 * (mMax - m - 1) + 1;
    }
    //Calcul de n_zMax
    //La taille de cette matrice est égale à mMax x (plus grand des nMax)
    n_zMax.zeros(mMax, nMax(0));
    for(uint m=0; m<mMax; m++)
    {
        for(uint n=0; n<nMax(m); n++)
        {
            n_zMax(m, n)=round(nu(N, Q, m + 2 * n + 1));
        }
    }
};

double fact(int n)
{
	if (n<=0) return 1;
	else return n*fact(n-1);
}

arma::mat Basis::zPart(int n_z, const arma::vec &zVals)
{
    //Récupération de la matrice Hermite
    Poly poly;
    poly.calcHermite(n_z,zVals/b_z);
    //poly.calcHermite(n) colonne, % mul terme à terme
    int tailleZ = zVals.size();
    //On crée une matrice contenant le facteur manquant pour la valeur de psi_s(z)
    arma::mat res(tailleZ, n, arma::fill::zeros);

    //Calculs des Z
    double c = 1/( sqrt(sqrt(pi)*fact(n_z)*pow(2,n_z) ) * sqrt(b_z));
    for(int k=0; k<n; k++)
    {
        res.col(k) = c * poly.hermite(k) % ( exp(-square(zVals)/(2*pow(b_z,2)) ));
    }

    return res;
}

arma::vec Basis::rPart(int m, int n, const arma::vec &rVals)
{
    //Récupération de la matrice Hermite
    Poly poly;
    poly.calcLaguerre(abs(m), n, pow( (rVals/b_r),2 );
    //poly.calcHermite(n) colonne, % mul terme à terme
    int tailleR = rVals.size();
    //On crée une matrice contenant le facteur manquant pour la valeur de psi_s(z)
    arma::mat res(tailleZ, n, arma::fill::zeros);

    double c = ( sqrt(fact(n)/(fact(n+abs(m))*pi))/b_r );

    for(int k=0; k<n; k++)
    {
        res.col(k) = c * poly.laguerre(k) % ( exp(-rVals/(2*pow(b_r,2)))*pow((rVals/b_r),abs(m)));
    }

    return res;

}

arma::mat Basis::basisFunc(int mp, int n, int n_z, const arma::vec &zVals, const arma::vec &rVals)
{
    //Récupération Z et R
    arma::vec zPart = zPart(int m, int n, const arma::vec &rVals);
    arma::vec rPart = rPart(int m, int n, const arma::vec &rVals);

    //Module (pas de theta) (?)
    return abs(zPart%rPart);

}
