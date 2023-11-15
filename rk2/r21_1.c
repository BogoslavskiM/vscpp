#include <stdio.h>


int check_x_value(int x, int max_x){
    return !(x >= max_x || x < 0);
}


void sort_array(int array [], int size){
    int temp;
    for(int _ = 0; _ < size; _++){
        for(int i = 1; i < size; i++){
            if  (array[i] < array[i - 1]){
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        }
    }
}


void reverse_array(int array [], int size){
    int temp;
    for (int i = 0; i < size / 2; i++){
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}


int main(){
    int m, n;
    m = 2;
    n = 3;

    int a[m][n];

    int b[m][n];

    printf("Write array elemnts A[%d, %d]:\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Array[%d, %d]:\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    int x;

    printf("Enter x: ");
    scanf("%d", &x);

    if (!check_x_value(x, n)){
        printf("invalid x");
        return 0;
    }
        
    int xarr[m];

    for (int i = 0; i < m; i++){
      xarr[i] = a[i][x];
    }

    sort_array(xarr, m);
    reverse_array(xarr, m);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j == x)
              b[i][j] = xarr[i];
            else
              b[i][j] = a[i][j];
        }
    }


    printf("Array[%d, %d]:\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}