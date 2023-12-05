#include <stdio.h>
#include <string.h>
#include <assert.h>


// test data1 =>
// amer summer 4
// triangle squarior 2

// 1 5 5 4 3 3 cluter muter
// 1 3 5 4 3 3 salam muter
// 1 3 5 4 2 3 cluter malek
// 2 5 5 4 2 3 fio name
// 2 3 5 4 2 3 halo
// 2 5 5 4 5 4 triangle squarior
// 3 4 5 4 2 1 bird
// 3 4 5 4 3 1 selector box
// 3 4 5 4 3 3 Canada amer
// 4 4 5 4 5 4 amer summer



// test data2 => no students

// 1 5 5 4 3 3 cluter muter
// 1 3 5 4 3 3 salam muter
// 1 3 5 4 2 3 cluter malek
// 2 5 5 4 2 3 fio name
// 2 3 5 4 2 3 halo
// 2 5 5 3 5 4 triangle squarior
// 3 4 5 4 2 1 bird
// 3 4 5 4 3 1 selector box
// 3 4 5 4 3 3 Canada amer
// 4 4 0 4 5 2 amer summer



struct student {
  char name[63];
  int group;
  int ses[5];
  int min_mark; // поле для хранения минимальной оценки студента - если она меньше 4, для фильтрации
  float mid_value; // поле для того, чтобы сразу сохранить данные о среднем балле
};

// подсчитывает среднее значение массива интов (float) (для сортировки)
float calculate_mid_value(int *array, int size){
  if (size == 0)
    return printf("invalid input into calculate_mid_value func");
  int sum_value = 0;
  for (int i = 0; i < size; i++){
      sum_value += array[i];
  }
  return (float)sum_value/size;
}


// вытаскивает минимальное значение массива интов (для фильтрации)
int array_min(int *array, int size){
  if (size == 0)
    return printf("invalid input into array_min func");
  int min = array[0];
  for (int i = 0; i < size; i++){
    if (min > array[i])
      min = array[i];
  }
  return min;
}


// сортирует массив студентов по среднему баллу
void sort_array(struct student *array, int size){
  int i, j;
  struct student temp;
  for (i = 0; i < size; i++){
    for (j = 0; j < size - 1; j++){
      if (array[j].mid_value > array[j + 1].mid_value){
        temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;
      }
    }
  }
}


// вводит массив студентов
void inp_array(struct student *array, int size){
  int i, j;
  char symbol;
  printf("Enter the data of %d students:\n", size);
  printf("group_number, marks of 5 subjects and name, sepd by ' ':\n");
  for (i = 0; i < size; i++){
    
    scanf("%d", &array[i].group);
    
    for (j = 0; j < 5; j++){
      scanf("%d", &array[i].ses[j]);
    }
    
    assert (getchar() == ' '); // пробел
    
    fgets(array[i].name, 63, stdin);
    
    array[i].name[strlen(array[i].name) - 1] = 0; // убираем \n
    array[i].mid_value = calculate_mid_value(array[i].ses, 5);
    array[i].min_mark = array_min(array[i].ses, 5);
    
  }
  printf("\n\n");
}


// крассиво печатает массив студентов
void show_array(struct student *array, int size, int without_lohs, int show_mark){
  int j = 0;
  if (show_mark)
    printf("name, group, mid_mark\n");
  else
    printf("name, group\n");
  
  for (int i = 0; i < size; i++){
    if (!without_lohs || array[i].min_mark >= 4){
      j++;
      if (show_mark)
        printf("%s %d %2.1f\n", array[i].name, array[i].group, array[i].mid_value);
      else
        printf("%s %d\n", array[i].name, array[i].group);
    }
  }
  if (j == 0)
    printf("no students\n");
  printf("\n\n");
}


int main() {
  int quantity = 10;
  int inputed_quanity;
  
  // ввод количества студентов
  printf("students quantity (0 for escape) : ");
  scanf("%d", &inputed_quanity);

  // обработка введенных выше данных
  if (inputed_quanity < 0) 
    return printf("invalid data, inputed_quanity must be >= 0, got %d\n", inputed_quanity);
  else if (inputed_quanity == 0)
    printf("escaped, quantity = %d\n", quantity);
  else
    quantity = inputed_quanity;

  // создаем массив студентов
  struct student students[quantity];

  // работа с данными
  inp_array(students, quantity); // заполняем массив студентов
  show_array(students, quantity, 0, 1); // смотрим все данные
  sort_array(students, quantity); // сортируем массив по среднему баллу
  show_array(students, quantity, 0, 1); // смотрим данные

  show_array(students, quantity, 1, 0); // смотрим репрезентативные данные
}

