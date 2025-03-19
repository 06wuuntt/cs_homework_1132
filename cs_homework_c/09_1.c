#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {start, build_num, build_float, build_var, integer, floatnum, variable, string, stop} state_t;

state_t getState(char ch, state_t current_state, int *dot_count, int index, const char *data) {
    if (current_state == start) {
        if (ch == '-') {
            if (data[index + 1] == '0' && data[index + 2] == '\0') return string;
            if (isdigit(data[index + 1])) return build_num;
            return string;
        }
        if (isdigit(ch)) {
            if (ch == '0' && data[1] != '\0' && data[1] != '.') return string;
            return build_num;
        }
        if (isalpha(ch) || ch == '_') return build_var;
        return string;
    }

    if (current_state == build_num) {
        if (isdigit(ch)) return build_num;
        if (ch == '.' && *dot_count == 0) {  
            *dot_count += 1;
            if (data[index + 1] == '\0') return string;
            return build_float;
        }
        if (ch == '\0') return integer;
        return string;
    }

    if (current_state == build_float) {
        if (isdigit(ch)) return build_float;
        if (ch == '\0' && *dot_count == 1) return floatnum;
        return string;
    }

    if (current_state == build_var) {
        if (isalnum(ch) || ch == '_') return build_var;
        if (ch == '\0') return variable;
        return string;
    }

    return string;
}

int main() {
    int n;
    char data[100];

    scanf("%d", &n);
    getchar();

    while (n--) {
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = '\0';

        state_t current_state = start;
        int dot_count = 0;
        int len = strlen(data);

        for (int i = 0; i <= len; i++) {
            current_state = getState(data[i], current_state, &dot_count, i, data);
            if (current_state == string) break;
        }

        if (current_state == integer) {
            printf("integer\n");
        } else if (current_state == floatnum) {
            printf("float\n");
        } else if (current_state == variable && len >= 1 && len <= 10) {
            printf("variable\n");
        } else {
            printf("string\n");
        }
    }

    return 0;
}