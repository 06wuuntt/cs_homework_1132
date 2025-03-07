#include <stdio.h>

int turnBit(char c){
    switch (c){
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        default: return -1;
    }
}

void compareset(int s0, int s1, char e1, char e2){
    int s2 = s1 | (1 << turnBit(e1));
    if (s2 & (1 << turnBit(e2))) printf("Y\n");
    else printf("N\n");

    if (s2 == (s2 & s0)) printf("Y\n");
    else printf("N\n");

    printf("%d\n", s0 & s2);
    printf("%d\n", s0 | s2);
    printf("%d", s0 & ~s2);
    // printf("%d", s2);
}


void check(int s0, int s1, char e1, char e2){
    int flag = 1;
    if (s0 < 0 || s0 > 63){
        printf("S0 ERROR\n");
        flag = 0;
    }
    if (s1 < 0 || s1 > 63){
        printf("S1 ERROR\n");
        flag = 0;
    }
    if (turnBit(e1) == -1){
        printf("e1 ERROR\n");
        flag = 0;
    }
    if (turnBit(e2) == -1){
        printf("e2 ERROR\n");
        flag = 0;
    }
    if (flag == 1){
        compareset(s0, s1, e1, e2);
    }
}

int main(){
    int s0, s1;
    char e1, e2;
    scanf("%d %d %c %c", &s0, &s1, &e1, &e2);
    check(s0, s1, e1, e2);
    return 0;
}