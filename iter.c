#include <memory.h>
#include "utils.c"


int rel_up(int n, double a[n][n], double b[n], double x[n], double w, double e) {
    double a1[n][n];
    double b1[n];
    double x0[n];
    copy_m(n, a, a1);
    copy_b(n, b, b1);
    memset(x0, 0, n*sizeof(*x0));
    memset(x, 0, n*sizeof(*x));
    double sub;
    int count = 0;
    do {
        count++;
        sub = 0;
        copy_b(n, x, x0);
        memset(x, 0, n*sizeof(*x));
        for (int i = 0; i < n; i++) {
            x[i] = b[i] - (w - 1)/w*x0[i]*a[i][i];
            for (int j = i + 1; j < n; j++) {
                x[i] -= a[i][j]*x0[j];
            }
            for (int j = 0; j < i; j++) {
                x[i] -= a[i][j]*x[j];
            }
            x[i] /= a[i][i]/w;
        }
        for (int i = 0; i < n; i++) {
            x0[i] = 0;
            for (int j = 0; j < n; j++) {
                x0[i] += a[i][j]*x[j];
            }
            x0[i] -= b[i];
            sub += x0[i]*x0[i];
        }
    } while (sub > e*e);
    return count;
}