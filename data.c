//
// Created by Jonas on 17.10.2023.
//
#include <stdio.h>
#include "data.h"

char name[MAX_LENGTH];
char phoneNumber[MAX_LENGTH];

int readData() {
    printf("Please enter your name: ");
    if (scanf("%255s", name) != 1) {
        return 1; // error
    }

    printf("Please enter a phone number: ");
    if (scanf("%255s", phoneNumber) != 1) {
        return 1;
    }
    return 0; // success
}

void writeData() {
    printf("Full name: %s\nPhone Number: %s\n", name, phoneNumber);
}

