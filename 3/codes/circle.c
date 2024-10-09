#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "/home/g-v-satwika/matgeo/codes/msoft/libs/matfun.h"
#include "/home/g-v-satwika/matgeo/codes/msoft/libs/geofun.h"

// Solve quadratic equation ax^2 + bx + c = 0
/*void solveQuadratic(double a, double b, double c, double *root1, double *root2) {
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else {
        *root1 = *root2 = 0;  
}
}*/
int main() {
    double **P = createMat(1, 2); // Create a point vector for P
    P[0][0] = 7;  // x-coordinate of point P
    P[0][1] = 3;  // y-coordinate of point P

    double r = 5;  // Given radius
     // Final equation: 2k^2 - 22k + 40 = 0
     double **CM=createMat(3,1); //coefficient matrix
     CM[0][0]=2;  // Coefficient for k^2
     CM[1][0] = -22;   // Coefficient for k
     CM[2][0] = 56;  //constant term

    // Solve the quadratic equation to get two values of k
   double **K=createMat(2,1);
    K=Matquad(CM[0][0],CM[1][0],CM[2][0]);
    double k1=K[0][0];
    double k2=K[1][0];
    // Create two separate vectors for the two centers
    double **center1 = createMat(1, 2);
    double **center2 = createMat(1, 2);
    
    center1[0][0] = k1;  // Center 1: (k1, k1-1)
    center1[0][1] = k1-1;
    
    center2[0][0] = k2;  // Center 2: (k2, k2-1)
    center2[0][1] = k2-1;

    // Write the centers to a file
    FILE *file = fopen("circle.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }
    // Write the two centers to the file
    fprintf(file, "C1(%.2f, %.2f)\n", center1[0][0], center1[0][1]);
    fprintf(file, "C2(%.2f, %.2f)\n", center2[0][0], center2[0][1]);
    fprintf(file, "P(7.00,3.00)");
    fclose(file);
    // Free the allocated memory
    for (int i = 0; i < 1; i++) {
        free(center1[i]);
        free(center2[i]);
        free(P[i]);
    }
    free(center1);
    free(center2);
    free(P);

    return 0;
}

