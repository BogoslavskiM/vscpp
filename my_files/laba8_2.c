#include <stdio.h>
#include <string.h>

int main() {
    char fname[100] = "text.txt";
    printf("file_name: ");
    printf(fname);
    printf("\n");
    FILE *file = fopen(fname,"r");
    
    int res;
    int i = 0;
    int is_found_point = 0;
    char symbol;
    symbol = fgetc(file);
    while (symbol != EOF){
      i++;
      if (symbol == '.'){
          res = i;
          is_found_point = 1;
      }
      symbol = fgetc(file);
    }
    if (is_found_point){
      printf("point_position: %d",res);
    }
    else {
      printf("point not found");
    }

}