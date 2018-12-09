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
    gauss(n, a, b, x);
    //print_m(n, a, b);
    printf("\n");
    print_x(n, x);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    gauss_choice(n, a, b, x);
    //print_m(n, a, b);
    printf("\n");
    print_x(n, x);
    printf("\n");
    printf("\n");
    int count = rel_up(n, a, b, x, 1.5, 1e-6);
    printf("\n\n%d\n\n", count);
    print_x(n, x);
    return 0;
}