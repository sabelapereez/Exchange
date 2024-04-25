#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int TELEMENT;

typedef struct {
    TELEMENT *data;
    unsigned long int tam;
} STVECTOR;

typedef STVECTOR *vectorD;

/*Releases the memory occupied by the previous vector*/
void Release(vectorD *v1){
    if (*v1 != 0){
        free((*v1)->data);
        free(*v1);
        *v1 = 0;
        printf("Vector releasedn");
    }
    else{
        printf("No memory allocated to any vector\n");
    }
}

/*Allocates memory and returns the allocation to the vector*/
void CreateVector(vectorD *v1, unsigned long int tam1) {
    Release(v1);
    *v1 = (vectorD) malloc(sizeof (STVECTOR));
    (*v1)->data = (TELEMENT*) malloc(tam1 * sizeof (TELEMENT));
    (**v1).tam = tam1;
}

/*Fills a vector position with a value*/
void FillVector(vectorD *v1, unsigned long int position, TELEMENT value) {
    *( (*v1) ->data + position) = value;
}

/*Initialize the vector with random numbers*/
void initializeVectorRand(vectorD *v1){
    unsigned long int n = 0;
    srand(time(NULL));
    for(unsigned long int i = 0; i < (*v1)->tam; i++){
        *((*v1) -> data + n) = rand();
        n += 1; 
    }
}

/*Swaps the vector elements at index positions m and n*/
void swap(vectorD *v1, unsigned long int m, unsigned long int n){
    unsigned long int aux = *((*v1) -> data + n);
    *((*v1) -> data + n) = *((*v1) -> data + m);
    *((*v1) -> data + m) = aux;
}

/*Returns the TELEMENT that is at the indicated position of the vector*/
TELEMENT Return(vectorD v1, unsigned long int position){
    if (v1 != 0 && position < v1->tam){
        return *(v1->data+position);
    }
    else{
        printf("That element does not exist\n");
        return 0;
    }
}

/*Returns the current size of the vector*/
unsigned long int VectorSize(vectorD v1){
        return v1->tam;
}
