#pragma once


#include <stdio.h>


void copy_m(int n, const double m1[n][n], double m2[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m2[i][j] = m1[i][j];
        }
    }
}

void copy_b(int n, const double b1[n], double b2[n]) {
    for (int i = 0; i  < n; i++) {
        b2[i] = b1[i];
    }
}

void print_a(int n, double m[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf & ", m[i][j]);
        }
        printf("\n");
    }
}


void print_x(int n, double x[n]) {
    for (int i = 0; i < n; i++) {
        printf("%0.6lf ", x[i]);
    }
}



void print_m(int n, double m[n][n], double b[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf & ", m[i][j]);
        }
        printf("%lf\n", b[i]);
    }
}

