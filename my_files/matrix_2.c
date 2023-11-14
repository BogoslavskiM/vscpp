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

    int to_sqw;

    printf("\ntransformate matrix\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            to_sqw = 0;
            if (i > 0){
                if (array[i - 1][j] == 0)
                    to_sqw = 1;
            }
            if (j > 0){
                if (array[i][j - 1] == 0)
                    to_sqw = 1;
            }
            if (i + 1 < m){
                if (array[i + 1][j] == 0)
                    to_sqw = 1;
            }
            if (j + 1 < n){
                if (array[i][j + 1] == 0)
                    to_sqw = 1;
            }

            if (to_sqw == 1){
                array[i][j] = array[i][j] * array[i][j];
            }
                
        }
        
    }
  
    printf("Array[%d, %d]:\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}