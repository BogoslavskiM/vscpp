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

    printf("Array[%d, %d]:\n", m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    int xa, ya;
    printf("A(x, y):\n");
    scanf("%d %d", &xa, &ya);
  
    int xb, yb;
    printf("B(x, y):\n");
    scanf("%d %d", &xb, &yb);

    xa = delimit_value(xa, 1, n);
    ya = delimit_value(ya, 1, m);

    xb = delimit_value(xb, 1, n);
    yb = delimit_value(yb, 1, m);
  
    xa --;
    ya --;
    xb --;
    yb --;

    printf("\n");
  
    int res_matrix[xb - xa + 1][yb - ya + 1];

    for (int j = 0; j < xb - xa + 1; j++){
      for (int i = 0; i < yb - ya + 1; i++){
            res_matrix[i][j] = array[xa + j][ya + i];
            printf("%d ", res_matrix[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}