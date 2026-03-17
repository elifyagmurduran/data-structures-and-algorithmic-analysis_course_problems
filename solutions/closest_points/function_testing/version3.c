#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float distance(int x1, int y1, int x2, int y2);
float min(float a, float b);
float bruteforce(int size, int mat[][2]);
float closestfunction(int n, int mat[][2]);
float stripcalc(int n, int mat[][2], float d);

int *xptr1, *yptr1, *xptr2, *yptr2;
double *dminptr;

int main() {
    int n = 10;

    float temp = 0;
    double dmin = 0;
    dminptr = &dmin;
    int x1, y1, x2, y2; //x and y that are the min distanced point candidates
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
    temp = closestfunction(10, mat);
    dmin = temp;
    // dmin = sqrt(temp); //this extra step is to solve the issue sqrt func raised
    printf("closest points are: (%d, %d) and (%d, %d) + the smallest distance is -> %f", x1, y1, x2, y2, dmin);
    return 0;
}

float distance(int x1, int y1, int x2, int y2) {
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
float min(float a, float b) {
    if (a < b)
        return a;
    else
        return b;
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
float stripcalc(int n, int mat[][2], float d) {
    int *tempx1, *tempx2, *tempy1, *tempy2;
    tempx1 = xptr1;
    tempy1 = yptr1;
    tempx2 = xptr2;
    tempy2 = yptr1;

    int *matstrip[2];
    matstrip[2] = (int *)calloc(n, sizeof(int));
    float stripmin = d;
    int i = 0;
    int j = 0;
    int k = 0;
    int mid = n / 2;
    for (i = 0; i < n; i++) {
        if (abs(mat[i][0] - mid) < d) {
            matstrip[j][0] = mat[i][0];
            matstrip[j][1] = mat[i][1];
            j++;
        }
    }

    stripmin = bruteforce(j, matstrip);
    if (d != stripmin) {
        xptr1 = tempx1;
        yptr1 = tempy1;
        xptr2 = tempx2;
        yptr1 = tempy2;
    }
    return stripmin;
}
float closestfunction(int n, int mat[][2]) {
    float d;
    float dl, dr, stripd;

    if (n <= 3) {
        d = bruteforce(n, mat);
    } else {
        int mid = n / 2; //mid is the row number

        dl = closestfunction(mid, mat);
        dr = closestfunction((n - mid), mat + mid);

        d = min(dl, dr);
        stripd = stripcalc(n, mat, d);
        *dminptr = min(d, stripd);
    }
    return d;
}
