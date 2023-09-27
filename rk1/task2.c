#include <stdio.h>




int main(){
    int days_in_month, year, is_vis;

    printf("write day_count and year, separated ssase:\n");
    scanf("%d %d", &days_in_month, &year);

    if (days_in_month < 1 || days_in_month > 31) {
        printf("wrong days_count data");
        return 0;
    }

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        is_vis = 1;
    else
        is_vis = 0;

    printf("thees day count have ");
    switch (days_in_month){
        case 1 ... 28:
            printf("12 moths\n");
            break;
        case 29:
            switch (is_vis){
                case 0:
                    printf("11 sometimes\n");
                    break;
                case 1:
                    printf("12 months\n");

            }
            break;
        case 30:
            printf("11 moths\n");
            break;
        case 31:
            printf("7 moths\n");
            break;
        default:
            printf("0 moths\n");
    }

}