/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Chaerin Yoo
Student ID#: 102998234
Email      : cyoo10@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int PRODUCT1_ID = 111, PRODUCT2_ID = 222, PRODUCT3_ID = 111;
    const double Product1_Price = 111.49, Product2_Price = 222.99, Product3_Price = 334.49;
    const char Product1_Taxed = 'Y', Product2_Taxed = 'N', Product3_Taxed = 'N';

    double average_price = (Product1_Price + Product2_Price + Product3_Price)/3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", PRODUCT1_ID);
    printf("  Taxed: %c\n", Product1_Taxed);
    printf("  Price: $%.4lf\n", Product1_Price);
    printf("\n");

    printf("Product-2 (ID:%d)\n", PRODUCT2_ID);
    printf("  Taxed: %c\n", Product2_Taxed);
    printf("  Price: $%.4lf\n", Product2_Price);
    printf("\n");

    printf("Product-3 (ID:%d)\n", PRODUCT3_ID);
    printf("  Taxed: %c\n", Product3_Taxed);
    printf("  Price: $%.4lf\n", Product3_Price);
    printf("\n");

    printf("The average of all prices is: $%.4lf\n", average_price);
    printf("\n");

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n", Product1_Taxed == 'Y' || Product1_Taxed=='y');
    printf("\n");

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", Product2_Taxed == 'N' && Product3_Taxed == 'N');
    printf("\n");

    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n", testValue, Product3_Price < testValue);
    printf("\n");

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", Product3_Price > (Product1_Price + Product2_Price));
    printf("\n");

    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d", Product1_Price >= (Product3_Price - Product2_Price));
    printf(" (price difference: $%.2lf)\n", Product3_Price - Product2_Price);
    printf("\n");

    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", Product2_Price >= average_price);
    printf("\n");

    printf("7. Based on product ID, product 1 is unique -> %d\n", PRODUCT1_ID != PRODUCT2_ID && PRODUCT1_ID != PRODUCT3_ID);
    printf("\n");

    printf("8. Based on product ID, product 2 is unique -> %d\n", PRODUCT2_ID != PRODUCT1_ID && PRODUCT2_ID != PRODUCT3_ID);
    printf("\n");

    printf("9. Based on product ID, product 3 is unique -> %d\n", PRODUCT3_ID != PRODUCT1_ID && PRODUCT3_ID != PRODUCT2_ID);

    

    return 0;
}