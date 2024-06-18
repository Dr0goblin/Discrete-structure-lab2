#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform the join (union) operation on two matrices
void join(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] | B[i][j];
        }
    }
}

// Function to perform the meet (intersection) operation on two matrices
void meet(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] & B[i][j];
        }
    }
}

// Function to perform the Boolean product of two matrices
void booleanProduct(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] |= (A[i][k] & B[k][j]);
            }
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter elements of the first matrix (0 or 1):\n");
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Boolean product is not possible with these dimensions.\n");
        return -1;
    }

    printf("Enter elements of the second matrix (0 or 1):\n");
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("First Matrix:\n");
    printMatrix(A, rowsA, colsA);

    printf("Second Matrix:\n");
    printMatrix(B, rowsB, colsB);

    join(A, B, result, rowsA, colsA);
    printf("Join (Union) of matrices:\n");
    printMatrix(result, rowsA, colsA);

    meet(A, B, result, rowsA, colsA);
    printf("Meet (Intersection) of matrices:\n");
    printMatrix(result, rowsA, colsA);

    booleanProduct(A, B, result, rowsA, colsA, colsB);
    printf("Boolean Product of matrices:\n");
    printMatrix(result, rowsA, colsB);

    return 0;
}
