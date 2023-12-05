#include <stdio.h>


int main() {
    char s[] = "1234567654321";
  
    int is_palindrom = 1;
    int s_size = sizeof(s) - 1;
  
    for (int i = 0; i < s_size; i++) {
        if (s[i] != s[s_size - i - 1]) {
          is_palindrom = 0;
        }
    }
  
    printf("is_palindrom: %d", is_palindrom);
  
    return 0;
}