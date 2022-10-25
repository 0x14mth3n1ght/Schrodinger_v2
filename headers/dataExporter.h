#include <armadillo>
#include <iostream>
#include <fstream>

#ifndef EXPORTER
#define EXPORTER
/**
 * @brief Exporte les résultats d'une fonction sous forme d'un fichier .csv dans ./target (Pour les visualiser sur matplotlib par exemple)
 *
 * @param X tableau des abscisses non nul
 * @param Y tableau des ordonnées, doit avoir le même nombre de lignes que X
 * @param nom Le nom du fichier.
 */
void exportToCsv(arma::vec X, arma::mat Y, char* nom);

#endif