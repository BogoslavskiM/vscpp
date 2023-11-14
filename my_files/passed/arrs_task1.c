#include <stdio.h>
#include <stdlib.h>


int input_arr_size(int n){
    int in_n;
  
    printf("Enter array length (0 for skip): ");
    scanf("%d", &in_n);

    if (in_n > 0)
        n = in_n;
    else if (in_n < 0)
        printf("Invalid input, used n = %d\n", n);

    return n;
}


void sort_array(int *a, int n){
    int _, i, temp;
    for (_ = 0; _ < n; _++){
        for (i = 1; i < n; i++){
            if (a[i] < a[i - 1]){
                temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
            }
        }
    }
}


void input_array(int *a, int n) {  
    printf("Enter %d integers: \n", n);
    
    for (int i = 0; i < n; i++) {
        printf("%d : ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
}


void reverse_array(int *a, int n){
    int d;
    for (int i = 0; i < n/2; i++){
        d = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = d;
    }
}


void show_array(int *a, int n){
  for (int i = 0; i < n; i++){
      printf("%d ", a[i]);
  }
  printf("\n");
}


int main(){
  int *array, arr_len;
  
  arr_len = input_arr_size(10);
  array = (int *) calloc(arr_len, sizeof(int));
  input_array(array, arr_len);

  reverse_array(array, arr_len);
  show_array(array, arr_len);
  
  sort_array(array, arr_len);
  show_array(array, arr_len);
  
  reverse_array(array, arr_len);
  show_array(array, arr_len);
  
  free(array);
  return 0;
}