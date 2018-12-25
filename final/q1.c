#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MATRIX_SIZE 7
#define MAX_SIZE 250

unsigned int matrix[MATRIX_SIZE][MATRIX_SIZE];

void init_matrix();
void print_matrix();
void vertical_sort();
void horizontal_sort();
void swap(unsigned int*, unsigned int*);

int main(int argc, char* argv[])
{
    init_matrix();
    printf("Random matrix:\n");
    while (1) {
        print_matrix();
        printf("==================================\n");
        printf("=========== MENU =================\n");
        printf("==================================\n");
        char c;
        printf("[1] Vertical sorting\n");
        printf("[2] Horizontal sorting\n");
        printf("[q] Exit\n");
        printf("Your choice: ");
        scanf(" %c", &c); /* The space before %c is actually required 
                           * for some weird reason... */
        switch (c) {
            case '1':
                vertical_sort();
                break;
            case '2':
                horizontal_sort();
                break;
            case 'q':
                exit(EXIT_SUCCESS);
        }
        printf("==================================\n");
    }
    return 0;
}

void swap(unsigned int *xp, unsigned int *yp)
{
    *xp ^= *yp;
    *yp ^= *xp;
    *xp ^= *yp;
}

void vertical_sort()
{
    unsigned int i, j, k;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE - 1; j++) {
            for (k = 0; k < MATRIX_SIZE - j - 1; k++) {
                if (matrix[k][i] > matrix[k+1][i]) {
                    swap(&(matrix[k][i]), &(matrix[k+1][i]));
                }
            }
        }
    }
}

void horizontal_sort()
{
    unsigned int i, j, k;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE - 1; j++) {
            for (k = 0; k < MATRIX_SIZE - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k+1]) {
                    swap(&(matrix[i][k]), &(matrix[i][k+1]));
                }
            }
        }
    }
}

void print_matrix()
{
    unsigned int i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%03u  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void init_matrix()
{
    srand(time(NULL));
    unsigned int i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = (rand() % MAX_SIZE) + 1;
        }
    }
}
