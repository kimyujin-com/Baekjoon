#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int f[40];
int cnt = 0;

int fib(int n) 
{
    if (n == 1 || n == 2) {
        cnt++;
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) 
{
    cnt++;
    int i;
    f[1] = f[2] = -1;
    for (i = 3; i <= n; i++) {
        cnt++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(void)
{
    int n;

    scanf("%d", &n);

    fib(n);
    printf("%d ", cnt);
    cnt = -1;
    fibonacci(n);
    printf("%d\n", cnt);
}