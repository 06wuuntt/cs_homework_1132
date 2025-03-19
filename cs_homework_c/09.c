#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef enum {start, build_num, build_float, build_var, integer, floatnum, variable, string, stop} state_t;

state_t getState(char ch, state_t current_state, int *dot_count) {
    if (current_state == start) {
        if (isdigit(ch) || ch == '-') return build_num;
        else if (isalpha(ch) || ch == '_') return build_var;
        // else return string;
    }
    if (current_state == build_num) {
        if (isdigit(ch)) return build_num;
        else if (ch == '.' && *dot_count == 0) {  
            *dot_count += 1;
            return build_float;
        }
        else if (ch == '\0') return integer;
        else return string;
    }
    if (current_state == build_float) {
        if (isdigit(ch)) return build_float;
        else if (ch == '\0') return floatnum;
        else current_state = build_var;
    }
    if (current_state == build_var) {
        if (ch == '_' || isdigit(ch) || isalpha(ch)) return build_var;
        else if (ch == '\0') return variable;
        else return string;
    }
}

int main() {
    int n;
    char data[100];
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%s", data);
        data[strcspn(data, "\n")] = '\0';
        state_t current_state = start;
        int dot_count = 0;
        int index = 0;
        do {
            current_state = getState(data[index], current_state, &dot_count);
        }while (data[index++] != '\n' && current_state != string);
        if (current_state == integer) {
            printf("integer\n");
        }else if (current_state == floatnum) {
            printf("float\n");
        }else if (current_state == variable) {
            printf("variable\n");
        }else if (current_state == string) {
            printf("string\n");
        }
    }
    return 0;
}