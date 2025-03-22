#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void getdecimalnum(int *m, char *num) {
    int len = strlen(num), c, decimalnum = 0, base = *m, base_power = 1;
    for (int i=0; i<len; i++) {
        if (isalpha(num[len-i-1])) c = num[len-i-1] - 55;
        else c = num[len-i-1] - 48;
        decimalnum += c * base_power;
        base_power *= base;
        // printf("%d %d\n", base_power, decimalnum);
    }
    *m = decimalnum;
}

void convert(int *num, int *n) {
    int index = 0;
    char result[100];
    do {
        int c = (*num) % (*n);
        char str;
        (*num) /= (*n);
        if (c >= 10) result[index] = c + 55;
        else result[index] = c + 48;
        // printf("num = %d, c = %d, str = %c, result = %s\n", *num, c, str, result);
        index++;
    } while (*num != 0);
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
}

int main() {
    int m, n;
    char num[100];
    scanf("%d %s %d", &m, num, &n);
    getdecimalnum(&m, num);
    // printf("%d\n", m);
    convert(&m, &n);
    // printf("%d\n%s\n%d", m, num, n);
    return 0;
}