#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    double x1, x2, D;

    scanf("%d%d%d", &a, &b, &c);
    D = b*b-4*a*c;
    
    if (D >= 0) {
        x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a);
        x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a);
        if (x1 == x2) {
            printf("%.1f", x1);
        }
        else {
            printf("%.1f\n%.1f", x1, x2);
        }
    }

    else {
        x1 = ((-1.0)*b)/(2*a);
        x2 = sqrt((-1.0)*D)/(2*a);
        if (x1 == -0.0) x1 = 0.0;
        if (x2 < 0) x2 = x2*(-1);
        printf("%.1f+%.1fi\n", x1, x2);
        printf("%.1f-%.1fi", x1, x2);
    }
}