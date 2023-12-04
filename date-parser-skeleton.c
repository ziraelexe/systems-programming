#include<stdio.h>

typedef struct DateStruct {
    unsigned int day;
    unsigned int month;
    unsigned int year;
} DateStruct;

typedef union DateUnion {
    struct DateStruct date;
    int dateAsInt;
} DateUnion;

int main() {
    int d, m, y, completeDate;
    DateUnion dateUnion;

    printf("*** Demo of using union and struct to parse bitstrings ***\n");

    printf("enter day: ");
    scanf("%d", &d);
    printf("enter month: ");
    scanf("%d", &m);
    printf("enter year: ");
    scanf("%d", &y);

    dateUnion.date.day = d;
    dateUnion.date.month = m;
    dateUnion.date.year = y;

    printf("your date encoded as a number = %d\n\n", dateUnion.dateAsInt);

    printf("Now, enter your date as a number: ");
    scanf("%d", &completeDate);

    dateUnion.dateAsInt = completeDate;

    printf("parsed day = %d\n", dateUnion.date.day);
    printf("parsed month = %d\n", dateUnion.date.month);
    printf("parsed year = %d\n", dateUnion.date.year);

    return 0;
}
