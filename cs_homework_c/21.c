#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *a, int n) {
    int comp = 0, move = 0;
    for (int i = 0; i < n; i++) {
        int getMinIndex = i, min = a[i];
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (a[j] < min) {
                getMinIndex = j;
                min = a[j];
            }
        }
        if (getMinIndex != i) {
            swap(&a[i], &a[getMinIndex]);
            move += 3;
        }
    }
    printf("%d %d\n", comp, move);
}

void insertionSort(int *a, int n) {
    int comp = 0, move = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        int target = a[i];
        move++;
        while (++comp && j > 0) {
            if (++comp && a[j - 1] > target) {
                a[j] = a[j - 1];
                move++;
            } else
                break;
            j--;
        }
        a[j] = target;
        move++;
    }
    printf("%d %d\n", comp, move);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int copy_a[n];
    memcpy(copy_a, a, sizeof(a));
    selectionSort(a, n);
    insertionSort(copy_a, n);
    return 0;
}