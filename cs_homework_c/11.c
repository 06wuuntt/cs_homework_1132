#include <stdio.h>

int getGraycode(int n, int k) {
    if (n == 1) {
        printf("%d", k);
    }
    else if (k < (1 << (n-1))) {
        printf("%d", 0);
        return getGraycode(n-1, k);
    }
    else {
        printf("%d", 1);
        return getGraycode(n-1, (1 << n) - 1 - k);
    }
}

int main() {
    int n, k;
    while(1) {
        scanf("%d", &n);
        if (n == -1) break;
        scanf("%d", &k);
        getGraycode(n, k);
        printf("\n");
    }

    return 0;
}