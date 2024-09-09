/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Chaerin Yoo
Student ID#: 102998234
Email      : cyoo10@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apples, oranges, pears, tomatos, cabbages;
    int continueshopping;
    int pick;


    do
    {
        printf("Grocery Shopping\n");
        printf("================\n");

        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apples);
            if (apples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apples < 0);
        printf("\n");

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &oranges);
            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (oranges < 0);
        printf("\n");

        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears);
            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pears < 0);
        printf("\n");

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatos);
            if (tomatos < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomatos < 0);
        printf("\n");

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages);
            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbages < 0);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n");
        printf("\n");

        while (apples > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pick);
            if (apples < pick)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
            }
            else if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }

            else
            {
                apples -= pick;
                if (apples > 0)
                {
                    printf("Looks like we still need some APPLES...\n");
                }
                else
                {
                    printf("Great, that's the apples done!\n\n");
                }

            }
        } 

        while (oranges > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &pick);

            if (oranges < pick)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
            }
            else if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else
            {
                oranges -= pick;
                if (oranges > 0)
                {
                    printf("Looks like we still need some ORANGES...\n");
                }
                else
                {
                    printf("Great, that's the oranges done!\n\n");
                }
            }
        } 

        while (pears > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pick);

            if (pears < pick)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
            }
            else if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else
            {
                pears -= pick;
                if (pears > 0)
                {
                    printf("Looks like we still need some PEARS...\n");

                }
                else
                {
                    printf("Great, that's the pears done!\n\n");
                }
            }

        }

        while (tomatos > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pick);

            if (tomatos < pick)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatos);
            }
            else if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else
            {
                tomatos -= pick;
                if (tomatos > 0)
                {
                    printf("Looks like we still need some TOMATOES...\n");
                }
                else
                {
                    printf("Great, that's the tomatoes done!\n\n");
                }
            }
        }

        while (cabbages > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pick);

            if (cabbages < pick)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
            }
            else if (pick <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else
            {
                cabbages -= pick;
                if (cabbages > 0)
                {
                    printf("Looks like we still need some CABBAGES...\n");
                }
                else
                {
                    printf("Great, that's the cabbages done!\n\n");
                }
            }
        }

        printf("All the items are picked!\n");
        printf("\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &continueshopping);
        printf("\n");

    } while (continueshopping != 0);
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
