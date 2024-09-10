/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <ctype.h>
#include <string.h>
#include "core.h"


// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//inputInt
int inputInt(void)
{
    char newLine = 'x';
    int value;
    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }

    return value;
}

int inputIntPositive()
{
    int value;

    do
    {
        value = inputInt();
        if (value < 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (value < 0);


    return value;
}

int inputIntRange(int lower, int upper)
{
    int value;
    do
    {
        value = inputInt();
        if (value<lower || value>upper)
        {
            printf("ERROR! Value must be between % d and %d inclusive: ", lower, upper);
        }
    } while (value<lower || value>upper);

    return value;
}

char inputCharOption(const char Character[])
{
    char value;
    int i, count = 0;

    do {
        scanf(" %c", &value);

        for (i = 0; Character[i] != '\0' && count == 0; i++) {
            if (Character[i] == value) {
                count++;
            }
        }

        if (count == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", Character);
        }

    } while (count == 0);

    clearInputBuffer();

    return value;
}

void inputCString(char* str, int lower, int upper)
{
    int length;
    char Input[99];
    int i;
    do {
        length = 0;
        scanf("%[^\n]", Input);
        clearInputBuffer();

        while (Input[length] != '\0') {
            length++;
        }

        if (lower == upper && length != lower) {
            printf("ERROR: String length must be exactly %d chars: ", lower);
        }
        else if (length > upper) {
            printf("ERROR: String length must be no more than %d chars: ", upper);
        }
        else if (length < lower) {
            printf("ERROR: String length must be between %d and %d chars: ", lower, upper);
        }
        else {
            for (i = 0; i < length; i++) {
                str[i] = Input[i];
            }
            str[length] = '\0';
            return;
        }

    } while (length < lower || length > upper);
}

void displayFormattedPhone(const char* str)
{
    int length = 0, i;
    int isValid = 1;

    while (str != NULL && str[length])
    {
        if (!isdigit(str[length]))
        {
            isValid = 0;
        }
        length++;
    }

    if (length != 10 || !isValid)
    {
        printf("(___)___-____");
    }
    else
    {
        i = 0;
        printf("(");
        while (i < 3)
        {
            printf("%c", str[i]);
            i++;
        }
        printf(")");
        while (i < 6)
        {
            printf("%c", str[i]);
            i++;
        }
        printf("-");
        while (i < 10)
        {
            printf("%c", str[i]);
            i++;
        }
    }
}