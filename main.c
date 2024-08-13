#include <stdio.h>
#include <stdlib.h>
#include "./Vector_Library/dynamicvector.h"
#include "./Exchange_Library/exchange.h"

int main(int argc, char** argv){
    char mode, currency[20], nstock[100];
    int tam, success, money = -1;
    vectorD values, solution, stock;
    FILE *fvalues;

    //Parameter control
    if (argc > 2){
        printf("Error in the entered parameters.\n");
        exit(1);
    }
    else if (argc == 2){
        if ((fvalues = fopen(argv[1], "r")) == NULL){
            perror("Error reading the file.\n");
            exit(2);
        }
        tam = FileLines(fvalues);
        //Read currency
        fseek(fvalues, 0, SEEK_SET);
        fscanf(fvalues, "%s", currency);
        printf("You are going to work with %s.\n", currency);
        //Create values vector
        VectorfromFile(&values, fvalues, tam-1);
        fclose(fvalues); 
    }
    else{
        printf("DEFAULT MODE: Euros\n");
        //Creation of the default values vector
        CreateVector(&values, 8);
        FillVector(&values, 0, 200);
        FillVector(&values, 1, 100);
        FillVector(&values, 2, 50);
        FillVector(&values, 3, 20);
        FillVector(&values, 4, 10);
        FillVector(&values, 5, 5);
        FillVector(&values, 6, 2);
        FillVector(&values, 7, 1);
    }

    //Select mode
    printf("----------------------MODES----------------------\n");
    printf("- A -> Infinite currencies\t- B -> Limited currencies\n");
    printf("Choose mode: ");
    scanf(" %c", &mode);

    //Give exchanges
    switch(mode){
        case 'A':
        case 'a':
            do {
                printf("\nEnter 0 to exit the program.\n");
                printf("Enter the amount to be returned: ");
                scanf("%d", &money);
                //Exit
                if (money == 0){
                    printf("Exiting the program...\n");
                    break;
                }
                CreateVector(&solution, VectorSize(values));
                success = iexchange(money, values, solution);
                if (success == 1){
                    ActualSolution(solution, values);
                }
                else if (success == 0){
                    printf("Solution not found.\n");
                }
            } while (money != 0);
            break;

        case 'B':
        case 'b':
            int option;
            FILE *fstock;
            printf("Enter the file with the stock: ");
            scanf("%s", nstock);
            if ((fstock = fopen(nstock, "r")) == NULL){
                perror("Error reading the file.\n");
                exit(2);
            }
            tam = FileLines(fstock);
            fseek(fstock, 0, SEEK_SET);
            //Create stock vector
            VectorfromFile(&stock, fstock, tam);
            fclose(fstock);

            //Prove values and stock have same number of items
            if (VectorSize(values) != VectorSize(stock)){
                perror("Number of values and number of coins in stock are different.\n");
                exit(3);
            }

            do{
                ActualStock(stock, values);
                printf("Enter 0 to return change, 1 to add stock or 2 to exit: ");
                scanf(" %d", &option);
                switch (option){
                case 0:
                    printf("Enter the amount to be returned: ");
                    scanf("%d", &money);
                    CreateVector(&solution, VectorSize(values));
                    success = lexchange(money, values, solution, stock);
                    if (success == 1){
                        ActualSolution(solution, values);
                    }
                    else if (success == 0){
                        printf("Solution not found.\n");
                    }
                    break;
                
                case 1:
                    TELEMENT aux;
                    for(int j = 0; j < VectorSize(stock); j++){
                        aux = Return(stock, j);
                        FillVector(&stock, j, aux + 10);
                    }
                    break;

                case 2:
                    //Stock update when exiting
                    printf("Exiting the program...\n");
                    if ((fstock = fopen(nstock, "w")) == NULL){
                        perror("Error reading the file.\n");
                        exit(2);
                    }
                    for(int j = 0; j < VectorSize(stock); j++){
                        fprintf(fstock, "%d\n", Return(stock, j));
                    }
                    fclose(fstock);
                    break;

                default:
                    printf("Wrong option.\n");
                    break;

                }

            } while (option != 2);
            break;

        default:
            printf("Wrong mode.\n");
            break;
    }
    return 0;
}