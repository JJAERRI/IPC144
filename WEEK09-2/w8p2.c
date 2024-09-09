/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User-Defined Libraries
// User Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num)
{
	int val;

	do
	{
		scanf("%d", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
	{
		*num = val;     //two way
	}

	return val;       //one way
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num)
{
	double val;

	do
	{
		scanf("%lf", &val);
		if (val <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (val <= 0);

	if (num != NULL)
	{
		*num = val;     //two way
	}

	return val;       //one way
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_product);
	printf("NOTE: A 'serving' is %dg\n", NUM_GRAMS);
	return;
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_num)
{
	struct CatFoodInfo food = { 0 };

	printf("\nCat Food Product #%d\n", sequence_num);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&food.sku);
	//food.sku = getIntPositive(NULL);
	//food.sku = getIntPositive(&food.sku);

	printf("PRICE         : $");
	food.price = getDoublePositive(NULL);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&food.weight);

	printf("CALORIES/SERV.: ");
	food.calories = getIntPositive(NULL);

	return food;

}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* kilograms)
{
	const double LBS_TO_KG = 2.20462;

	double result = *pounds / LBS_TO_KG;

	if (kilograms != NULL)
	{
		*kilograms = result;
	}

	return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* grams)
{
	//const double LBS_TO_GRAMS = 453.592;

	const double LBS_TO_KG = 2.20462;

	int result = ((*pounds) / LBS_TO_KG) * 1000;

	if (grams != NULL)
	{
		*grams = result;
	}

	return result;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* kilograms, int* grams)
{
	convertLbsKg(pounds, kilograms);
	convertLbsG(pounds, grams);

}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalGrams, double* resultServings)
{
	double result = (double)totalGrams / gPerServ;

	if (resultServings != NULL)
	{
		*resultServings = result;
	}

	return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* productPrice, const double* totalServings, double* costPerServing)
{
	double result = *productPrice / *totalServings;

	if (costPerServing != NULL)
	{
		*costPerServing = result;
	}

	return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* productPrice, const double* totalCalories, double* costPerCalorie)
{
	double result = *productPrice / *totalCalories;

	if (costPerCalorie != NULL)
	{
		*costPerCalorie = result;
	}

	return result;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productData)
{
	struct ReportData report = { 0 };
	report.sku = productData.sku;
	report.price = productData.price;
	report.weightPounds = productData.weight;
	report.calories = productData.calories;
	report.weightKilos = productData.weight / 2.20462;
	report.weightGrams = (int)(productData.weight * 1000 / 2.20462);
	report.servings = calculateServings(NUM_GRAMS, report.weightGrams, &report.servings);
	report.costPerServing = productData.price / report.servings;
	report.costPerCalorie = productData.price / (productData.calories * report.servings);
	return report;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", NUM_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int isCheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.sku, report.price, report.weightPounds, report.weightKilos, 
		report.weightGrams, report.calories, report.servings, report.costPerServing, report.costPerCalorie);

	if (isCheapest) {
		printf(" ***");
	}

	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo productData)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", productData.sku, productData.price);
	printf("\n");

	// Ending line
	printf("Happy shopping!\n");
	printf("\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	openingMessage(MAX_PRODUCT);

	struct CatFoodInfo cats[MAX_PRODUCT];
	struct ReportData report[MAX_PRODUCT];
	int i;

	int cheapestIndex = 0;

	for (i = 0; i < MAX_PRODUCT; i++) 
	{
		cats[i] = getCatFoodInfo(i + 1);

		report[i] = calculateReportData(cats[i]);

		if (report[i].costPerServing < report[cheapestIndex].costPerServing) 
		{
			cheapestIndex = i;
		}
	}
	displayCatFoodHeader();
	for (i = 0; i < MAX_PRODUCT; i++) 
	{
		displayCatFoodData(cats[i].sku, &cats[i].price, cats[i].calories, &cats[i].weight);
	}

	displayReportHeader();
	for (i = 0; i < MAX_PRODUCT; i++) 
	{
		displayReportData(report[i], i == cheapestIndex);
	}

	displayFinalAnalysis(cats[cheapestIndex]);

}

