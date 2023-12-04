#include <stdio.h>

int arr[] = {-20, -10, 0, 10, 20};

int main() {

    int *p = NULL, i;
    float *floatPtr = NULL;
    //*p = 20;          // Set the first value using int pointer
    //*floatPtr = 20.0; // Set the first value using float pointer
    // c) both lines will set the first value of the array to 20.
    // The second line uses the float pointer to set a float value in the memory location pointed to by 'floatPtr'

    puts(" *** demo with pointers and arrays ***\n");

    p = arr;
    floatPtr = (float *) arr; // a) assign the float pointer the address of a

    *p = 99; // assign the first element
    while (p < arr + 5)
        printf("%6d", *p++);


    while (p < arr + 5)
        printf("%6d", *p++);

    putchar('\n');

    while (p-- > arr)
        printf("%6d", *p);

    /*  t
        f
        f
        f
        f

        f
        t
        f
        f
        f
            */

    putchar('\n');

    // b)
    for (p = arr; p <= arr + 4; ++p)
        printf("%6d", *p);

    putchar('\n');

    for (p = arr + 2, i = 0; i < 3; ++i)
        printf("%6d%6d\n", p[-i], p[i]);

    putchar('\n');

    // d)
    printf("Second element via int pointer: %d\n", *(p + 1));

    return 0;
}
