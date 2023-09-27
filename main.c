#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main(){
    int y, A;
    printf("введите A и y через пробел\n");

    scanf("%d %d", &A, &y);

    if (A > 0)
        printf("%d, method:A", A);
    else
        printf("%d, method:y", y);
}