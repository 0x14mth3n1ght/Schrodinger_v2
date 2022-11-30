#include <armadillo>

#ifndef BASIS
#define BASIS

/**
 * @brief Retourne l'indice mMax pour la troncature de base.
 * 
 * @todo Vérifier que les arguments soient positifs ou nuls.
 * 
 * @return L'indice mMax pour la troncature de base
 */
int calcule_mMax(const uint, const double);

/**
 * @brief Classe pour les fonctions de base, et la troncature de base
 * 
 */
class Basis
{
    public:
        /**
         * @brief Construit un objet servant à réaliser la troncature de base et à récupérer les composants Z et R de la densité locale.
         * 
         */
        Basis(double, double, uint, double);

        /**
         *  Troncature de base
         * 
         */

        /**
         * @brief Indice de base max des m
         * 
         */
        int mMax;
        /**
         * @brief Matrice contenant les indices de base max des n.
         * 
         * 
         */
        arma::ivec nMax;
        /**
         * @brief Matrice contenant les indices de base max des n pour la partie z.
         * 
         */
        arma::mat n_zMax;

        /**
         * Composantes R et Z de la densité locale (Base cylindrique)
         * 
        */

        /**
         * @brief Composante R de la densité locale. 
         * 
         * @return arma::vec Le vecteur contenant les composantes R de la densité locale pour un vecteur donné contenant les coordonnées r.
         */
        arma::vec rPart(arma::vec, int, int);
        /**
         * @brief Composante Z de la densité locale. 
         * 
         * @return arma::vec Le vecteur contenant les composantes Z de la densité locale pour un vecteur donné contenant les coordonnées z.
         */
        arma::vec zPart(arma::vec, int);

        /*
        * @brief Matrice des phi
        *
        * @return arma::vec Le vecteur contenant les composantes phi
        */
        arma::mat basisFunc(int, int, int, const arma::vec &, const arma::vec &);

    private:
        double b_z,b_r;
        
};
#endif
