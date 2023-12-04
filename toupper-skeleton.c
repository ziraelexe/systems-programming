#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) { // read until end of input
        if ((c >= 'a' && c <= 'z')) {
            c = c & ~32; //since 2^5 = 32 in ASCII code
        }
        putchar(c);
    }
    return 0;
}
