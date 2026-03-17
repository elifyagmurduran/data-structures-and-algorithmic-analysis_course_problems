#include <stdio.h>
#include <stdlib.h>
struct adjacency_matrix_struct { //[i][j] are gonna be city matrix indexes
    int adjacency;
    int hour;
    int minute;
    int price;
};

int main() {
    int r = 3, c = 3, i, j, count;
    struct adjacency_matrix_struct **adj_matrix;
    adj_matrix = (struct adjacency_matrix_struct **)malloc(r * sizeof(struct adjacency_matrix_struct *));
    for (i = 0; i < r; i++)
        adj_matrix[i] = (struct adjacency_matrix_struct *)malloc(c * sizeof(struct adjacency_matrix_struct));

    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            adj_matrix[i][j].hour = ++count; // OR *(*(arr+i)+j) = ++count

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            printf("%d ", adj_matrix[i][j].hour);

    /* Code for further processing and free the
    dynamically allocated memory */

    for (int i = 0; i < r; i++)
        free(arr[i]);

    free(arr);

    return 0;
}

  // adj matrix time w dynamic initilization

    // fill the matrix
    for (i = 0; i < city_count; i++) {
        // firstly the diagonal is gonna be zeroed
        adj_matrix[i][i].adjacency = 0;
        adj_matrix[i][i].hour = 0;
        adj_matrix[i][i].minute = 0;
        adj_matrix[i][i].price = 0;
        // now to search
        if (i != 0) {
            // source var mı
            k = 0;
            j = 0;
            while ((k < flight_count) && ((strcmp(city_matrix[j], flights[k].source) != 0) || (strcmp(city_matrix[j], flights[k].destination) != 0))) {
                k++;
            }
            if (k < flight_count) {
                sprintf(city_matrix[j], flights[k].source);
            }
        }
    }
