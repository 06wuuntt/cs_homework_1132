#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int integer;
    int nume;
    int deno;
} Fraction;

int findgcd(int m, int n) {
    if (n == 0) return m;
    else return findgcd(n, m%n);
}

int check(Fraction f) {
    if (f.deno == 0) return 0;
    else return 1;
}

Fraction turnImproper(char *num) {
    int len = strlen(num);
    Fraction f = {0, 0, 0};
    char temp_int[20] = {'0'}, temp_nume[20] = {'0'}, temp_deno[20] = {'0'};
    int i = 0, temp_i = 0;
    if (num[len-1] == ')') {
        while (1) {
            if (num[i] == '(') {
                f.integer = atoi(temp_int);
                i++;
                break;
            }
            else {
                temp_int[temp_i] = num[i];
                i++;
                temp_i++;
            }            
        }
    }
    temp_i = 0;
    while (1) {
        if (num[i] == '/') {
            f.nume = atoi(temp_nume);
            i++;
            break;
        }
        else {
            temp_nume[temp_i] = num[i];
            i++;
            temp_i++;
        }
    }
    temp_i = 0;
    while (1) {
        if (num[i] == ')' || num[i] == '\0') {
            f.deno = atoi(temp_deno);
            break;
        }
        else {
            temp_deno[temp_i] = num[i];
            i++;
            temp_i++;
        }
    }
    if (f.integer != 0) {
        if (f.integer < 0) {
            f.nume = f.integer * f.deno - f.nume;
        }
        else {
            f.nume = f.integer * f.deno + f.nume;
        }
        f.integer = 0;
    }
    // printf("%d %d %d\n", f.integer, f.nume, f.deno);
    return f;
}

Fraction calculate(Fraction f1, Fraction f2, char operator) {
    Fraction result = {0, 0, 0};
    switch (operator) {
        case '+':
            result.nume = f1.nume *f2.deno + f2.nume * f1.deno;
            result.deno = f1.deno * f2.deno;
            break;
        case '-':
            result.nume = f1.nume *f2.deno - f2.nume * f1.deno;
            result.deno = f1.deno * f2.deno;
            break;
        case '*':
            result.nume = f1.nume * f2.nume;
            result.deno = f1.deno * f2.deno;
            break;
        case '/':
            result.nume = f1.nume * f2.deno;
            result.deno = f1.deno * f2.nume;
            break;
    }
    if (result.deno < 0) {
        result.nume *= -1;
        result.deno *= -1;
    }
    // printf("%d %d %d\n", result.integer, result.nume, result.deno);
    return result;
}

int main() {
    char num1[20], num2[20], operator, c;
    while (1) {
        scanf("%s %c %s %c", num1, &operator, num2, &c);
        // printf("%s %c %s %c", num1, operator, num2, c);
        Fraction f1 = turnImproper(num1);
        Fraction f2 = turnImproper(num2);
        // printf("ans = ");
        if (check(f1) == 0 || check(f2) == 0) {
            printf("Error\n");
        }
        else {
            Fraction result = calculate(f1, f2, operator);
            if (result.deno == 0) {
                printf("Error\n");
                break;
            }
            else {
                int gcd = findgcd(result.nume, result.deno);
                result.nume /= gcd;
                result.deno /= gcd;
                if (abs(result.nume) > abs(result.deno)) {
                    result.integer = result.nume / result.deno;
                    result.nume = abs(result.nume) % abs(result.deno);
                    result.deno = abs(result.deno);
                }
                if (result.nume == 0) {
                    printf("%d\n", result.integer);
                }
                else if (result.integer == 0) {
                    if (result.deno < 0) {
                        result.nume *= -1;
                        result.deno *= -1;
                    }
                    printf("%d/%d\n", result.nume, result.deno);
                }
                else {
                    printf("%d(%d/%d)\n", result.integer, result.nume, result.deno);
                }
            }
        }
        if (c == 'n') break;
    }
    return 0;
}