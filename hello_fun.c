#include <stdio.h>
#include <stdlib.h>




int main()
{
    int x;
    char y[80];

    printf("Hello world, \nC language\n");

    printf("write the number, witch I will guess\n");

    scanf("%d", &x);
    printf("your number is %d\n", x);

    printf("what do you think about my ability?\n");
    scanf("%s", &y);

    printf("your opinion is \"%s\" \n", y);
    printf("amazing\n");


    return 0;
}