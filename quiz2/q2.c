#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 128

int int_cmp(const void* a, const void* b)
{
    int int_a = *((int*) a);
    int int_b = *((int*) b);
    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int float_cmp(const void* a, const void* b)
{
    float float_a = *((float*) a);
    float float_b = *((float*) b);
    if (float_a == float_b) return 0;
    else if (float_a < float_b) return -1;
    else return 1;
}

int double_cmp(const void* a, const void* b)
{
    double double_a = *((double*) a);
    double double_b = *((double*) b);
    if (double_a == double_b) return 0;
    else if (double_a < double_b) return -1;
    else return 1;
}

int main(int argc, char* argv[])
{
    int n;
    int type;
    typedef int array_type;
    int int_arr[MAX_SIZE];
    float float_arr[MAX_SIZE];
    double double_arr[MAX_SIZE];
    printf("Please enter the size of the array:\n");
    scanf("%d", &n);
    printf("Please enter the data type: (0 for integer, 1 for float, 2 for double):\n");
    scanf("%d", &type);
    if (type == 0) {
        printf("Please enter your numbers one by one (Press enter after each one):\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &int_arr[i]);
        }

        qsort(int_arr, n, sizeof(int), int_cmp);
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d\n", int_arr[i]);
        }
    } else if (type == 1) {
        printf("Please enter your numbers one by one (Press enter after each one):\n");
        for (int i = 0; i < n; i++) {
            scanf("%f", &float_arr[i]);
        }

        qsort(float_arr, n, sizeof(float), float_cmp);
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%f\n", float_arr[i]);
        }
    } else if (type == 2) {
        printf("Please enter your numbers one by one (Press enter after each one):\n");
        for (int i = 0; i < n; i++) {
            scanf("%lf", &double_arr[i]);
        }

        qsort(double_arr, n, sizeof(double), double_cmp);
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%lf\n", double_arr[i]);
        }
    }

    
}