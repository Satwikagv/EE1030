#include <stdio.h>
#include <stdlib.h>
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}

double **Matadd(double **a,double **b, int m, int n){
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]+b[i][j];
  }
 }
return c;
}

double **Matsub(double **a, double **b, int m, int n) {
    int i, j;
    double **c;
    c = createMat(m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];  // Subtraction instead of addition
        }
    }
    return c;
}


int main() {
    // Create matrices for points A, B, C
    double **A = createMat(2, 1);
    double **B = createMat(2, 1);
    double **C = createMat(2, 1);

    // Initialize points A, B, C
    A[0][0] = 6; A[1][0] = 1;
    B[0][0] = 8; B[1][0] = 2;
    C[0][0] = 9; C[1][0] = 4;

    // Calculate D = C + A - B using Matsub and Matadd
    double **temp = Matsub(A, B, 2, 1);
    double **D = Matadd(C, temp, 2, 1);

    // Write points to a file
    FILE *file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "A(%lf, %lf)\n", A[0][0], A[1][0]);
    fprintf(file, "B(%lf, %lf)\n", B[0][0], B[1][0]);
    fprintf(file, "C(%lf, %lf)\n", C[0][0], C[1][0]);
    fprintf(file, "D(%lf, %lf)\n", D[0][0], D[1][0]);
    fclose(file);

    // Print D to the terminal
    printf("The coordinates of point D are: (%lf, %lf)\n", D[0][0], D[1][0]);

    return 0;
}


