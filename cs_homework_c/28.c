#include <stdio.h>
#include <string.h>

int Upper_or_Lower(char alpha) {
    if (alpha >= 'A' && alpha <= 'Z') {
        return 1; //upper
    } else if (alpha >= 'a' && alpha <= 'z') {
        return  0; //lower
    }
}

void checkString(int k, char *str, int *maxcorrect) {
    int len = strlen(str);
    for (int start = 0; start < len; start++) {
        int expected = Upper_or_Lower(str[start]), correct = 0, i = start;
        while (i + k <= len) {
            int valid = 1;
            for (int j = 0; j < k; j++) {
                if (Upper_or_Lower(str[i + j]) != expected) {
                    valid = 0;
                    break;
                }
            }
            if (!valid) break;
            correct += k;
            i += k;
            expected = !expected;
        }
        if (correct > *maxcorrect) {
            *maxcorrect = correct;
        }
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    while (n--) {
        char str[100];
        int maxcorrect = 0;
        scanf("%s %d", str, &k);
        checkString(k, str, &maxcorrect);
        if (maxcorrect == k) maxcorrect = 0;
        printf("%d\n", maxcorrect);
    }
    return 0;
}