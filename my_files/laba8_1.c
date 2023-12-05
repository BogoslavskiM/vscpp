#include <stdio.h>


int main(){
  // первоначальная строка
  char inp_text[100] = "+<-here was one plus++<-here was 2 pluses+++<-here was 3 pluses";

  int size = 0; // переменная для рассчета длины строки
  int n = 3; // на сколько плюсов заменить один плюс

  // рассчет длины строки
  while (inp_text[size] != '\0' && inp_text[size] != '\n') {
      size++;
  }

  // переменная, в которой хранится результирующая строка
  char out_text[300];

  // цикл, который заменяит каждый плюс на n плюcсов и сохранит в out_text
  int next_res_ind = 0;
  for (int i = 0; i < size - 2; i++){
    if (inp_text[i] == '+'){
      for (int j = 0; j < n; j++){
        out_text[next_res_ind] = '+';
        next_res_ind++;
      }
    }
    else{
      out_text[next_res_ind] = inp_text[i];
      next_res_ind++;
    }
  }

  // вывод результата преобразования
  printf(out_text);
  
  
}