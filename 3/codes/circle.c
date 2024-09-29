#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Matrix creation function
double **createMat(int m, int n) {
    int i;
    double **a;
    a = (double **)malloc(m * sizeof(*a));
    for (i = 0; i < m; i++)
        a[i] = (double *)malloc(n * sizeof(*a[i]));
    return a;
}

// Matrix transpose function
double **transposeMat(double **a, int m, int n) {
    int i, j;
    double **c = createMat(n, m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i][j] = a[j][i];
        }
    }
    return c;
}

// Matrix multiplication function
double **Matmul(double **a, double **b, int m, int n, int p) {
    int i, j, k;
    double **c = createMat(m, p);
    double temp = 0;
    for (i = 0; i < m; i++) {
        for (k = 0; k < p; k++) {
            for (j = 0; j < n; j++) {
                temp = temp + a[i][j] * b[j][k];
            }
            c[i][k] = temp;
            temp = 0;
        }
    }
    return c;
}

// Dot product (inner product) of two matrices
double Matdot(double **a, double **b, int m) {
    double **temp = Matmul(transposeMat(a, m, 1), b, 1, m, 1);
    return temp[0][0];
}

// Norm of a matrix (vector)
double Matnorm(double **a, int m) {
    return sqrt(Matdot(a, a, m));
}

// Function to compute the centers of the circle
void computeCircleCenters(double p[2], double r, FILE *file) {
    // Compute values of k
    double k1, k2, discriminant;
    
    // f = ||u||^2 - r^2, where u = (-k, 1-k)
    // Using the formula ||P||^2 + 2u⊤P + f = 0 to find k1, k2
    // Assume point P = (7, 3)
    double **P = createMat(2, 1);
    P[0][0] = p[0];
    P[1][0] = p[1];
    
    // Solve for k1 and k2
    discriminant = sqrt(1 + 4 * (p[0] - p[1]) * (p[0] - p[1]));  // sqrt term in the equation for k1, k2
    k1 = (p[0] + p[1] - discriminant) / 2;
    k2 = (p[0] + p[1] + discriminant) / 2;
    
    // First center (-k1, 1-k1)
    double center1[2] = {-k1, 1 - k1};
    
    // Second center (-k2, 1-k2)
    double center2[2] = {-k2, 1 - k2};
    
    // Write the centers to a file
    fprintf(file, "Center 1: (%.2f, %.2f)\n", center1[0], center1[1]);
    fprintf(file, "Center 2: (%.2f, %.2f)\n", center2[0], center2[1]);
}

int main() {
    double p[2] = {7, 3};  // Point P (7,3)
    double r = 5;          // Radius of the circle
    
    // Open file for writing the centers
    FILE *file = fopen("circle.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Compute and write the centers to the file
    computeCircleCenters(p, r, file);
    
    // Close the file
    fclose(file);   
    return 0;
}

