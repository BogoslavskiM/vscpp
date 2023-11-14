#include <stdio.h>
#include <stdlib.h>

int in_line_input() {
    int x[10];
    printf("Введите 10 xbctk");
    scanf("%d %d %d %d %d %d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7], &x[8], &x[9]);
    return x;
}


int out(int x[10] ){
    for (int i = 0; i < 10; i++ ){
        printf("%d ", x[i]);
    }
    return 0;
}


int in_column_input(){
    int x[10];

    for (int i = 0; i < 10; i++){
        scanf("%d", &x[i]);
    }
    return x;
}

int sort(int x[10]){
    for (int i = 0; i < 10, i++){
        for (int j = 0; j < 9, j++){
            if (x[j] > x[j + 1]){
                x[j], x[j + i] = x[j + 1], x[j];
            }
        }
    }
    return x;
}

int reverse(int x[10]){
    for (int i = 0; i < (10 / 2), i++){
        x[i], x[10 - 1 - i] = x[10 - 1 - i], x[i];
    }
    return x;
}

int main(){
    int x[10] = in_line_input();
    out(x);
    x = sort(x);
    out(x);
    x = reverse(x)
    out(x);
    return;
}