#include <stdlib.h>
#include <stdio.h>
#include "dynamicvector.h"

/*Returns change in infinite coins mode*/
int iexchange(int x, vectorD values, vectorD solution){
    TELEMENT aux;
    int n = VectorSize(values);
    //Inicialize vector solution
    for (int i = 0; i < n; i++) FillVector(&solution, i, 0); 
    int i = 0, suma = 0;
    //Calculate the coins with a greedy algorithm
    while (suma < x && i < n)
        if (suma + Return(values, i) <= x){
            aux = Return(solution, i);
            FillVector(&solution, i, aux + 1);
            suma += Return(values, i);
        }
        else
            i++;
    //Check a solution was found
    if (suma == x) return 1;
    else{
        for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
        return 0;
    }
}

/*Returns change depending on a stock*/
int lexchange(int x, vectorD values, vectorD solution, vectorD stock){
    TELEMENT aux, aux2;
    int n = VectorSize(values);
    //Inicialize vector solution
    for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
    int i = 0, suma = 0;
    //Calculate the coins with a greedy algorithm and taking in account the stock
    while (suma < x && i < n){
        int actvalue = Return(values, i);
        int actstock = Return(stock, i);
        if ((suma + actvalue <= x) && (actstock > 0)){
            aux = Return(solution, i);
            FillVector(&solution, i, aux + 1);
            suma += actvalue;
            aux = actstock;
            FillVector(&stock, i, aux - 1);
        }
        else
            i++;
    }        
    //Check if a solution was found
    if (suma == x) return 1;
    else{
        //Get the stock back
        for (i = 0; i < n; i++){
            aux = Return(solution, i);
            aux2 = Return(stock, i);
            FillVector(&stock, i, aux2 + aux);
        }
        for (int i = 0; i < n; i++) FillVector(&solution, i, 0);
        return 0;
    }
}

/*Fills a vector from a file*/
void VectorfromFile(vectorD *vector, FILE *file, int tam){
    int n = 0, aux;
    CreateVector(vector, tam);
    while(fscanf(file, "%d", &aux) == 1){
            FillVector(vector, n, aux);
            n++;
    }
}

/*Returns the number of lines of a file*/
int FileLines(FILE *file){
    int n = 0;
    char bin[200];
    fseek(file, 0, SEEK_SET);
    while(fgets(bin, 200, file) != NULL){
        n++;
    }
    return n;
}

/*Prints the actual stock*/
void ActualStock(vectorD stock, vectorD values){
    printf("\nActual stock:\n");
    for(int j = 0; j < VectorSize(stock); j++){
        printf("%d coins of %d.\n", Return(stock, j), Return(values, j));
    }
}

/*Prints the actual stock*/
void ActualSolution(vectorD solution, vectorD values){
    printf("\nCoins to be returned:\n");
    for(int j = 0; j < VectorSize(solution); j++){
        printf("%d currencys of %d.\n", Return(solution, j), Return(values, j));
    }
}