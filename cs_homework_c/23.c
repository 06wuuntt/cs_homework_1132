#include <stdio.h>

void swap(int *a, int *b) {
    int temp0 = a[0];
    int temp1 = a[1];
    a[0] = b[0];
    a[1] = b[1];
    b[0] = temp0;
    b[1] = temp1;
}

void removeduplicate(int a[][2], int invernum) {
    printf("(%d,%d)\n", a[0][0], a[0][1]);
    for (int i = 1; i < invernum; i++) {
        if (a[i][0] != a[i - 1][0] || a[i][1] != a[i - 1][1]) {
            printf("(%d,%d)\n", a[i][0], a[i][1]);
        }
    }
}

void sortInversion(int a[][2], int invernum) {
    for (int i = 0; i < invernum; i++) {
        for (int j = 0; j < invernum - i - 1; j++) {
            if (a[j][0] > a[j + 1][0] || (a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1])) {
                swap(a[j], a[j + 1]);
            }
        }
    }
    removeduplicate(a, invernum);
}

void getInversion(int *a, int n) {
    int inversion[5000][2] = {0};
    int invernum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                inversion[invernum][0] = a[i];
                inversion[invernum][1] = a[j];
                invernum++;
            }
        }
    }
    if (invernum == 0) {
        printf("%d", 0);
        return;
    }
    // for (int i = 1; i < invernum; i++) {
    //     printf(" (%d, %d)\n", inversion[i][0], inversion[i][1]);
    // }
    sortInversion(inversion, invernum);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    getInversion(a, n);
    return 0;
}