#include <stdio.h>
#include <string.h>

void reverse(char *num) {
    int len = strlen(num);
    char temp[102];
    for (int i = 0; i < len; i++) {
        temp[i] = num[len - i - 1];
    } 
    for (int i = 0; i < len; i++) {
        num[i] = temp[i];
    }
}

void swap(char *num1, char *num2) {
    char temp[102];
    strcpy(temp, num1);
    strcpy(num1, num2);
    strcpy(num2, temp);
}

void add(char *num1, char *num2, char *addresult) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, i = 0;
    reverse(num1);
    reverse(num2);
    while (i < len1 || i < len2 || carry) {
        int digit1, digit2;
        digit1 = (i < len1) ? num1[i] - '0' : 0; // 補0
        digit2 = (i < len2) ? num2[i] - '0' : 0; // 補0
        int sum = digit1 + digit2 + carry;
        addresult[i] = (sum % 10) + '0';
        carry = sum / 10;
        i++;
    }
    reverse(num1);
    reverse(num2);    
}

void sub(char *num1, char *num2, char *subresult) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int borrow = 0, i = 0;
    reverse(num1);
    reverse(num2);
    while (i < len1 || i < len2) {
        int digit1, digit2;
        digit1 = (i < len1) ? num1[i] - '0' : 0; // 補0
        digit2 = (i < len2) ? num2[i] - '0' : 0; // 補0
        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        subresult[i] = (digit1 - digit2) + '0';
        i++;
    }
    reverse(num1);
    reverse(num2);
}

void mul(char *num1, char *num2, char *mulresult) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, carry1= 0, k = 0; 
    char temp[200] = {'0'};
    reverse(num1);
    reverse(num2);
    if (len1 < len2) {
        swap(num1, num2);
        int l = len1;
        len1 = len2;
        len2 = l;
    }
    for (int i = 0; i < len2; i++) {
        char temp[200] = {'0'};
        carry = 0;
        int index = 0;
        for (index = 0; index < i; index++) {
            temp[index] = '0';
        }
        for (int j = 0; j < len1; j++) {
            int digit1 = num1[j] - '0';
            int digit2 = num2[i] - '0';
            int product = digit1 * digit2 + carry;
            temp[index] = (product % 10) + '0';
            carry = product / 10;
            index++;
        }
        if (carry) {
            temp[index] = carry + '0';
        }
        char copymulresult[200] = {'0'};
        strcpy(copymulresult, mulresult);
        k = 0;
        while (k < strlen(temp) || k < strlen(copymulresult) || carry1) {
            int digit1, digit2;
            digit1 = (k < strlen(temp)) ? temp[k] - '0' : 0; // 補0
            digit2 = (k < strlen(copymulresult)) ? copymulresult[k] - '0' : 0; // 補0
            int sum = digit1 + digit2 + carry1;
            mulresult[k] = (sum % 10) + '0';
            carry1 = sum / 10;
            k++;
        }
        
    }
    reverse(num1);
    reverse(num2);
}

void calculate(char *num1, char *num2, int condition) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char addresult[200] = {'0'}, subresult[200] = {'0'}, mulresult[200] = {'0'};
    if (len1 == len2) {
        int cmp = strcmp(num1, num2);
        if (condition == 1 || condition == 4) {
            add(num1, num2, addresult);
            if (condition == 1) {
                addresult[strlen(addresult)] = '-';
                if (cmp > 0) {
                    sub(num1, num2, subresult);
                    subresult[strlen(subresult)] = '-';
                } else if (cmp < 0) {
                    sub(num2, num1, subresult);
                } else {
                    subresult[0] = '0';
                }
            } else if (condition == 4) {
                if (cmp > 0) {
                    sub(num1, num2, subresult);
                } else if (cmp < 0) {
                    sub(num2, num1, subresult);
                    subresult[strlen(subresult)] = '-';
                } else {
                    subresult[0] = '0';
                }
            }
        } else if (condition == 2) {
            add(num1, num2, subresult);
            subresult[strlen(subresult)] = '-';
            if (cmp > 0) {
                sub(num1, num2, addresult);
                addresult[strlen(addresult)] = '-';
            } else if (cmp < 0) {
                sub(num2, num1, addresult);
            } else {
                addresult[0] = '0';
            }
        } else if (condition == 3) {
            add(num1, num2, subresult);
            if (cmp > 0) {
                sub(num1, num2, addresult);
            } else if (cmp < 0) {
                sub(num2, num1, addresult);
                addresult[strlen(addresult)] = '-';
            } else {
                addresult[0] = '0';
            }
        }
    } else {
        if (len1 < len2) {
            if (condition == 1 || condition == 4) {
                add(num1, num2, addresult);
                sub(num2, num1, subresult);
                if (condition == 1) {
                    addresult[strlen(addresult)] = '-';
                } else if (condition == 4) {
                    subresult[strlen(subresult)] = '-';
                }
            } else if (condition == 2 || condition == 3) {
                sub(num2, num1, addresult);
                add(num1, num2, subresult);
                if (condition == 3) {
                    addresult[strlen(addresult)] = '-';
                } else if (condition == 2) {
                    subresult[strlen(subresult)] = '-';
                }
            }
        } else if (len1 > len2) {
            if (condition == 1 || condition == 4) {
                add(num1, num2, addresult);
                sub(num1, num2, subresult);
                if (condition == 1) {
                    addresult[strlen(addresult)] = '-';
                    subresult[strlen(subresult)] = '-';
                }
            } else if (condition == 2 || condition == 3) {
                sub(num1, num2, addresult);
                add(num1, num2, subresult);
                if (condition == 2) {
                    addresult[strlen(addresult)] = '-';
                    subresult[strlen(subresult)] = '-';
                }
            }
        }
    }
    mul(num1, num2, mulresult);
    if (condition == 2 || condition == 3) {
        mulresult[strlen(mulresult)] = '-';
    }

    reverse(addresult);
    reverse(subresult);
    reverse(mulresult);
    printf("%s\n%s\n%s\n", addresult, subresult, mulresult);
}

void dealnegative(char *num) {
    int len = strlen(num);
    if (num[0] == '-') {
        for (int i = 0; i < len - 1; i++) {
            num[i] = num[i + 1];
        }
        num[len - 1] = '\0';
    }
   
}

int condition(char *num1, char *num2) {
    int cond;
    if (num1[0] == '-' && num2[0] == '-') {   // both negative
        cond = 1;
    } else if (num1[0] == '-' && num2[0] != '-') {  // num1 negative
        cond = 2;
    } else if (num1[0] != '-' && num2[0] == '-') {  // num2 negative
        cond = 3;
    } else if (num1[0] != '-' && num2[0] != '-') {  // both positive
        cond = 4;
    }
    dealnegative(num1);
    dealnegative(num2);
    return cond;
}

int main() {
    char num1[102], num2[102];
    char addresult[102], subresult[102], mulresult[102];
    scanf("%s %s", num1, num2);
    int cond = condition(num1, num2);
    calculate(num1, num2, cond);
    // printf("%s %s %d\n", num1, num2, cond);
}