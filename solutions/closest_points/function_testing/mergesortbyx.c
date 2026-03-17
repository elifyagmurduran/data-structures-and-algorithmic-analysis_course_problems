
#include <stdio.h>
#include <stdlib.h>

void merge(int mat[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1][2], R[n2][2];

    for (i = 0; i < n1; i++)
    {
        L[i][0] = mat[l + i][0];
        L[i][1] = mat[l + i][1];
    }

    for (j = 0; j < n2; j++)
    {
        R[j][0] = mat[m + 1 + j][0];
        R[j][1] = mat[m + 1 + j][1];
    }

    /* Merge the temp matays back into mat[l..r]*/
    i = 0; // Initial index of first submatay
    j = 0; // Initial index of second submatay
    k = l; // Initial index of merged submatay
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            mat[k][0] = L[i][0];
            mat[k][1] = L[i][1];
            i++;
        }
        else
        {
            mat[k][0] = R[j][0];
            mat[k][1] = R[j][1];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        mat[k][0] = L[i][0];
        mat[k][1] = L[i][1];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        mat[k][0] = R[j][0];
        mat[k][1] = R[j][1];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-matay of mat to be sorted */
void mergeSort(int mat[][2], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        //
        mergeSort(mat, l, m);
        mergeSort(mat, m + 1, r);
        //
        merge(mat, l, m, r);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an matay */
void printmatay(int mat[][2], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", mat[i][0], mat[i][1]);
    }
}

/* Driver code */
int main()
{
    int mat[10][2] = {
        {4, 8},
        {6, 7},
        {24, 16},
        {12, 11},
        {13, 10},
        {20, 24},
        {7, 14},
        {26, 29},
        {40, 35}};
    int mat_size = 10;

    printf("Given mat is \n");
    printmatay(mat, mat_size - 1);

    printf("\nSorted mat is \n");
    printmatay(mat, mat_size - 1);
    return 0;
}
