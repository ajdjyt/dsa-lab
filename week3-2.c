// Implement matrix multiplication using DMA
#include <stdio.h>
#include <stdlib.h>

void main() {
    // Declare Matrices and variables
    int **a, **b, **o;
    int r1, c1, r2, c2, i, j, k;

    //Input the sizes
    printf("Enter r1 c1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter r2 c2: ");
    scanf("%d %d", &r2, &c2);

    //Verify if MM is possible
    if (c1 != r2) {
        printf("Not possible\n");
        exit(0);
    }

    //Dynamically allocate memory for matrices a, b, and o
    a = (int **)malloc(r1 * sizeof(int *));
    b = (int **)malloc(r2 * sizeof(int *));
    o = (int **)malloc(r1 * sizeof(int *));

    //Allocate Memory for each row of a,b and o
        //For a and o
    for (i = 0; i < r1; i++) {
        a[i] = (int *)malloc(c1 * sizeof(int));
        o[i] = (int *)calloc(c2, sizeof(int));
    }
        //For b
    for (i = 0; i < r2; i++) {
        b[i] = (int *)malloc(c2 * sizeof(int));
    }

    //Input matrices
    printf("Enter matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    //Perform MM
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                o[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    //Print Result
    printf("Resultant matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", o[i][j]);
        }
        printf("\n");
    }

    //Free mem allocated via DMA
    free(a);
    free(b);
    free(o);
}