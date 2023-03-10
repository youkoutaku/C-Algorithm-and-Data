/*  
    数値積分 シンプソン則
    (x0,f(x0)),(x1,f(x1)),(x2,f(x2))3点を通る二次曲線ｇ（ｘ）を作る.
    [x0~x2]g(x) dx= h*( f(x0) +4f(x1) + f(x2) )/3
    奇数項の合計fo
    偶数項の合計fe
    [a ~ b]f(x) dx = {f(a) + f(b) +4( fo + f(b-h) ) + 2*fe}*h/3
*/

#include <stdio.h>
#include <math.h>

#define f(x) (sqrt(4-(x)*(x))) //関数

int main(void){
    int k;
    double a,b,n,h,fo,fe,sum;

    printf("積分区間　A, B ?");
    scanf("%lf %lf", &a, &b);

    n=50;
    h=(b-a)/(2*n);

    fo=0; fe=0;
    for(k=1; k <= 2*n-3; k+=2){
        fo = fo + f(a+h*k);
        fe = fe + f(a+h*(k+1));
    }
    sum = ( f(a) + f(b) + 4*(fo + f(b-h) ) + 2*fe)*h/3;
    printf("    /%f\n",b);
    printf("    |   sqrt(4-x*x) =%f\n", sum);
    printf("    /%f\n",a);

    return 0;
}