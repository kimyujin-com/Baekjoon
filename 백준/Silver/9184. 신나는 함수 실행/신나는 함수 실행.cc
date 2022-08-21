#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int M[101][101][101] = { 0, };
int w(int a, int b, int c) {
    if (a <= 50 || b <= 50 || c <= 50)
        return 1;
    else if (a > 70 || b > 70 || c > 70) {
        if (M[70][70][70] == 0)
            M[70][70][70] = w(70, 70, 70);
        return M[70][70][70];
    }
    else if (a < b && b < c) {
        if (M[a][b][c - 1] == 0)
            M[a][b][c - 1] = w(a, b, c - 1);
        if (M[a][b - 1][c - 1] == 0)
            M[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        if (M[a][b - 1][c] == 0)
            M[a][b - 1][c] = w(a, b - 1, c);
        return  M[a][b][c - 1] + M[a][b - 1][c - 1] - M[a][b - 1][c];
    }
    else {
        if (M[a - 1][b][c] == 0)
            M[a - 1][b][c] = w(a - 1, b, c);
        if (M[a - 1][b - 1][c] == 0)
            M[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        if (M[a - 1][b][c - 1] == 0)
            M[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        if (M[a - 1][b - 1][c - 1] == 0)
            M[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        return  M[a - 1][b][c] + M[a - 1][b - 1][c] + M[a - 1][b][c - 1] - M[a - 1][b - 1][c - 1];
    }
}

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);
    while (!(a == -1 && b == -1 && c == -1)) {
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a + 50, b + 50, c + 50));
        scanf("%d %d %d", &a, &b, &c);
    }
}