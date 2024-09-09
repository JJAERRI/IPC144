/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P2)
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

#define MIN_YEAR 2012  //mecro
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
	const int JAN = 1;  //constant variables
	const int DEC = 12;

	int year, month, valid, i;
	double mRate, eRate;
	double sumM = 0, sumE = 0, sumAll = 0;

	printf("General Well-being Log\n");
	printf("======================\n");

	do
	{
		valid = 1;
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);
		if (year < MIN_YEAR || year > MAX_YEAR)
		{
			printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
			valid = 0;
		}
		if (month < JAN || month > DEC)
		{
			printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
			valid = 0;
		}

	} while (valid == 0);

	printf("\n");
	printf("*** Log date set! ***\n");
	printf("\n");

	// printf("Log starting date: ");

	for (i = 1; i <= LOG_DAYS; i++)
	{

		switch (month)
		{
		case 1:
			printf("%d-JAN-%02d\n", year, i); // 02 means two integers box if 1 -> 01
			break;
		case 2:
			printf("%d-FEB-%02d\n", year, i);
			break;
		case 3:
			printf("%d-MAR-%02d\n", year, i);
			break;
		case 4:
			printf("%d-APR-%02d\n", year, i);
			break;
		case 5:
			printf("%d-MAY-%02d\n", year, i);
			break;
		case 6:
			printf("%d-JUN-%02d\n", year, i);
			break;
		case 7:
			printf("%d-JUL-%02d\n", year, i);
			break;
		case 8:
			printf("%d-AUG-%02d\n", year, i);
			break;
		case 9:
			printf("%d-SEP-%02d\n", year, i);
			break;
		case 10:
			printf("%d-OCT-%02d\n", year, i);
			break;
		case 11:
			printf("%d-NOV-%02d\n", year, i);
			break;
		case 12:
			printf("%d-DEC-%02d\n", year, i);
			break;

		default:
			break;
		}

		do
		{
			valid = 1;
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &mRate);
			if (mRate < 0.0 || mRate > 5.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				valid = 0;
			}
		} while (valid == 0);

		do 
		{
			valid = 1;
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &eRate);
			if (eRate < 0.0 || eRate > 5.0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				valid = 0;
			}

		} while (valid == 0);

		sumM = sumM + mRate;
		sumE = sumE + eRate;
		sumAll = sumAll + mRate + eRate;

		printf("\n");

	}

	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3lf\n", sumM);
	printf("Evening total rating:  %.3lf\n", sumE);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n", sumAll);
	printf("\n");

	printf("Average morning rating:  %.1lf\n", sumM / LOG_DAYS);
	printf("Average evening rating:  %.1lf\n", sumE / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf\n", sumAll / (LOG_DAYS*2));
	

	return 0;
}