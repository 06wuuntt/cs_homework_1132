#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char *num) {
    char temp[50];
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        temp[i] = num[len - i - 1];
    }
    for (int i = 0; i < len; i++) {
        num[i] = temp[i];
    }
}

void swap(char *num1, char *num2) {
    char temp[50];
    strcpy(temp, num1);
    strcpy(num1, num2);
    strcpy(num2, temp);
}

char mul(char *num1, char *num2, char *mulresult) {
    // printf("num1 = %s, num2 = %s\n", num1, num2);
    int len1 = strlen(num1), len2 = strlen(num2);
    int mulcarry = 0, addcarry = 0;
    reverse(num1);
    reverse(num2);
    // if (len1 < len2) {
    //     swap(num1, num2);
    //     int l = len1;
    //     len1 = len2;
    //     len2 = l;
    // }
    for (int i = 0; i < len2; i++) {
        char temp[50] = {'0'};
        mulcarry = 0;
        int index = 0;
        for (index = 0; index < i; index++) {
            temp[index] = '0';
        }
        for (int j = 0; j < len1; j++) {
            int digit1 = num1[j] - '0';
            int digit2 = num2[i] - '0';
            int product = digit1 * digit2 + mulcarry;
            temp[index] = (product % 10) + '0';
            mulcarry = product / 10;
            index++;
        }
        if (mulcarry) {
            temp[index] = mulcarry + '0';
        }
        char copymulresult[100] = {'0'};
        strcpy(copymulresult, mulresult);
        int k = 0;
        while (k < strlen(temp) || k < strlen(copymulresult) || addcarry) {
            int digit1, digit2;
            digit1 = (k < strlen(temp)) ? temp[k] - '0' : 0;
            digit2 = (k < strlen(copymulresult)) ? copymulresult[k] - '0' : 0;
            int sum = digit1 + digit2 + addcarry;
            mulresult[k] = (sum % 10) + '0';
            addcarry = sum / 10;
            k++;
        }
    }
    reverse(num1);
    reverse(num2);
    reverse(mulresult);
}

void div_rem(int quonum, char *num1, char *num2) {
    // num1 = quo * num2 + rem
    char mulresult[100] = {'0'}, quo[50] = {'0'}, rem[50] = {'0'};
    int index = 0;
    while (quonum != 0) {
        quo[index] = (quonum % 10) + '0';
        quonum /= 10;
        index++;
    }
    reverse(quo);
    mul(num2, quo, mulresult);
    int len1 = strlen(num1);
    int len2 = strlen(mulresult);
    reverse(num1);
    reverse(mulresult);
    int borrow = 0, i = 0;
    while(i < len1 || i < len2) {
        int digit1, digit2;
        digit1 = (i < len1) ? num1[i] - '0' : 0;
        digit2 = (i < len2) ? mulresult[i] - '0' : 0;
        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else borrow = 0;
        rem[i] = (digit1 - digit2) + '0';
        i++;
    }
    reverse(mulresult);
    reverse(rem);
    reverse(num1);
    while (1) {
        // printf("%d\n", i);
        if (rem[0] != '0') break;
        else {
            for (int j = 0; j < strlen(rem); j++) {
                rem[j] = rem[j+1];
            }
        }
    }
    if (strcmp(mulresult, num1) == 0) rem[0] = '0';
    // printf("quo = %s\n", quo);
    printf("%s\n%s", quo, rem);
}

void div_quo(char *num1, char *num2) {
    int quonum = 0;
    for (int i = 1; 1; i++) {
        char quo[50] = {'0'};
        quonum = i;
        int index = 0;
        while (quonum != 0) {
            quo[index] = (quonum % 10) + '0';
            quonum /= 10; 
            index++;
        }
        reverse(quo);
        // printf("i = %d, tempquo = %s\n", i, quo);
        char mulresult[100] = {'0'};
        mul(num2, quo, mulresult);
        // printf("mul = %s\n", mulresult);
        // printf("mullen = %d, num1len = %d, cmp = %d\n", strlen(mulresult), strlen(num1), strcmp(num1, mulresult));
        if (strlen(mulresult) > strlen(num1) || (strlen(mulresult) == strlen(num1) && strcmp(num1, mulresult) < 0)) {
            quonum = i - 1;
            break;
        } else if (strlen(mulresult) == strlen(num1) && strcmp(num1, mulresult) == 0) {
            quonum = i;
            break;
        }
    }
    // printf("%d\n", quonum);
    div_rem(quonum, num1, num2);
}

int main() {
    char num1[50], num2[50];
    scanf("%s %s", num1, num2);
    div_quo(num1, num2);
    return 0;
}