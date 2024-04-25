#include <stdlib.h>
#include <stdio.h>
#include "dynamicvector.h"

/*Returns change in infinite coins mode*/
int iexchange(int x, vectorD values, vectorD solution){
    unsigned long int n = VectorSize(values);
    for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
    int i = 0, suma = 0;
    while (suma < x && i < n)
        if (suma + Return(values, i) <= x){
            TELEMENT aux = Return(solution, i);
            FillVector(&solution, i, aux + 1);
            suma+=valor[i];
        }
        else
            i++;
    if (suma == x) return 1;
    else{
        for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
        return 0;
    }
}
