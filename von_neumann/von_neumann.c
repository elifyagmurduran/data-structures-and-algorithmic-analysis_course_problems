#include <stdio.h>
#include <stdlib.h>
int main() {

    int n, i, j, k, m, x, y;
    printf("please enter n:\t");
    scanf("%d", &n);

    int size = 2 * n + 3;
    int *arr[size];

    for (i = 0; i < size; i++) {
        arr[i] = (int *)calloc(size, 4);
    }

    k = size / 2;
    i = 0;
    while ((k - i) >= 0) {
        for (j = i + 1; j < size - i - 1; j++) {
            arr[k - i][j] = 1;
            arr[k + i][j] = 1;
        }
        i++;
    }
    printf("von neumann matrix for n = %d\n", n);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n\n\n\n");
    }

    return 0;
}
