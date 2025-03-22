#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isError(char *s) {
    int len = strlen(s), flag = 1;
    while (len > 0 && isspace(s[len - 1])) len--;
    if (!isalpha(s[0]) && s[0] != '_') flag = 0;
    else if (!isalpha(s[len-1]) && s[len-1] != '_') flag = 0;
    return flag;
}

void reverse(char *s) {
    int len = strlen(s);
    int left = 0, right = len-1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    printf("%s\n", s);
    // printf("%d %d\n", left, right);
}

void compareLen(char *s1, char *s2) {
    int s1len = strlen(s1), s2len = strlen(s2);
    int count = 0;
    for (int i=0; i < s1len; i++) {
        if (s1[i] == ' ') count++;
    }
    s1len -= count;
    count = 0;
    for (int i=0; i < s2len; i++) {
        if (s2[i] == ' ') count++;
    }
    s2len -= count;
    // printf("%d %d\n", s1len, s2len);
    if (s1len >= s2len) {
        reverse(s1);
    } else if (s2len > s1len) {
        reverse(s2);
    }
}

int main() {
    char s1[200], s2[200];
    fgets(s1, 100, stdin);
    fgets(s2, 100, stdin);
    // printf("%s%s", s1, s2);
    if (isError(s1) && isError(s2)) {
        reverse(s1);
        reverse(s2);
        compareLen(s1, s2);
    } else {
        printf("Error");
    }
    return 0;
}