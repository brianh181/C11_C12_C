#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = (dollars - (dollars % 20)) / 20;
    dollars %= 20;
    *tens = (dollars - (dollars % 10)) / 10;
    dollars %= 10;
    *fives = (dollars - (dollars % 5)) / 5;
    dollars %= 5;
    *ones = dollars;
}

int main(void) {
    int dollars, twenties, tens, fives, ones = 0;

    printf("Enter the amount in dollars: ");
    scanf("%d", &dollars);

    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    printf("You will receive %d twenties, %d tens, %d fives, and %d ones.\n", twenties, tens, fives, ones);




    return 0;
}