#include <stdio.h>
#include <stdlib.h>


int main() {
    int month_number;

    printf("enter month_number\n");
    scanf("%d", &month_number);

    switch (month_number){
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
        default:
            printf("no found month by month number %d", month_number);
    }
    printf("\n");

    switch (month_number){
        case 1 ... 2: case 12:
            printf("Winter");
            break;
        case 3 ... 5:
            printf("Spring");
            break;
        case 6 ... 8:
            printf("Summer");
            break;
        case 9 ... 11:
            printf("Autumn");
            break;
        default:
            printf("no found season by month number %d", month_number);
    }
    printf("\n");

    switch (month_number){
        case 1 ... 3:
            printf("1 quarter");
            break;
        case 4 ... 6:
            printf("2 quarter");
            break;
        case 7 ... 9:
            printf("3 quarter");
            break;
        case 10 ... 12:
            printf("4 quarter");
            break;
        default:
            printf("no found quarter by month number %d", month_number);
    }
    printf("\n");
    return 0;
}