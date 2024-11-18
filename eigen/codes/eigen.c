#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000
#define TOLERANCE 1e-6

// Function to allocate and free matrices
double** allocateMatrix(int n) {
    double** matrix = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(double));
    }
    return matrix;
}

void freeMatrix(double** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to copy a matrix
void copyMatrix(double** src, double** dest, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

// Hessenberg Reduction using Householder reflections
void hessenbergReduction(double** A, int n) {
    for (int k = 0; k < n - 2; k++) {
        double norm = 0.0;
        for (int i = k + 1; i < n; i++) {
            norm += A[i][k] * A[i][k];
        }
        norm = sqrt(norm);

        if (fabs(norm) < TOLERANCE) continue;

        double v[n];
        for (int i = 0; i < n; i++) v[i] = 0.0;
        v[k + 1] = A[k + 1][k] - norm;
        for (int i = k + 2; i < n; i++) {
            v[i] = A[i][k];
        }

        double v_norm = 0.0;
        for (int i = k + 1; i < n; i++) {
            v_norm += v[i] * v[i];
        }
        v_norm = sqrt(v_norm);
        if (v_norm < TOLERANCE) continue;
        for (int i = k + 1; i < n; i++) {
            v[i] /= v_norm;
        }

        for (int i = k; i < n; i++) {
            double sum = 0.0;
            for (int j = k + 1; j < n; j++) {
                sum += A[i][j] * v[j];
            }
            for (int j = k + 1; j < n; j++) {
                A[i][j] -= 2.0 * sum * v[j];
            }
        }
        for (int j = k; j < n; j++) {
            double sum = 0.0;
            for (int i = k + 1; i < n; i++) {
                sum += A[i][j] * v[i];
            }
            for (int i = k + 1; i < n; i++) {
                A[i][j] -= 2.0 * sum * v[i];
            }
        }
    }
}

// QR Decomposition using Gram-Schmidt process
void gramSchmidt(double** A, double** Q, double** R, int n) {
    for (int j = 0; j < n; j++) {
        R[j][j] = 0.0;
        for (int i = 0; i < n; i++) {
            R[j][j] += A[i][j] * A[i][j];
        }
        R[j][j] = sqrt(R[j][j]);

        for (int i = 0; i < n; i++) {
            Q[i][j] = A[i][j] / R[j][j];
        }

        for (int k = j + 1; k < n; k++) {
            R[j][k] = 0.0;
            for (int i = 0; i < n; i++) {
                R[j][k] += Q[i][j] * A[i][k];
            }
            for (int i = 0; i < n; i++) {
                A[i][k] -= R[j][k] * Q[i][j];
            }
        }
    }
}

// QR Algorithm for Eigenvalue Calculation
void qrAlgorithm(double** A, double* eigenvalues, int n) {
    double** Q = allocateMatrix(n);
    double** R = allocateMatrix(n);
    double** AQ = allocateMatrix(n);

    for (int iter = 0; iter < MAX_ITER; iter++) {
        gramSchmidt(A, Q, R, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AQ[i][j] = 0.0;
                for (int k = 0; k < n; k++) {
                    AQ[i][j] += R[i][k] * Q[k][j];
                }
            }
        }
        copyMatrix(AQ, A, n);

        int converged = 1;
        for (int i = 1; i < n; i++) {
            if (fabs(A[i][i - 1]) > TOLERANCE) {
                converged = 0;
                break;
            }
        }
        if (converged) break;
    }

    for (int i = 0; i < n; i++) {
        eigenvalues[i] = A[i][i];
    }

    freeMatrix(Q, n);
    freeMatrix(R, n);
    freeMatrix(AQ, n);
}

int main() {
    int n;
    printf("Enter the size of the matrix (n): ");
    scanf("%d", &n);

    double** A = allocateMatrix(n);
    double* eigenvalues = malloc(n * sizeof(double));

    printf("Enter the matrix elements row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    hessenbergReduction(A, n);
    qrAlgorithm(A, eigenvalues, n);

    printf("Eigenvalues: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", eigenvalues[i]);
    }
    printf("\n");

    freeMatrix(A, n);
    free(eigenvalues);

    return 0;
}

