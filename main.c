#include <stdio.h>

int main(){
    int n, m;
    printf("введите n: ");
    scanf("%d", &n);
    int x[n];
    
    
    for (int i = 0; i < n; i++){
        printf("введите x[%d]: ", i + 1);
        scanf("%d", &x[i]);
    }
    
    for (int i = 0; i < n; i++){
        printf("%d ", x[i]);
    }
    
    printf("\nвведите m: ");
    scanf("%d", &m);
    
    int results[m];
    
    int j, k;
    
    int actual_level;
    for (int i = 0; i < n; i++){
        printf("введите j и k: ");
        scanf("%d %d", &j, &k);
        j -= 1;
        k -= 1;
        actual_level = j;
        if (k >= n || j < 0){
            printf("invalid data\n");
            continue;
        }
        while (actual_level < k){
            if (x[actual_level] == 0){
                break;
            }
            actual_level = actual_level + x[actual_level];
        }
        if (actual_level == k){
            results[i] = 1;
            printf("can\n");
        }
        else{
            results[i] = 0;
            printf("can't\n");
        }
        
    }
    
    for (int i = 0; i < n; i++){
        printf("%d ", results[i]);
    }
    
    return 0;
}
