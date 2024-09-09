/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

	char type1, type2, type3;
	int bagWeight1, bagWeight2, bagWeight3;
	char cream1, cream2, cream3;

	char strength;
	char likeCream;
	int dailyServings;


	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n");
	printf("\n");
	printf("Enter the coffee product information being sold today...\n");
	printf("\n");

	printf("COFFEE-1...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &type1);
	printf("Bag weight (g): ");
	scanf("%d", &bagWeight1);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &cream1);
	printf("\n");

	printf("COFFEE-2...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &type2);
	printf("Bag weight (g): ");
	scanf("%d", &bagWeight2);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &cream2);
	printf("\n");

	printf("COFFEE-3...\n");
	printf("Type ([L]ight,[M]edium,[R]ich): ");
	scanf(" %c", &type3);
	printf("Bag weight (g): ");
	scanf("%d", &bagWeight3);
	printf("Best served with cream ([Y]es,[N]o): ");
	scanf(" %c", &cream3);
	printf("\n");

	printf("---+------------------------+---------------+-------+\n");
	printf("   |    Coffee              |   Packaged    | Best  |\n");
	printf("   |     Type               |  Bag Weight   | Served|\n");
	printf("   +------------------------+---------------+ With  |\n");
	printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
	printf("---+------------------------+---------------+-------|\n");
	printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (type1 == 'L' || type1 == 'l'), (type1 == 'M' || type1 == 'm'), (type1 == 'R' || type1 == 'r'), bagWeight1, bagWeight1 / GRAMS_IN_LBS, (cream1 == 'Y' || cream1 == 'y'));
	printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (type2 == 'L' || type2 == 'l'), (type2 == 'M' || type2 == 'm'), (type2 == 'R' || type2 == 'r'), bagWeight2, bagWeight2 / GRAMS_IN_LBS, (cream2 == 'Y' || cream2 == 'y'));
	printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (type3 == 'L' || type3 == 'l'), (type3 == 'M' || type3 == 'm'), (type3 == 'R' || type3 == 'r'), bagWeight3, bagWeight3 / GRAMS_IN_LBS, (cream3 == 'Y' || cream3 == 'y'));
	printf("\n");


	int i;
	for (i = 0; i < 2; ++i)
	{


		printf("Enter how you like your coffee...\n");
		printf("\n");

		printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
		scanf(" %c", &strength);
		printf("Do you like your coffee with cream ([Y]es,[N]o): ");
		scanf(" %c", &likeCream);
		printf("Typical number of daily servings: ");
		scanf("%d", &dailyServings);
		printf("\n");

		printf("The below table shows how your preferences align to the available products:\n");
		printf("\n");

		printf("--------------------+-------------+-------+\n");
		printf("  |     Coffee      |  Packaged   | With  |\n");
		printf("ID|      Type       | Bag Weight  | Cream |\n");
		printf("--+-----------------+-------------+-------+\n");
		printf(" 1|       %d         |      %d      |   %d   |\n", ((strength == 'L' || strength == 'l') && (type1 == 'L' || type1 == 'l')), ((dailyServings >= 1 && dailyServings <= 4) && bagWeight1), ((likeCream == 'Y' || likeCream == 'y') && (cream1 == 'Y' || cream1 == 'y')));
		printf(" 2|       %d         |      %d      |   %d   |\n", ((strength == 'R' || strength == 'r') && (type2 == 'R' || type2 == 'r')), ((dailyServings >= 5 && dailyServings <= 9) && bagWeight2), ((likeCream == 'N' || likeCream == 'n') && (cream2 == 'N' || cream2 == 'n')));
		printf(" 3|       %d         |      %d      |   %d   |\n", ((strength == 'M' || strength == 'm') && (type3 == 'M' || type3 == 'm')), ((dailyServings >= 10) && bagWeight3), ((likeCream == 'N' || likeCream == 'n') && (cream3 == 'N' || cream3 == 'n')));
		printf("\n");
	}

		printf("Hope you found a product that suits your likes!\n");

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/