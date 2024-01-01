#include <stdio.h>
#include <math.h>

int mostCut(int x, int y) {
    int n = 0;
    int i = 0;
    int result = 1;
    while (result <= x && result <= y) {
        n = i;
        i++;
        result = pow(2, i);
    }
    return pow(2, n);
}

int cutBorder(int x, int y) {
    printf("Checking at %d %d\n", x, y);
    if (x <= 1 || y <= 1) {
        return x * y;
    }

    int expo = mostCut(x, y);
    if (expo == x && expo == y) {
        return 1;
    }

    if (x > y) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    printf("Split to %d %d\n", x % expo, y);
    printf("Split to %d %d\n", y - expo, x - (x % expo));
    int bor_1 = cutBorder(x % expo, y);
    int bor_2 = cutBorder(y - expo, x - (x % expo));

    return 1 + bor_1 + bor_2;
}

int main(void) {
    int x, y;
    int count=0;
    scanf("%d %d", &x, &y);
    printf("%d\n", cutBorder(x, y));
    printf("%d\n",count);
    return 0;
}
// T(n) = 2T(n/2) + log(n)
// O(2^n)