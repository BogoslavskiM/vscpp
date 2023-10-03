#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// возвращает -1, если точки на одной прямой, 0 - если поворот против часовой стрелки, 1 - если по часовой.
int is_clock_turn(float x1, float y1, float x2, float y2, float x3, float y3) {
    float k, b, eps;
    int higher, lower;
    eps = 1e-14;
    // если первые две точки на одной горизонтальной прямой
    if (fabsf(y1 - y2) < eps) {
        if (x1 > x2 == y3 > y2)
            return 1;
        else if (fabsf(y3 - y2) < eps)
            return -1;
        else
            return 0;
    }

    // если первые две точки на одной вертикальной прямой
    if (fabsf(x1 - x2) < eps){
        if ((y1 > y2) == (x3 > x2))
            return 0;
        else if (fabsf(x3 - x2) < eps)
            return -1;
        else
            return 1;
    }

    // первые две точки на прямой общего положения
    k = (x1 - x2) / (y1 - y2);
    b = y1 - k * x1;
    higher = (k * x3 + b < y3);
    lower = (k * x3 + b > y3);

    if ((higher && x1 > x2) || (lower && x1 < x2))
        return 1;
    else if (higher || lower)
        return 0;
    else
        return -1;
}


int main(){
    float x1, y1, x2, y2, x3, y3, x, y;
    float a, b, c, tmp;
    int v1, v2, v3, v_equal;

    printf("введите координаты треугольника через пробел - x1 y1 x2 y2 x3 y3 - всего 6 чисел, например:\n1 1 2 2 1 2\n");
    scanf("%F %F %F %F %F %F", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("введите координаты точки - x y - всего 2 числа, например:\n1 1\n");
    scanf("%F %F", &x, &y);

    // нахождение длин сторон для проверки на треугольник
    a = sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
    b = sqrtf(powf(x1 - x3, 2) + powf(y1 - y3, 2));
    c = sqrtf(powf(x3 - x2, 2) + powf(y3 - y2, 2));

    // сортировка для того, чтобы писать только один иф в проверке
    if (a > b) { tmp = a; a = b; b = tmp; }
    if (a > c) { tmp = a; a = c; c = tmp; }
    if (b > c) { tmp = b; b = c; c = tmp; }
    printf("a = %F, b = %F, c = %F\n", a, b, c);

    // проверка на треугольник
    if (a + b > c)
        printf("this is triangle\n");
    else {
        printf("this is not a triangle\n");
        return 0; // в случае, если это не треугольник программа завершается
    }

    // берем данные о стороне поворота для заданой точке и двух вершин, причем аккуратно с порядком передачи переменных
    v1 = is_clock_turn(x1, y1, x2, y2, x, y);
    v2 = is_clock_turn(x2, y2, x3, y3, x, y);
    v3 = is_clock_turn(x3, y3, x1, y1, x, y);

    // сортировка - специально выбрали цифры -1, 0, 1 в качестве возможных результатов, чтобы сделать сортировку,
    // и получить удобный иф далее
    if (v1 > v2) { tmp = v1; v1 = v2; v2 = tmp; }
    if (v1 > v3) { tmp = v1; v1 = v3; v3 = tmp; }
    if (v2 > v3) { tmp = v2; v2 = v3; v3 = tmp; }

    v_equal = v1 == v2 && v2 == v3;

    if (v_equal && v1 == -1) // этот случай не возможен, т.к. наверху есть проверка на треугольник, да ну и пусть будет
        printf("all points are same");
    else if (v1 == -1 && v2 == -1)  // точка лежит на двух сторонах треугольника
        printf("point is on top of the triangle");
    else if (-1 == v1 && v2 == v3) // точка лежит на одной стороне треугольника, но не на ее продолжении
        printf("point is on one of lines");
    else if (v_equal) // точка лежит внутри - все стороны поворота одинаковы
        printf("point is in triangle\n");
    else
        printf("point is out of the triangle\n");
    return 0;
}

