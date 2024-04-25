#include <stdio.h>
#include <stdlib.h>
#include "dynamicvector.h"
#include "exchange.h"

int main(int argc, char** argv){
    char mode, currency;

    //Select mode
    printf("----------------------MODES----------------------\n");
    printf("- A -> Infinite coins\t- B -> Limited coins\n");
    printf("Choose mode: ");
    scanf(" %c", &mode);

    //Select currency
    printf("----------------------CURRENCY----------------------\n");
    printf("- A -> Euro\t- B -> Dollar\t- E -> Exit\n");
    printf("Choose mode: ");
    scanf(" %c", &currency);

    //Create values vector
    switch(currency){
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }

    //Give exchanges
    switch(mode){
    case 'A':
    case 'a':
        int money;
        vectorD solution;
        do{
            printf("Enter the amount to be returned: ");
            scanf("%d", &money);
            CreateVector(&solution, VectorSize(values));
            //Call iexchange
        } while(money != 0);
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