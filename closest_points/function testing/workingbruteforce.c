#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float bruteforce(int size, int mat[][2]);
int *xptr1, *yptr1, *xptr2, *yptr2;
float distance(int x1, int y1, int x2, int y2);
float min(float a, float b);
int main() {
    int n = 10;
    int x1, y1, x2, y2; //x and y that are the min distanced point candidates
    double dmin;
    float temp;
    xptr1 = &x1;
    yptr1 = &y1;
    xptr2 = &x2;
    yptr2 = &y2;
    int mat[10][2] = {
        {4, 8},
        {6, 7},
        {7, 14},
        {12, 11},
        {13, 10},
        {20, 24},
        {24, 16},
        {26, 29},
        {40, 35}};

    dmin = bruteforce(3, mat);
    printf("closest points are: (%d, %d) and (%d, %d) + the smallest distance is -> %f", x1, y1, x2, y2, dmin);
    return 0;
}
float bruteforce(int size, int mat[][2]) {
    int i = 0;
    int j = 0;
    int k = 0;
    float dist = FLT_MAX;
    for (i = 0; i < size; i++) {
        for (j = (i + 1); j < size; j++) {
            if (dist != min(dist, distance(mat[i][0], mat[i][1], mat[j][0], mat[j][1]))) {
                *xptr1 = mat[i][0];
                *yptr1 = mat[i][1];
                *xptr2 = mat[j][0];
                *yptr2 = mat[j][1];
                dist = distance(mat[i][0], mat[i][1], mat[j][0], mat[j][1]);
            }
        }
    }
    return dist;
}
float distance(int x1, int y1, int x2, int y2) {
    return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}
float min(float a, float b) {
    if (a < b)
        return a;
    else
        return b;
}
