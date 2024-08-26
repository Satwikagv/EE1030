#include <stdio.h>

int main() {
    // Points A, B, C, and D
    int A[2] = {6, 1};
    int B[2] = {8, 2};
    int C[2] = {9, 4};
    int D[2] = {7, 3};  // We calculated p = 7

    // Open a file to write the points
    FILE *file = fopen("points.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write points to the file
    fprintf(file, "A(%d, %d)\n", A[0], A[1]);
    fprintf(file, "B(%d, %d)\n", B[0], B[1]);
    fprintf(file, "C(%d, %d)\n", C[0], C[1]);
    fprintf(file, "D(%d, %d)\n", D[0], D[1]);

    // Close the file
    fclose(file);

    printf("Points have been written to points.txt\n");
    return 0;
}

