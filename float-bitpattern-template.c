/**
 * solution to programming assignment on the bit pattern of
 * floating point numbers
 */

#include <stdio.h>
#include <float.h>

void putbits(unsigned int n); // prototype

#define M (FLT_MANT_DIG - 1)
#define E 8
#define S 1

struct bits {

    unsigned int mantissa: M;
    unsigned int exponent: E;
    unsigned int sign: S;

};

union FloatLong {

    float x;
    unsigned int n;
    struct bits b;

} xnb;

int main() {
    puts("** Sign, exponent and mantissa of a float-variable ***\n");
    printf("Number of bits for the mantissa: %d\nnumber of bits for the exponent: %d\n", M, E);
    if (sizeof(float) > sizeof(int)) {
        // too large for the bit fields
        puts("type float must be larger than type int");
        return 1;
    }

    printf("\nEnter a floating point number: ");
    while (scanf("%f", &xnb.x) == 1) {
        printf("bit pattern: ");
        putbits(xnb.n);

        printf("\nsign: %c\n", (xnb.b.sign == 0) ? '+' : '-');

        if (xnb.b.exponent == 0 && xnb.b.mantissa == 0) {
            printf("exponent: 0\nmantissa: 0.000000\n");
        } else {
            printf("exponent: %d\n", (xnb.b.exponent - 127));
            printf("mantissa: %f\n", 1.0 + (xnb.b.mantissa / (float) (1 << (M))));

            printf("\nNext number (enter q to quit): ");
        }

    }
    return 0;
}

void putbits(unsigned int n) { // print the bit pattern of n
    int i;
    for (i = 8 * sizeof(n) - 1; i >= 0; --i) {
        putchar(((n >> i) & 1) + '0'); // output the i-th bit
        if (i % 4 == 0 && i > 0) { // put a blank after a block of 4 bits
            putchar(' ');
        }
    }
}

/*
 * f1=f2
 * f1.b = f2.b
 * c) Yes this works because in the union the field starts at the address 0x0000
 */



