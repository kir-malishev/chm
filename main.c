#include "gauss.c"
#include "iter.c"

double a1[4][4] = {
        {3, -2, 2, -2},
        {2, -1, 2, 0},
        {2, 1, 4, 8},
        {1, 3, -6, 2}
};

double b1[] = {8, 4, -1, 3};


double a2[4][4] = {
        {2, 3, 1, 2},
        {4, 3, 1, 1},
        {1, -7, -1, -2},
        {2, 5, 1, 1}
};

double b2[] = {4, 5, 7, 1};

double a3[4][4] = {
        {1, -1, 1, -1},
        {4, -1, 0, -1},
        {3, 1, -2, 1},
        {5, 1, 0, -4}
};

double b3[] = {0, 0, 1, 0};


double mat[3][3] = {
        {1, 0, 0},
        {0, 4, 0},
        {0, 0, 2}

};


enum
{
    n = 50,
    m = 15
};

void get_test(double a[n][n], double b[n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                a[i][j] = n + m*m + (double) j/m + (double) i/n;
            } else {
                a[i][j] = (double) (i + j)/ (n + m);
            }
        }
        b[i] = m*n - i*i*i;
    }
}


int main(void)
{
    printf("");
    printf("\n");
    printf("\n");
    double a[n][n];
    double b[n];
    double x[n];
    get_test(a, b);
    print_m(n, a, b);
//    gauss(n, a, b, x);
//    printf("\n");
//    print_x(n, x);
//    printf("\n");
//    printf("\n");
//    printf("\n");
//    printf("\n");
//    gauss_choice(n, a, b, x);
//    printf("\n");
//    print_x(n, x);
    printf("\n");
    printf("\n");
    for (double w = 0.1; w <= 1.91; w += 0.1) {
        int count = rel_up(n, a, b, x, w, 1e-6);
        printf("%lf;%d\n", w, count);
    }
    int count = rel_up(n, a, b, x, 0.7, 1e-6);
    printf("\n\n%d\n\n", count);
    print_x(n, x);
//    double x[4];
//    print_m(4, a2, b2);
//    printf("\n\n");
//    gauss(4, a2, b2, x);
//    print_x(4, x);
//    printf("\n\n");
//    double inv1[4][4];
//    inverse(4, a2, inv1);
//    print_a(4, inv1);
//    printf("\n\n%lf\n\n%lf", det(4, a2), condition(4, a2));
    return 0;
}