/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Caerin yoo
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
    const double TAX = 0.13;
    const char patSize = 'S';
    const char tomSize = 'L';
    const char sallySize = 'M';
    double price_small, price_medium, price_large;
    int small_number, medium_number, large_number;
    int patty_sub_total, patty_taxes, patty_total;
    int sally_sub_total, sally_taxes, sally_total;
    int tom_sub_total, tom_taxes, tom_total;
    int all_sub_total, all_taxes, all_total;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &price_small);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &price_medium);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &price_large);
    printf("\n");

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", price_small);
    printf("MEDIUM : $%.2lf\n", price_medium);
    printf("LARGE  : $%.2lf\n", price_large);
    printf("\n");

    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &small_number);
    printf("\n");

    printf("Tommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &large_number);
    printf("\n");

    printf("Sally's shirt size is \'%c\'\n", sallySize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &medium_number);
    printf("\n");

    patty_sub_total = price_small * small_number * 100;
    patty_taxes = patty_sub_total * TAX + 0.5;
    patty_total = patty_sub_total + patty_taxes;

    sally_sub_total = price_medium * medium_number * 100;
    sally_taxes = sally_sub_total * TAX + 0.5;
    sally_total = sally_sub_total + sally_taxes;

    tom_sub_total = price_large * large_number * 100;
    tom_taxes = tom_sub_total * TAX + 0.5;
    tom_total = tom_sub_total + tom_taxes;

    all_sub_total = patty_sub_total + sally_sub_total + tom_sub_total;
    all_taxes = patty_taxes + sally_taxes + tom_taxes;
    all_total = patty_total + sally_total + tom_total;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, price_small, small_number, patty_sub_total/100.0, (double)patty_taxes/100.0, (double)patty_total/100.0);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", sallySize, price_medium, medium_number, sally_sub_total / 100.0, (double)sally_taxes / 100.0, (double)sally_total / 100.0);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, price_large, large_number, tom_sub_total / 100.0, (double)tom_taxes / 100.0, (double)tom_total / 100.0);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", all_sub_total / 100.0, all_taxes / 100.0, all_total / 100.0);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n");
    printf("\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    double balance_excluding_tax = all_sub_total / 100.0;
    printf("%22.4lf\n", balance_excluding_tax);

    int toonies_qty = balance_excluding_tax / 2;
    balance_excluding_tax -= toonies_qty * 2;
    printf("Toonies  %3d %9.4lf\n", toonies_qty, balance_excluding_tax);


    int loonies_qty = balance_excluding_tax / 1;
    balance_excluding_tax -= loonies_qty * 1;
    printf("Loonies  %3d %9.4lf\n", loonies_qty, balance_excluding_tax);

    int quarters_qty = balance_excluding_tax / 0.25;
    balance_excluding_tax -= quarters_qty * 0.25;
    printf("Quarters  %2d %9.4lf\n", quarters_qty, balance_excluding_tax);

    int dimes_qty = balance_excluding_tax / 0.1;
    balance_excluding_tax -= dimes_qty * 0.1;
    printf("Dimes   %4d %9.4lf\n", dimes_qty, balance_excluding_tax);

    int nickels_qty = balance_excluding_tax / 0.05;
    balance_excluding_tax -= nickels_qty * 0.05;
    printf("Nickels  %3d %9.4lf\n", nickels_qty, balance_excluding_tax);

    int pennies_qty = balance_excluding_tax / 0.01+1;
    balance_excluding_tax = 0.0000;
    printf("Pennies   %2d %9.4lf\n", pennies_qty, balance_excluding_tax);
    printf("\n");

    double average_cost_per_shirt_excluding_tax = all_sub_total / (double)(small_number + medium_number + large_number) / 100.0;
    printf("Average cost/shirt: $%.4lf\n\n", average_cost_per_shirt_excluding_tax);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    double balance_including_tax = all_total / 100.0;
    printf("%22.4lf\n", balance_including_tax);

    toonies_qty = balance_including_tax / 2;
    balance_including_tax -= toonies_qty * 2;
    printf("Toonies  %3d %9.4lf\n", toonies_qty, balance_including_tax);

    loonies_qty = balance_including_tax / 1;
    balance_including_tax -= loonies_qty * 1;
    printf("Loonies  %3d %9.4lf\n", loonies_qty, balance_including_tax);

    quarters_qty = balance_including_tax / 0.25;
    balance_including_tax -= quarters_qty * 0.25;
    printf("Quarters  %2d %9.4lf\n", quarters_qty, balance_including_tax);

    dimes_qty = balance_including_tax / 0.1;
    balance_including_tax -= dimes_qty * 0.1;
    printf("Dimes   %4d %9.4lf\n", dimes_qty, balance_including_tax);

    nickels_qty = balance_including_tax / 0.05;
    balance_including_tax -= nickels_qty * 0.05;
    printf("Nickels  %3d %9.4lf\n", nickels_qty, balance_including_tax);

    pennies_qty = balance_including_tax / 0.01+1;
    balance_including_tax = 0.0000;
    printf("Pennies   %2d %9.4lf\n", pennies_qty, balance_including_tax);
    printf("\n");

    double average_cost_per_shirt_including_tax = all_total / (double)(small_number + medium_number + large_number) / 100.0;
    printf("Average cost/shirt: $%.4lf\n", average_cost_per_shirt_including_tax);


    return 0;
}