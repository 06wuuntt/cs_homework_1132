#include <stdio.h>
#include <stdlib.h>

int findgcd(int x, int y) {
    if (y == 0) return x;
    else return findgcd(y, x%y);
}

void cal_gcd(int *x, int *y) {
    int gcd = findgcd(*x, *y);
    *x /= gcd;
    *y /= gcd;
}

void printEquation(int x_dis, int y_dis, int x1, int y1, int x2, int y2) {
    // y = mx + b
    if (x_dis == 0) {
        printf("x = %d\n", x1);
        return;
    }
    else if (y_dis == 0) {
        printf("y = %d\n", y1);
        return;
    }
    printf("y = ");
    if (y_dis % x_dis == 0) {    // print m
        if (y_dis / x_dis == 1) printf("x ");
        else if (y_dis / x_dis == -1) printf("-x ");
        else printf("%dx ", y_dis/x_dis);
    }
    else {
        if (x_dis*y_dis < 0) printf("-%d/%dx ", abs(y_dis), abs(x_dis));
        else printf("%d/%dx ", abs(y_dis), abs(x_dis));
    }
    int numerator = x2*y1 - x1*y2, denominator = x2 - x1; // print b
    cal_gcd(&numerator, &denominator);
    if (numerator % denominator == 0 && numerator / denominator != 0) {
        if (numerator / denominator > 0) printf("+ %d", numerator / denominator);
        else printf("- %d", abs(numerator/ denominator));
    }
    else if (numerator % denominator != 0) {
        if (numerator * denominator < 0) printf("- %d/%d", abs(numerator), abs(denominator));
        else printf("+ %d/%d", abs(numerator), abs(denominator));
    }
    printf("\n");
}

int main() {
    int n, x1, x2, y1, y2;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int y_dis = y1 - y2, x_dis = x1 - x2;
        cal_gcd(&x_dis, &y_dis);
        printEquation(x_dis, y_dis, x1, y1, x2, y2);
    }
    return 0;
}