#include <stdlib.h>
#include <stdio.h>


int max(int a, int b){
    if (a > b)
        return a;
    else
        return b;
}


int main(){
    int len;
    if (len == 0){
        printf("invalid len");
        return 0;
    }


    printf("enter len:");
    scanf("%d", &len);

    int mas[len];
    int buf;
    for (int i = 0; i < len; i++){
        printf("elem: ");
        scanf("%d", &buf);
        mas[i] = buf;
    }
    int m; // calculate_loop count
    printf("enter M: ");
    scanf("%d", &m);
    int l, r;
    int last_num_buf;
    int res, act_res;

    for (int i = 0; i < m; i ++){
        printf("enter (L R): ");
        scanf("%d %d", &l, &r);
        if (l < 0 || r >= len || l > r) {
            printf("invalid data\n");
            continue;
        }
        if (l == r) {
            printf("0");
            continue;
        }
        last_num_buf = mas[l];
        act_res = 0;
        res = 0;
        for (int j = l + 1; j <= r; j++){

            if (mas[j] == last_num_buf)
                act_res++;
            else {
                last_num_buf = mas[j];
                act_res = 0;
            }
            res = max(res, act_res);

        }
        printf("res for l = %d and r = %d is %d\n", l, r, res);
    }
}