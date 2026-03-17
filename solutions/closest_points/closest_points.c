#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
int *xptr1, *yptr1, *xptr2, *yptr2;
float distance(int x1, int y1, int x2, int y2);
float min(float a, float b);
float bruteforce(int size, int mat[][2]);
float closestfunction(int n, int mat[][2]);
float stripcalc(int n, int mat[][2], float d);
void merge(int mat[][2], int l, int m, int r);
void mergesortbyx(int mat[][2], int l, int r);
//
int main() {
    int i, j, k;
    int n;
    int x1, y1, x2, y2; //x and y that are the min distanced point candidates
    double dmin;
    float temp;
    xptr1 = &x1;
    yptr1 = &y1;
    xptr2 = &x2;
    yptr2 = &y2;
    FILE *fptr;
    char str[50];
    char selection = 'y';
    while (selection == 'y') {
        printf("please enter sample file name:");
        scanf("%s", &str);
        //
        printf("how many points are there?\t");
        scanf("%d", &n);
        //
        int mat[n][2];
        //
        fptr = fopen(str, "r");
        //
        if (fptr == NULL) {
            printf("file failed to open.");
        } else {
            printf("file has now opened.\nexecuting program...\n");
            //prep matrix here
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
            mergesortbyx(mat, 0, n - 1);
            printf("sorted matrix:\n");
            for (i = 0; i < n; i++) {
                printf("%d %d\n", mat[i][0], mat[i][1]);
            }
            printf("now calculating closest points...\n");
            closestfunction(10, mat);
            temp = distance(x1, y1, x2, y2); //this extra step is to solve the issue sqrt func raised
            dmin = sqrt(temp);
            printf("closest points are: (%d, %d) and (%d, %d) + the smallest distance is -> %f", x1, y1, x2, y2, dmin);
            fclose(fptr);
            printf("\nfile is now closed.\n");
        }
        printf("do you want to continue? y/n:");
        scanf("%c", &selection);
        scanf("%c", &selection);
    }
    printf("program ended. goodbye.");

    return 0;
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
    int matstrip[n][2];
    float stripd = FLT_MAX;
    int i = 0;
    int j = 0;
    int k = 0;
    int mid = n / 2;
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    for (i = 0; i < n; i++) {
        if ((abs(mat[i][0]) - mid) < d) {
            matstrip[j][0] = mat[i][0];
            matstrip[j][1] = mat[i][1];
            j++;
        }
    }
    //sort the strip
    for (i = 0; i < j; i++) {
        for (k = (i + 1); k < j; k++) {
            if (d != min(d, distance(matstrip[i][0], matstrip[i][1], matstrip[k][0], matstrip[k][1]))) {
                *xptr1 = matstrip[i][0];
                *yptr1 = matstrip[i][1];
                *xptr2 = matstrip[k][0];
                *yptr2 = matstrip[k][1];
                d = distance(mat[i][0], mat[i][1], mat[k][0], mat[k][1]);
            }
        }
    }
    return stripd;
}
float closestfunction(int n, int mat[][2]) {
    float d = FLT_MAX;
    float dl, dr;

    if (n <= 3) {
        d = bruteforce(n, mat);
    } else {
        int mid = n / 2; //mid is the row number
        float d = FLT_MAX;
        float dl, dr;

        dl = closestfunction(mid, mat);
        dr = closestfunction((n - mid), mat + mid);

        d = min(dl, dr);
        d = min(d, stripcalc(n, mat, d));
    }
    return d;
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
