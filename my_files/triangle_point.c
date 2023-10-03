#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_clock_turn(int x1, int y1, int x2, int y2, int x3, int y3) {
    float k, b;
    int higher, lower;
    if (abs(y1 - y2) < 0.00000001) {
        if (x1 > x2 == y3 > y2)
            return 1;
        else if (abs(y3 - y2) < 0.00000001)
            return -1;
        else
            return 0;
    }

    if (abs(x1 - x2) < 0.00000001){
        if ((y1 > y2) == (x3 > x2))
            return 0;
        else if (abs(x3 - x2) < 0.00000001)
            return -1;
        else
            return 1;
    }

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

    a = sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2));
    b = sqrtf(powf(x1 - x3, 2) + powf(y1 - y3, 2));
    c = sqrtf(powf(x3 - x2, 2) + powf(y3 - y2, 2));

    if (a > b) { tmp = a; a = b; b = tmp; }
    if (a > c) { tmp = a; a = c; c = tmp; }
    if (b > c) { tmp = b; b = c; c = tmp; }
    printf("a = %F, b = %F, c = %F\n", a, b, c);

    if (a + b > c)
        printf("this is triangle\n");
    else {
        printf("this is not a triangle\n");
        return 0;
    }

    v1 = is_clock_turn(x1, y1, x2, y2, x, y);
    v2 = is_clock_turn(x2, y2, x3, y3, x, y);
    v3 = is_clock_turn(x3, y3, x1, y1, x, y);

    if (v1 > v2) { tmp = v1; v1 = v2; v2 = tmp; }
    if (v1 > v3) { tmp = v1; v1 = v3; v3 = tmp; }
    if (v2 > v3) { tmp = v2; v2 = v3; v3 = tmp; }

    v_equal = v1 == v2 && v2 == v3;

    if (v_equal && v1 == -1)
        printf("all points are same");
    else if (v1 == -1 && v2 == -1)
        printf("point is on top of the triangle");
    else if (-1 == v1 || -1 == v2 || -1 == v3)
        printf("point is on one of lines");
    else if (v_equal)
        printf("point is in triangle\n");
    else
        printf("point is out of the triangle\n");
    return 0;
}

