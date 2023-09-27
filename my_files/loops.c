#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(){
    for (int j = 0; j < 5; j++) {
        printf("%f ", sin(j));
        printf("%f\n", cos(j));

    }
    printf("\n\n  ---   \n\n");
    for (float j = 0.5; j < 5000000000; j += powf(j, 2) ){
        printf("%.10f\n", j); // хотя бы 10 символов после запятой
        printf("%10f\n", j); // хотя бы 10 символов
        printf("%5.1f\n", j); // хотя бы 5 символов всего и хотя бы 1 после запятой
        printf("-\n");
    }

    printf("\n\n  ---   \n\n");
    int i;
    char s[128];
    __int128_t x;  // "long long x;"
    i = 1;
    while (i < 129){
        x = powl(2, i);
        sprintf(s, "%lli", x);
        if (strcmp(s, "0"))
            printf("%s\n", s);
        else {
            printf("ints too big degree of 2: i = %d", i);
            break;
        }
        i *= 2;
    }
    printf("\n\n   ---   \n\n");
    i = 100;
    do {
        printf("%d\n", i);
        i /= 2;
        i ++;
        i ++;
    } while (i > 19);
    return 0;

}


