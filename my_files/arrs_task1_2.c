#include <stdio.h>


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


void show_array(int array [], int size){
  for(int i = 0; i < size; i++){
      printf("%d ", array[i]);
  }
  printf("\n");
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
    int size = 10;
    size = input_array_size(size);
    int array[size];

    input_array(array, size);
    show_array(array, size);
  
    sort_array(array, size);
    show_array(array, size);
  
    reverse_array(array, size);
    show_array(array, size);
  
    return 0;

}