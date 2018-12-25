#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int main(int argc, char* argv[])
{
    int upper_bound;
    printf("Please enter upper bound for matrix elements:\n");
    scanf("%d", &upper_bound);
    int matrix[SIZE][SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % upper_bound;
        }
    }
    int largest = 0;
    int largest_i = 0, largest_j = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            int determinant = matrix[i][j] * matrix[i+1][j+1] - matrix[i][j+1] * matrix[i+1][j]; // det({{a, b},{c, d}}) = ad - bc
            if (determinant > largest) {
                largest = determinant;
                largest_i = i;
                largest_j = j;
            }
        }
    }

    printf("-----------------\n");
    printf("The largest determinant: %d\n", largest);
    printf("Found on row %d column %d\n", largest_i, largest_j);
    printf("-----------------\n");
    printf("Matrix\n");
    printf("%d  %d\n", matrix[largest_i][largest_j], matrix[largest_i][largest_j + 1]);
    printf("%d  %d\n", matrix[largest_i + 1][largest_j], matrix[largest_i + 1][largest_j + 1]);
    printf("-----------------\n");
    printf("Big Matrix\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
