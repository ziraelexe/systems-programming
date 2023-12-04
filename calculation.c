#include <stdio.h>
#include <stdint.h>

float negate(float s) {

    uint32_t *floatAsInt = (uint32_t *) &s;
    *floatAsInt = *floatAsInt ^ 0x80000000;
    return *(float *) floatAsInt;
}

int main() {

    float s = 25.3;
    float negatedNumber = negate(s);

    printf("Original number %f\n", s);
    printf("Negated number: %f\n", negatedNumber);
    return 0;
}



