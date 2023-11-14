#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
    for (int i = 0 + 39; i <= 5000; i += 39)
        printf("%d ", i);

    printf("\n");
    for (int i = 1; i <= 5000; i += 1){
        if (i % 39 == 0)
            printf("%d ", i);
    }
    printf("\n");
    int i = 0;
    while (i <= 5000){
        i += 1;
        if (i % 39 == 0)
            printf("%d ", i);
    }
    i = 0;
    printf("\n");
    while (i <= 5000){
        i += 39;
        printf("%d ", i);
    }
    printf("\n");
    i = 39;
    do {
        printf("%d ", i);
        i += 39;
    }
    while (i <= 5000);
    printf("\n");
}



