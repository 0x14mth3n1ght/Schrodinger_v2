#include <armadillo>
#include <iostream>
#include <fstream>

#ifndef EXPORTER
#define EXPORTER
/**
 * @brief Exporte les résultats d'une fonction sous forme d'un fichier .csv dans ./target (Pour les visualiser sur matplotlib par exemple)
 *
 * @param X tableau des abscisses non nul
 * @param Y tableau des ordonnées, de même taille que X
 * @param nom Le nom du fichier.
 */
void exportToCsv(arma::vec X, arma::vec Y, char* nom);

#endif