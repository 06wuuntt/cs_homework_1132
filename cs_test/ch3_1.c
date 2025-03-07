#include <stdio.h>

int climbstairs(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    return climbstairs(n - 1) + climbstairs (n - 2) + climbstairs(n - 3);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", climbstairs(n));

    return 0;

}