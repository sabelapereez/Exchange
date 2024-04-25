#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "dynamicvector.h"

/**
 * Returns change in infinite coins mode.
 *
 * @param x amount to be exchanged.
 * @param value vector with the valid values
 * @param value vector with the returned coins
 * 
 */
int iexchange(int x, vectorD values, vectorD solution);

#endif /*EXCHANGE_H*/