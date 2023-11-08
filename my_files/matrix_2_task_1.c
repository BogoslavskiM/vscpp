#include <stdio.h>


int main(){
    int m, n;
    printf("M N : ");
    scanf("%d %d", &m, &n);
    int arr[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            // printf("%d %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
  
    int k;
    printf("k : ");
    scanf( "%d", &k);

    printf("\nYour matrix is:\n");
  
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
  
    int arr2[n];
  
    for (int i = 0; i < n; i++){
      arr2[i] = arr[k][i];
    }

    int temp, arr_temp[n];
    for(int _ = 0; _ <= n; _++){
        for(int i = 1; i < n; i++){
            if  (arr2[i] < arr2[i - 1]){
                temp = arr2[i];
                arr2[i] = arr2[i - 1];
                arr2[i - 1] = temp;
              
                for (int j = k; j < m; j++){
                    temp = arr[j][i];
                    arr[j][i] = arr[j][i - 1];
                    arr[j][i - 1] = temp;
                }
                
            }
        }
    }
    printf("\n");
  
    printf("\nNow your matrix is:\n");
  
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}