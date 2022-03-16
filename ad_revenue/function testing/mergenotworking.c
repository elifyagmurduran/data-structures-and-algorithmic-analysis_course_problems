#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b);
void print(int n, int mat[6][5]);
void merge(int mat[][5], int l, int m, int r);
void mergeSort(int mat[][5], int l, int r);
void wrapperMerge(int mat[][5], int n);
/*
 j | StartTime | Duration | Value
 ---------------------------------
 1 |     5     |     3    |   3
 2 |     9     |     4    |   7
 3 |     1     |     6    |   9
 4 |     4     |     7    |   5
 5 |     1     |     3    |   2
 6 |     2     |     5    |   3

 */
int main() {
    int i, j, k;
    int n = 6;
    // index - start - duration - end - value
    int mat[6][5] = {
        {1, 5, 3, 0, 3},
        {2, 9, 4, 0, 7},
        {3, 1, 6, 0, 9},
        {4, 4, 7, 0, 5},
        {5, 1, 3, 0, 2},
        {6, 2, 5, 0, 3}};
    print(n, mat);
    printf("\n\nafter merge;\n");
    wrapperMerge(mat, n);
    print(n, mat);
    return 0;
}
int max(int a, int b) {
    if (a < b)
        return b;
    else
        return a;
}
void print(int n, int mat[6][5]) {
    int i;
    printf(" i | StartTime | Duration |  End Time | Value\n--------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        if (mat[i][3] < 10) {
            printf(" %d |     %d     |    %d     |    %d     |    %d     |\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
        } else {
            printf(" %d |     %d     |    %d     |    %d    |    %d     |\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3], mat[i][4]);
        }
    }
}

void merge(int mat[][5], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1][5], R[n2][5];
    //
    for (i = 0; i < n1; i++) {
        L[i][0] = mat[l + i][0];
        L[i][1] = mat[l + i][1];
        L[i][2] = mat[l + i][2];
        L[i][3] = mat[l + i][3];
        L[i][4] = mat[l + i][4];
    }

    for (j = 0; j < n2; j++) {
        R[j][0] = mat[m + 1 + j][0];
        R[j][1] = mat[m + 1 + j][1];
        R[j][2] = mat[m + 1 + j][2];
        R[j][3] = mat[m + 1 + j][3];
        R[j][4] = mat[m + 1 + j][4];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i][3] <= R[j][3]) {
            mat[k][0] = L[i][0];
            mat[k][1] = L[i][1];
            mat[k][2] = L[i][2];
            mat[k][3] = L[i][3];
            mat[k][4] = L[i][4];

            i++;
        } else {
            mat[k][0] = R[i][0];
            mat[k][1] = R[i][1];
            mat[k][2] = R[i][2];
            mat[k][3] = R[i][3];
            mat[k][4] = R[i][4];
            j++;
        }
        k++;
    }

    while (i < n1) {

        mat[k][0] = L[i][0];
        mat[k][1] = L[i][1];
        mat[k][2] = L[i][2];
        mat[k][3] = L[i][3];
        mat[k][4] = L[i][4];
        i++;
        k++;
    }
    while (j < n2) {
        mat[k][0] = R[i][0];
        mat[k][1] = R[i][1];
        mat[k][2] = R[i][2];
        mat[k][3] = R[i][3];
        mat[k][4] = R[i][4];
        j++;
        k++;
    }
}
void mergeSort(int mat[][5], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        //
        mergeSort(mat, l, m);
        mergeSort(mat, m + 1, r);
        //
        merge(mat, l, m, r);
    }
}
void wrapperMerge(int mat[][5], int n) {
    int i;
    for (i = 0; i < n; i++) {
        mat[i][3] = mat[i][1] + mat[i][2];
    }
    mergeSort(mat, 0, 5);
}
