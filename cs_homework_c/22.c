#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp0 = a[0];
    int temp1 = a[1];
    a[0] = b[0];
    a[1] = b[1];
    b[0] = temp0;
    b[1] = temp1;
}

void sortResult(int result[][2], int result_count) {
    for (int i = 0; i < result_count; i++) {
        for (int j = 0; j < result_count - i - 1; j++) {
            if (result[j][0] > result[j + 1][0] || (result[j][0] == result[j + 1][0] && result[j][1] > result[j + 1][1])) {
                swap(result[j], result[j + 1]);
            }
        }
    }
}

char *drawColor(int n, int x, int y, int square_size, char *df, int result[][2], int *result_count) {
    if (*df == '\0') return df;
    if (*df == '1') {
        for (int i = x; i < x + square_size; i++) {
            for (int j = y; j < y + square_size; j++) {
                result[*result_count][0] = i;
                result[*result_count][1] = j;
                (*result_count)++;
            }
        }
        return df + 1;
    } else if (*df == '2') {
        int half = square_size / 2;
        df++;
        df = drawColor(n, x, y, half, df, result, result_count);
        df = drawColor(n, x, y + half, half, df, result, result_count);
        df = drawColor(n, x + half, y, half, df, result, result_count);
        df = drawColor(n, x + half, y + half, half, df, result, result_count);
        return df;
    }
    return df + 1;
}

int main() {
    char df_exp[100];
    int n;
    scanf("%s %d", df_exp, &n);
    int result[n * n][2];
    int result_count = 0;
    drawColor(n, 0, 0, n, df_exp, result, &result_count);
    sortResult(result, result_count);
    if (result_count == 0) printf("all white");
    for (int i = 0; i < result_count; i++) {
        printf("%d,%d\n", result[i][0], result[i][1]);
    }
    return 0;
}