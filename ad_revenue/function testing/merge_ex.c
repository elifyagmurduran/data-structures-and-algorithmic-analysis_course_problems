/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
struct ad {
    char index; // a b c diye yaptım ki sort tan sonra karışmasın
    int start;
    int duration;
    int endtime;
    int value;
};
void merge(struct ad table[], int l, int m, int r);
void mergeSort(struct ad table[], int l, int r);
void print(int n, struct ad table[]);
int main() {
    int i, j, k;
    int n = 6;
    struct ad table[6] = {
        {'a', 5, 3, 0, 3},
        {'b', 9, 4, 0, 7},
        {'c', 11, 6, 0, 9},
        {'d', 4, 7, 0, 5},
        {'e', 1, 3, 0, 2},
        {'e', 2, 5, 0, 3}};
    print(table, n);
    return 0;
}

void merge(struct ad table[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    struct ad L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = table[l + i];
    for (j = 0; j < n2; j++)
        R[j] = table[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].endtime <= R[j].endtime) {
            table[k] = L[i];
            i++;
        } else {
            table[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        table[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        table[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct ad table[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(table, l, m);
        mergeSort(table, m + 1, r);

        merge(table, l, m, r);
    }
}
