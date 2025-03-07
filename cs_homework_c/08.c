#include <stdio.h>
#include <math.h>

void comparetriangle(int a, int b, int c) {
    int triangle[3] = {a, b, c};
    for (int i=0; i<3; i++) {
        for (int j=0; j<i; j++) {
            if (triangle[j] > triangle[i]) {
                int temp = triangle[j];
                triangle[j] = triangle[i];
                triangle[i] = temp;
            }
        }
    }
    if (triangle[0] + triangle[1] <= triangle[2] || triangle[0] <= 0) {
        printf("Not Triangle\n");
    }
    else {
        int a = triangle[0] * triangle[0];
        int b = triangle[1] * triangle[1];
        int c = triangle[2] * triangle[2];
        if (triangle[0] == triangle[1] && triangle[1] == triangle[2]) {
            printf("Equilateral Triangle\n");
        }

        if (triangle[0] == triangle[1] || triangle[1] == triangle[2]) {
            printf("Isosceles Triangle\n");
        }
        if (a + b == c) {
            printf("Right Triangle\n");
        }
        else if (a + b < c) {
            printf("Obtuse Triangle\n");
        }
        else if (a + b > c) {
            printf("Acute Triangle\n");
        }
    }
}

int main() {
    int n, a, b, c;
    int triangle[99][3];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        triangle[i][0] = a;
        triangle[i][1] = b;
        triangle[i][2] = c;
    }
    for (int i=0; i<n; i++) {
        comparetriangle(triangle[i][0], triangle[i][1], triangle[i][2]);
        if (i != n-1) {
            for (int j=0; j<n; j++) {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}