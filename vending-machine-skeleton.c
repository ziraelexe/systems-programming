#include <stdio.h>

int main() {
    printf("Vending machine v0.1\n\n");

    // selection of beverages
    int type;
    printf("Choose your drink:\n");
    printf("1) Water (0,50 Euro)\n");
    printf("2) Lemonade (1,00 Euro)\n");
    printf("3) Beer (2,00 Euro)\n\n");
    printf("Enter 1, 2 or 3: ");
    scanf("%d", &type);

    // get the amount to be paid
    float price;
    switch (type) {
        case 1:
            price = 0.50f;
            break;
        case 2:
            price = 1.00f;
            break;
        case 3:
            price = 2.00f;
            break;
        default:
            printf("\n Beverage selection does not exist");
            return 1;
    }
    // request for payment
    float payment = 0;
    while (price > 0) {
        printf("\nPlease insert %.2f Euro: ", price);
        if (!scanf("%f", &payment)) {
            printf("\nInsufficient funds. Please insert an additional amount of %.2f Euro", price - payment);
            return -1;
        }
        price -= payment;
    }

    // check the coin
    if (price == 0) {
        printf("\nThank you! Enjoy your drink.\n");
        return 0;
    } else if (price < 0) {
        float change = -price;
        printf("\nEnjoy your drink! Your change is %.2f Euro\n", change);
        return 0;
    } else {
        printf("\nUnknown coin for %.2f inserted.\n", price);
        return -1;
    }
}

