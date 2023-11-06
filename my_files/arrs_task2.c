#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int input_array_size(int size){
    int in_size;
    printf("Enter array length (0 for skip): ");
    scanf("%d", &in_size);

    if (in_size > 0)
        size = in_size;
    else if (in_size < 0)
        printf("Invalid input, used size = %d\n", size);

    return size;
}


void input_array(int array [], int size){
    printf("Enter %d array elements: \n", size);
    for (int i = 0; i < size; i++){
        printf("%d : ", i);
        scanf("%d", &array[i]);
    }

}


int is_simple(int n){
    if (n <= 0){
        printf("warn, number is <= 0\n");
        return 0;
    }
    switch (n){
      case 1:
        return 0;
      case 2:
        return 1;
    }
  
    for (int i = 2; i <= sqrt(n) + 1; i++){
        if (n % i == 0){
          return 0;
        }
    }
    return 1;
}


void replace_elem(int array [], int size, int (*check_func)(int), int replace_to){
    for(int i = 0; i < size; i++){
        if (!check_func(array[i])) {
            array[i] = replace_to;
        }
    }
}


void show_array(int array [], int size){
  for(int i = 0; i < size; i++){
      printf("%d ", array[i]);
  }
  printf("\n");
}


int main(){
    int size = 10;
    size = input_array_size(size);
    int array[size];
    input_array(array, size);
    show_array(array, size);
  
    replace_elem(array, size, is_simple, 0);
    show_array(array, size);
    
    return 0;

}