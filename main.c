#include <stdio.h>
#include <stdlib.h>
#include "dynamicvector.h"
#include "exchange.h"

int main(int argc, char** argv){
    char mode, currency[20], bin[200], nstock[100];
    int n = 0;
    vectorD values, solution;
    FILE *fvalues;
    TELEMENT aux;

    if (argc > 2){
        printf("Error in the entered parameters.\n");
        exit(1);
    }

    if (argc == 2){
        if ((fvalues = fopen(argv[1], "r")) == NULL){
            perror("Error en la lectura del archivo.\n");
            exit(2);
        }
        while(fgets(bin, 200, fvalues) != NULL){
            n++;
        }
        CreateVector(&values, n-1);
        fseek(fvalues, 0, SEEK_SET);
        fscanf(fvalues, "%s", currency);
        printf("You are going to work with %s.\n", currency);
        n = 0;
        while(fscanf(fvalues, "%d", &aux) == 1){
            FillVector(&values, n, aux);
            n++;
        }
        fclose(fvalues); 
    }
    else{
        printf("DEFAULT MODE: Euros\n");
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
            int money = -1, success;
            do {
                printf("\nEnter 0 to exit the program.\n");
                printf("Enter the amount to be returned: ");
                scanf("%d", &money);
                if (money == 0){
                    break;
                }
                CreateVector(&solution, VectorSize(values));
                success = iexchange(money, values, solution);
                if (success == 1){
                    printf("\nCoins to be returned:\n");
                    for(int j = 0; j < VectorSize(solution); j++){
                        printf("%d currencys of %d.\n", Return(solution, j), Return(values, j));
                    }
                }
                else if (success == 0){
                    printf("Solution not found.\n");
                }
            } while (money != 0);
            break;

        case 'B':
        case 'b':
            FILE *fstock;
            vectorD stock;
            printf("Enter the file with the stock: \n");
            scanf("%s", nstock);
            if ((stock = fopen(nstock, "r")) == NULL){
                perror("Error en la lectura del archivo.\n");
                exit(2);
            }
            CreateVector(&stock, VectorSize(values));
            fseek(fstock, 0, SEEK_SET);
            n = 0;
            while(fscanf(fstock, "%d", &aux) == 1){
                FillVector(&stock, n, aux);
                n++;
            }
            fclose(fvalues);

            do{
                printf("\nEnter 0 to exit the program.\n");
                printf("Enter the amount to be returned: ");
                scanf("%d", &money);
                if (money == 0){
                    //Update file
                    break;
                }
                CreateVector(&solution, VectorSize(values));
                //Print stock
                //Allow to add stock
            } while (money != 0);
            break;

        case 'E':
        case 'e':
            printf("Exiting the program");
            break;

        default:
            printf("Wrong mode\n");
            break;
    }
    return 0;
}