#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    int arr1[7] = {10, 4, 0, 5, 7, 14, 6};
    int arr2[7] = {6, 3, 4, -6, 1, -2, 8};
    int n;
    printf("Please enter a number:\n");
    scanf("%d", &n);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++ ){
            if (arr1[i] + arr2[j] == n) {
                printf("(%d, %d)\n", arr1[i], arr2[j]);
            }
        }
    }
}