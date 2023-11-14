#include <stdio.h>


int delimit_value(int x, int min_x, int max_x){
  if (x < min_x)
      x = min_x;
  else if (x > max_x)
      x = max_x;

  return x;
}


int main(){
    int m, n;
    printf("M, N: ");
    scanf("%d %d", &m, &n);

    int array[m][n];

    printf("Write array elemnts:\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &array[i][j]);
        }
    }

    printf("\n");
    printf("Array[%d, %d]:\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    int transported_array[n][m];
    printf("\ntransp matrix...\n");

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            transported_array[j][i] = array[i][j];
        }
    }

    printf("\nArray'[%d, %d]:\n", m, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%d\t", transported_array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}