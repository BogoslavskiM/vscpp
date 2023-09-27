#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main() {
    float x, y, eps;

    eps = 1e-10;
    scanf("%f %f", &x, &y);

    if (fabs(cosf(x)) > eps) {
        if (fabs(y - 1 / cosf(x)) < eps) {
            printf("on line");
            return 0;
        }
    }
    else{
        printf("on line");
        return 0;
    }

    if (fabs(x * x + y * y - 25) < eps  || fabs(x * x + y * y - 49) < eps || fabs(fabs(y) - fabs(cosf(x))) < eps) {
        printf("on line");
        return 0;
    }
    if (y > 1 / cos(x)){
        printf("in");
        return 0;
    }
    if (x * x + y * y < 49 && x * x + y * y > 25 && y > 0 && y < cosf(x) ){
        printf("in");
        return 0;
    }
    printf("out");
    return 0;
}