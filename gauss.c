#include <stdio.h>
#include <math.h>

#include "utils.c"

void swap_lines(int n, double a[n][n], double b[n], int line1, int line2)
{
    double tmp;
    if (b != NULL) {
        tmp = b[line1];
        b[line1] = b[line2];
        b[line2] = tmp;
    }
    for (int i = 0; i < n; i++) {
        tmp = a[line1][i];
        a[line1][i] = a[line2][i];
        a[line2][i] = tmp;
    }
}

void swap_columns(int n, double a[n][n], int col1, int col2)
{
    double tmp;
    for (int i = 0; i < n; i++) {
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
}

void sub_lines(int n, double m[n][n], double b[n], int line1, int line2, double k)
{
    if (b != NULL) {
        b[line1] -= b[line2] * k;
    }
    for (int i = 0; i < n; i++) {

        m[line1][i] -= m[line2][i] * k;
    }
}

void div_line(int n, double m[n][n], int line, double k)
{
    for (int i = 0; i < n; i++) {
        m[line][i] /= k;
    }
}


void triangular_upper(int n, double a[n][n], double b[n], double c[n][n])
{
    for (int i = 0; i < n; i++) {
        int line = i;
        while (line < n && a[line][i] == 0) {
            line++;
        }
        if (line != i) {
            swap_lines(n, a, b, i, line);
            if (c != NULL) {
                swap_lines(n, c, NULL, i, line);
            }
        }
        for (int j = i + 1; j < n; j++) {

            if (a[j][i] != 0) {
                double k = a[j][i] / a[i][i];
                sub_lines(n, a, b, j, i, k);
                a[j][i] = 0;
                if (c != NULL) {
                    sub_lines(n, c, NULL, j, i, k);
                }
            }
        }
    }
}

void triangular_lower(int n, double a[n][n], double b[n], double c[n][n])
{
    for (int i = n - 1; i >= 0; i--) {
        int line = i;
        while (line >= 0 && a[line][i] == 0) {
            line--;
        }
        if (line != i) {
            swap_lines(n, a, b, i, line);
            if (c != NULL) {
                swap_lines(n, c, NULL, i, line);
            }
        }
        for (int j = i - 1; j >= 0; j--) {

            if (a[j][i] != 0) {
                double k = a[j][i] / a[i][i];
                sub_lines(n, a, b, j, i, k);
                a[j][i] = 0;
                if (c != NULL) {
                    sub_lines(n, c, NULL, j, i, k);
                }
            }
        }
    }
}

void gauss(int n, double a[n][n], double b[n], double x[n])
{
    double a1[n][n];
    double b1[n];
    copy_m(n, a, a1);
    copy_b(n, b, b1);
    triangular_upper(n, a1, b1, NULL);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b1[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= x[j] * a1[i][j];
        }
        x[i] /= a1[i][i];
    }
}

void gauss_choice(int n, double a[n][n], double b[n], double x[n])
{
    double a1[n][n];
    double b1[n];
    copy_m(n, a, a1);
    copy_b(n, b, b1);
    int x1[n];
    for (int i = 0; i < n; i++) {
        x1[i] = i;
    }
    for (int i = 0; i < n; i++) {
        double max = 0;
        int ind1 = i;
        int ind2 = i;
        for (int k = i; k < n; k++) {
            for (int l = i; l < n; l++) {
                if (fabs(a1[k][l]) > max) {
                    max = fabs(a1[k][l]);
                    ind1 = k;
                    ind2 = l;
                }
            }
        }
        if (ind1 != i) {
            swap_lines(n, a1, b1, i, ind1);
        }
        swap_columns(n, a1, i, ind2);
        int tmp = x1[i];
        x1[i] = x1[ind2];
        x1[ind2] = tmp;
        for (int j = i + 1; j < n; j++) {
            if (a1[j][i] != 0) {
                double k = a1[j][i] / a1[i][i];
                sub_lines(n, a1, b1, j, i, k);
                a1[j][i] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        x[x1[i]] = b1[i];
        for (int j = i + 1; j < n; j++) {
            x[x1[i]] -= x[x1[j]] * a1[i][j];
        }
        x[x1[i]] /= a1[i][i];
    }
}


double det(int n, double m[n][n])
{
    double m1[n][n];
    copy_m(n, m, m1);
    triangular_upper(n, m1, NULL, NULL);
    double d = 1;
    for (int i = 0; i < n; i++) {
        d *= m1[i][i];
    }
    return d;
}

void inverse(int n, double m[n][n], double inv[n][n])
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inv[i][j] = i == j;
        }
    }
    double m1[n][n];
    copy_m(n, m, m1);
    triangular_upper(n, m1, NULL, inv);
    triangular_lower(n, m1, NULL, inv);
    for (int i = 0; i < n; i++) {
        div_line(n, inv, i, m1[i][i]);
    }

}

double norm(int n, double m[n][n])
{
    double max = 0;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += fabs(m[i][j]);
        }
        if (sum > max) {
            max = sum;
        }
    }
    return max;
}

double condition(int n, double m[n][n])
{
    double inv[n][n];
    inverse(n, m, inv);
    return norm(n, m) * norm(n, inv);
}
