#include <studio.h>
#include <math.h>

int main{
    int a,b,r;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    while (b!=0)
    {
        /* code */
        r=a % b;
        a=b;
        b=r;
    }
    printf("PGCD = %d\n", a);
    return 0;
}