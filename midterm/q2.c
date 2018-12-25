#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float sum(float *arr, int n)
{
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

float sum_xy(float *x, float *y, int n)
{
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += x[i] * y[i];
    }
    return total;
}

int main(int argc, char* argv[])
{
    float x1[10] = { 18.22, 9.55, 5.82, 4.53, 3.8, 3.14, 2.65, 2.22, 2.11, 1.94 };
    float y1[10] = { 12, 15, 18, 20, 22, 24, 27, 30, 31, 32 };
    float x2[10] = { 5, 8.5, 11, 13.5, 17, 19.5, 23, 26, 27.5, 30 };
    float y2[10] = { 40, 62, 79, 94, 115, 130, 151, 166, 179, 194 };

    // Linear regression: y = ax + b where
    // b = avg(y) - a * avg(x);
    // a = (sum(x*y) - n * avg(x)*avg(y)) / (sum(x^2) - n * avg(x)^2);

    int n1 = sizeof(x1) / sizeof(x1[0]);
    int n2 = sizeof(x2) / sizeof(x2[0]);


    float avg_x1 = sum(x1, n1) / n1;
    float avg_y1 = sum(y1, n1) / n1;
    float avg_x2 = sum(x2, n2) / n2;
    float avg_y2 = sum(y2, n2) / n2;
    float sum_xy1 = sum_xy(x1, y1, n1);
    float sum_xy2 = sum_xy(x2, y2, n2);
    float sum_xx1 = sum_xy(x1, x1, n1);
    float sum_xx2 = sum_xy(x2, x2, n2);

    float a1 = (sum_xy1 - n1 * avg_x1 * avg_y1) / (sum_xx1 - n1 * avg_x1 * avg_x1);
    float b1 = avg_y1 - a1 * avg_x1;
    float a2 = (sum_xy2 - n2 * avg_x2 * avg_y2) / (sum_xx2 - n2 * avg_x2 * avg_x2);
    float b2 = avg_y2 - a2 * avg_x2;

    printf("L1: y = %.3f * x + %.3f\n", a1, b1);
    printf("L2: y = %.3f * x + %.3f\n", a2, b2);

    float intersection_x = (b2 - b1) / (a1 - a2);
    float intersection_y = (a1 * b2 - a2 * b1) / (a1 - a2);

    printf("Intersection point: P(%.3f, %.3f)\n", intersection_x, intersection_y);
    
    return 0;
}
