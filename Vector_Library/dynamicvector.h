#ifndef DYNAMICVECTOR_H
#define DYNAMICVECTOR_H

typedef int TELEMENT; /*Vector data type*/
typedef void *vectorD;
/*Releases the memory occupied by the previous vector*/
void Release(vectorD *v1);
/*Allocates memory and returns the allocation to the vector*/
void CreateVector(vectorD *v1,int tam1);
/*Fills a vector position with a value*/
void FillVector(vectorD *v1,int position,TELEMENT value);
/*Initialize the vector with random numbers*/
void InitializeVectorRand(vectorD *v1);
/*Swaps the vector elements at index positions m and n*/
void swap(vectorD *v1, int m, int n);
/*Returns the TELEMENT that is at the indicated position of the vector*/
TELEMENT Return(vectorD v1, int position);
/*Returns the current size of the vector*/
int VectorSize(vectorD v1);

#endif /*DYNAMICVECTOR_H*/ 
