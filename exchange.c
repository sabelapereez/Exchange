#include <stdlib.h>
#include <stdio.h>
#include "dynamicvector.h"

/*Returns change in infinite coins mode*/
int iexchange(int x, vectorD values, vectorD solution){
    int n = VectorSize(values);
    for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
    int i = 0, suma = 0;
    while (suma < x && i < n)
        if (suma + Return(values, i) <= x){
            TELEMENT aux = Return(solution, i);
            FillVector(&solution, i, aux + 1);
            suma += Return(values, i);
        }
        else
            i++;
    if (suma == x) return 1;
    else{
        for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
        return 0;
    }
}

//Adapt to stock
int fexchange(int x, vectorD values, vectorD solution, vectorD stock){
    int n = VectorSize(values);
    for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
    int i = 0, suma = 0;
    while (suma < x && i < n)
        if (suma + Return(values, i) <= x){
            //Only if stock available
            TELEMENT aux = Return(solution, i);
            FillVector(&solution, i, aux + 1);
            suma += Return(values, i);
        }
        else
            i++;
    if (suma == x) return 1;
    else{
        for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
        return 0;
    }
    //Update stock
}
