#include <stdio.h>
#include <string.h>

int turnToBin(char binnum[]) {
    int decimalnum = 0;
    for (int i = 0; i < 8; i++) {
        decimalnum += (binnum[i] - '0')*(1 << (7 - i));
    }
    return decimalnum;
}

int c(int m, int count) {
    if (m == 0 || m == 1) {
        return count;
    }
    else if (m % 2 == 0) {
        return c(m/2, ++count);
    }
    else {
        return c((m+1)/2, ++count);
    }
}

void turnTodecimal(int num) {
    char bin[5];
    int index = 0;
    while (index < 4) {
        int c = num % 2;
        num /= 2;
        bin[index] = c + '0';
        index++;
    }
    for (int i = 0; i < 2; i++) {
        char temp = bin[i];
        bin[i] = bin[3-i];
        bin[3-i] =  temp;
    }
    puts(bin);
}

int main() {
    while(1) {
        char binnum[8];
        scanf("%s", binnum);
        if (strcmp(binnum, "-1") == 0) break;
        int decimalnum = turnToBin(binnum);
        turnTodecimal(c(decimalnum, 0));
    }
    return 0;
}