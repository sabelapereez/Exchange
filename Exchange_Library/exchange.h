#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "dynamicvector.h"

/**
 * Returns change in infinite coins mode.
 *
 * @param x amount to be exchanged.
 * @param value vector with the valid values
 * @param solution vector with the returned coins
 * 
 */
int iexchange(int x, vectorD values, vectorD solution);

/**
 * Returns change depending on a stock.
 *
 * @param x amount to be exchanged.
 * @param value vector with the valid values
 * @param solution vector with the returned coins
 * @param stock vector with the available coins
 * 
 */
int lexchange(int x, vectorD values, vectorD solution, vectorD stock);

/**
 * Fills a vector from a file
 *
 * @param vector pointer to the vector to  fill
 * @param file file from wich the data is taken
 * @param tam size of the vector to create
 * 
 */
void VectorfromFile(vectorD *vector, FILE *file, int tam);

/**
 * Returns the number of lines of a file
 * 
 * @param file file whose lines we want to know
 * @param return number of lines of file
*/
int FileLines(FILE *file);


/**
 * Prints the actual stock
 * 
 * @param stock actual stock values
 * @param values values of the coins of the stock
*/
void ActualStock(vectorD stock, vectorD values);

/**
 * Prints the actual solution
 * 
 * @param solution actual solution values
 * @param values values of the coins of the stock
*/
void ActualSolution(vectorD solution, vectorD values);

#endif /*EXCHANGE_H*/
