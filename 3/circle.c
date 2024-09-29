#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function declarations
double **createMat(int m, int n);
double Matdot(double **a, double **b, int m);
double Matnorm(double **a, int m);
double **transposeMat(double **a, int m, int n);
double **Matmul(double **a, double **b, int m, int n, int p);

// Function to create an m x n matrix
double **createMat(int m, int n) {
    double **a = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    return a;
}

// Inner product of two matrices
double Matdot(double **a, double **b, int m) {
    double **temp = Matmul(transposeMat(a, m, 1), b, 1, m, 1);
    return temp[0][0];
}

// Norm of a vector
double Matnorm(double **a, int m) {
    return sqrt(Matdot(a, a, m));
}

// Matrix multiplication
double **Matmul(double **a, double **b, int m, int n, int p) {
    double **c = createMat(m, p);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < p; k++) {
            double temp = 0;
            for (int j = 0; j < n; j++) {
                temp += a[i][j] * b[j][k];
            }
            c[i][k] = temp;
        }
    }
    return c;
}

// Transpose of a matrix
double **transposeMat(double **a, int m, int n) {
    double **c = createMat(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = a[j][i];
        }
    }
    return c;
}

int main() {
    double r = 3.0; // Radius of the circle
    double p[2] = {7, 3}; // Point on the circle P(7, 3)

    // Create matrix for point P
    double **P = createMat(2, 1);
    P[0][0] = p[0];
    P[1][0] = p[1];

    // Variables for the circle equation
    double **u = createMat(2, 1);

    // Compute ||P||^2
    double norm_P2 = Matnorm(P, 2);

    // Solving for two values of k
    double k1, k2;
    double f1, f2;

    // Solve for two possible values of k using the quadratic equation
    double A = 2.0;
    double B = -2.0 * (p[1] - p[0]);
    double C = norm_P2 - r * r;

    double discriminant = sqrt(B * B - 4 * A * C);

    k1 = (-B + discriminant) / (2 * A);
    k2 = (-B - discriminant) / (2 * A);

    // Calculate two values of f
    f1 = k1 * k1 + (1 - k1) * (1 - k1) - r * r;
    f2 = k2 * k2 + (1 - k2) * (1 - k2) - r * r;

    // Compute centers using u = (-k, 1-k)
    // First center for k1
    u[0][0] = -k1;
    u[1][0] = k1 - 1;

    // Print first center
    printf("First center: (%.2lf, %.2lf)\n", u[0][0], u[1][0]);
     FILE *file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "c1(%.2lf, %.2lf)\n", u[0][0], u[1][0]);
    u[0][0] = -k2;
    u[1][0] = k2 - 1;

    // Print second center
    printf("Second center: (%.2lf, %.2lf)\n", u[0][0], u[1][0]);
    fprintf(file, "c2(%.2lf, %.2lf)\n", u[0][0], u[1][0]);
    fprintf(file, "p(%.2lf, %.2lf)\n",p[0], p[1]);
    fclose(file);
    return 0;
}

