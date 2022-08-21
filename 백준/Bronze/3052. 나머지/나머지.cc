#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int num[10], i, j = 0, cnt = 0, result = 0;

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num[i]);
        num[i] %= 42;
    }
    for (i = 0; i < 10; i++)
    {
        cnt = 0;
        for (j = 0; j < i; j++)
            if (num[i] == num[j])
                cnt++;
        if (cnt == 0)
            result++;
    }

    printf("%d\n", result);
}