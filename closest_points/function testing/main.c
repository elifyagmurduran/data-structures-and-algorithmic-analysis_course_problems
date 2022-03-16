#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *xptr1, *yptr1, *xptr2, *yptr2;
void merge(int mat[][2], int l, int m, int r);
void mergesortbyx(int mat[][2], int l, int r);
int main() {
    int i, j, k;
    int n;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0; //x and y that are the min distanced point candidates
    float temp;
    double dmin;
    xptr1 = &x1;
    yptr1 = &y1;
    xptr2 = &x2;
    yptr2 = &y2;
    char selection = 'y';
    FILE *fptr;
    char str[50] = "sample.txt";
    int mat[n][2];
    fptr = fopen(str, "r");

    for (i = 0; i < n; i++) {
        for (j = 0; j < 2; j++) {
            int a;
            fscanf(fptr, "%d", &a);
            mat[i][j] = a;
        }
    }
    printf("matrix is loaded.\n");
    for (i = 0; i < n; i++) {
        printf("%d %d\n", mat[i][0], mat[i][1]);
    }
    printf("sorting the matrix...\n");
    //merge sort here
    // mergesortbyx(mat, 0, n - 1);
    printf("sorted matrix:\n");
    for (i = 0; i < n; i++) {
        printf("%d %d\n", mat[i][0], mat[i][1]);
    }
    printf("now calculating closest points...\n");
    //program here
    //
    //
    //
    printf("closest points are: (%d, %d) and (%d, %d) + the smallest distance is -> %f", x1, y1, x2, y2, dmin);
    fclose(fptr);
    return 0;
}
void merge(int mat[][2], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1][2], R[n2][2];

    for (i = 0; i < n1; i++) {
        L[i][0] = mat[l + i][0];
        L[i][1] = mat[l + i][1];
    }

    for (j = 0; j < n2; j++) {
        R[j][0] = mat[m + 1 + j][0];
        R[j][1] = mat[m + 1 + j][1];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i][0] <= R[j][0]) {
            mat[k][0] = L[i][0];
            mat[k][1] = L[i][1];
            i++;
        } else {
            mat[k][0] = R[j][0];
            mat[k][1] = R[j][1];
            j++;
        }
        k++;
    }

    while (i < n1) {
        mat[k][0] = L[i][0];
        mat[k][1] = L[i][1];
        i++;
        k++;
    }

    while (j < n2) {
        mat[k][0] = R[j][0];
        mat[k][1] = R[j][1];
        j++;
        k++;
    }
}
void mergesortbyx(int mat[][2], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        //
        mergesortbyx(mat, l, m);
        mergesortbyx(mat, m + 1, r);
        //
        merge(mat, l, m, r);
    }
}
