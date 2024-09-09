/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P1)
Full Name  : Chaerin Yoo
Student ID#: 102998234
Email      : cyoo10@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_NUMBER_OF_ITEMS 10
#define MIN_NUMBER_OF_ITEMS 1

int main(void)
{
	double income;
	int numOfitems, i;

	double cost[MAX_NUMBER_OF_ITEMS];
	int priority[MAX_NUMBER_OF_ITEMS];
	char finance[MAX_NUMBER_OF_ITEMS];

	double total = 0.0;

	const double MIN_INCOME = 500.00;
	const double MAX_INCOME = 400000.00;
	const double MIN_COST = 100.00;

	int valid;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");
	printf("\n");

	do
	{
		valid = 1;
		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		if (income < MIN_INCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", MIN_INCOME);
			valid = 0;
		}
		else if (income > MAX_INCOME)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", MAX_INCOME);
			valid = 0;
		}
		printf("\n");
	} while (valid == 0);

	do
	{
		valid = 1;
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &numOfitems);

		if (numOfitems<MIN_NUMBER_OF_ITEMS || numOfitems > MAX_NUMBER_OF_ITEMS)
		{
			printf("ERROR: List is restricted to between %d and %d items.\n", MIN_NUMBER_OF_ITEMS, MAX_NUMBER_OF_ITEMS);
			valid = 0;
		}
		printf("\n");
	} while (valid == 0);



	for (i = 0; i < numOfitems; i++)
	{
		printf("Item-%d Details:\n", i + 1);


		do
		{
			valid = 1;
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			if (cost[i] < MIN_COST)
			{
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
				valid = 0;
			}

		} while (valid == 0);


		do
		{
			valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if (priority[i] < 1 || priority[i]>3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				valid = 0;
			}

		} while (valid == 0);

		do
		{
			valid = 1;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);

			if (finance[i] != 'y' && finance[i] != 'n')
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				valid = 0;
			}
		} while (valid == 0);


		total += cost[i];
		printf("\n");

	}

	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < numOfitems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total);

	printf("Best of luck in all your future endeavours!\n");


	return 0;
}

/*
	HELPER: printf formatting statements....
	=========================================

	Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");

		printf("%3d  %5d    %5c    %11.2lf\n", ...


	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/