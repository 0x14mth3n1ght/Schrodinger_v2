#include "../headers/basis.h"
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

arma::mat Basis::basisFunc(int mp, int n, int n_z, const arma::vec &zVals, const arma::vec &rVals)
{
    //Récupération de la matrice Hermite
    arma::mat hermiteMatrix = hermiteMat(n_z,zVals/bz);
    int tailleZ = zVals.size();
    int tailleR = rVals.size();
    //On crée une matrice contenant le facteur manquant pour la valeur de psi_s(z)
    arma::mat res(tailleZ, n_max, arma::fill::zeros);

    
    return res;

}
