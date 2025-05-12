#include <stdio.h>
#include <math.h>

double function1(double a, double x) { return sqrt(a - x * x); }
double function2(double a, double x) { return (a * pow(x, 3) + 7 * x) / (sqrt(a + x));}

void integral(double (*func)(double, double), double a, double p, double q, double err) {
    int n = 2;
    double sum = 0.0, h = (q - p) * 1.0 / n;
    double t, t_after, error;
    for (int i = 1; i < n; i++) sum += (*func)(a, p + i * h);
    t = (q - p) * 1.0 / 4 * ((*func)(a, p) + (*func)(a, q) + 2 * sum);
    do {
        n *= 2;
        h = (q - p) / n;
        sum = 0;
        t_after = (*func)(a, p) + (*func)(a, q);
        for (int i = 1; i < n; i++) t_after += 2.0 * (*func)(a, p + i * h);
        t_after = t_after * (((q - p) * 1.0 / n) / 2);
        error = fabs(t_after - t);
        // printf("%.12f, %.12f\n", t, t_after);
        t = t_after;
    } while (error > pow(10, -err));
    printf("%.12f\n", t_after);
}

int main() {
    while (1) {
        int type, err;
        double a, p, q;
        scanf("%d", &type);
        if (type == 0) break;
        else if (type != 1 && type != 2) {
            printf("Invalid\n");
            continue;
        }
        scanf("%lf %lf %lf %d", &a, &p, &q, &err);
        if (type == 1) integral(function1, a, p, q, err);
        else if (type == 2) integral(function2, a, p, q, err);
    }
    return 0;
}