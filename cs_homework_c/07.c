#include <stdio.h>

void drawgraph1(int m) {
    for (int i=0; i<m; i++){
        for (int j=m-i-1; j>0; j--){
            printf("#");
        }

        for (int j=1; j<=2*i+1; j++){
            if (j%2 == 1) printf("*");
            else printf("%c", ((i-1)%3)+65);
        }

        for (int j=m-i-1; j>0; j--){
            printf("#");
        }        
        printf("\n");
    }
}

void drawgraph2(int m) {
    for (int i=1; i<=m; i++){
        for (int j=i; j>=1; j--){
            printf("%d", j);
        }
        for (int j=0; j<(m-i+1)*2; j++){
            printf("*");
        }
        for (int j=1; j<=i; j++){
            printf("%d", j);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n<1 || n>2) printf("error");
    else if (m<2 || m>9) printf("error");
    else if (n == 1) drawgraph1(m);
    else if (n == 2) drawgraph2(m);
    return 0;
}