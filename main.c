#include <stdio.h>
#include <stdlib.h>

#include <math.h>

int is_right_turn(int x1, int y1, int x2, int y2, int x3, int y3) {
    float k, b;
    int higher;
    k = (x1 - x2) / (y1 - y2);
    b = y1 - k * x1;
    higher = k * x3 + b <= y3;

    if (x1 == x2){
        if ((y1 > y2) == (x3 > x2))
            return 1;
        else
            return 0;
    }
    else {
        if ((higher && x1 > x2) || (!higher && x1 < x2))
            return 1;
        else
            return 0;
    }
}




int main(){
    float x1, y1, x2, y2, x3, y3, x, y;

    printf("введите координаты треугольника через пробел - x1 y1 x2 y2 x3 y3 - всего 6 чисел, например:\n 1 1 2 2 1 2\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

    printf("введите координаты точки через пробел - x y\nнапример:\n0 0 \n");
    scanf("%f %f", &x, &y);

    float a, b, c, tmp;

    a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

    if (a > b) { tmp = a; a = b; b = tmp; }
    if (a > c) { tmp = a; a = c; c = tmp; }
    if (b > c) { tmp = b; b = c; c = tmp; }

    if (a + b <= c){
        printf("thees is not a triangle\n");
        return 0;
    }

    if (is_right_turn(x1, y1, x2, y2, x, y) == is_right_turn(x2, y2, x3, y3, x, y) == is_right_turn(x3, y3, x1, y1, x, y))
        printf("point is in triangle\n");
    else
        printf("point is out of the triangle\n");

    return 0;
}