#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct flighttable {
    int index;
    char source[25];
    int source_index;
    char destination[25];
    int destination_index;
    int hour;
    int minute;
    int price;
};
struct adjacency_matrix_struct { //[i][j] are gonna be city matrix indexes
    int adjacency;
    int hour;
    int minute;
    int price;
};
void printflights(struct flighttable table[], int size);
void printadjmat(int city_count, struct adjacency_matrix_struct **table);
int main() {
    int i, j, k;
    int c1, c2;
    // user info variables
    char user_source[25];
    char user_destination[25];
    int max_transfer; // 0<transfer<city
    int max_duration;
    int max_price;
    char selection_forextrainfo;
    char selection_tocontinue;
    char selection_duration;
    int hour_constr;
    int minute_constr;
    char selection_price;
    int price_constr;
    int flight_count = 0;
    // struct to put the stuff from file and file reading stuff variables
    FILE *fptr;
    char filestr[75];
    char temp_source[25];
    char temp_destination[25];
    int temp_hour;
    int temp_minute;
    int temp_price;
    struct adjacency_matrix_struct **adj_matrix;
    struct flighttable *flights = (struct flighttable *)malloc(sizeof(struct flighttable) * 25);
    // graph stuff variables
    char **city_matrix = (char **)malloc(2 * sizeof(char *));
    int city_count;
    // read from file to make the struct array
    fptr = fopen("sample.txt", "r");
    if (fptr == NULL) {
        printf("sample.txt failed to open.");
        exit(0);
    } else {
        printf("\nThe file is now opened.\n");
        while (fgets(filestr, 50, fptr) != NULL) {
            sscanf(filestr, "%s %s %d %d %d", temp_source, temp_destination, &temp_hour, &temp_minute, &temp_price);
            flights[flight_count].index = flight_count;
            strcpy(flights[flight_count].source, temp_source);
            strcpy(flights[flight_count].destination, temp_destination);
            flights[flight_count].hour = temp_hour;
            flights[flight_count].minute = temp_minute;
            flights[flight_count].price = temp_price;
            flight_count++;
        }
    }
    // realloc to flight_count then print the flights table
    flights = realloc(flights, flight_count * sizeof(struct flighttable));

    fclose(fptr);
    printf("\n\nThe file is now closed.\n");
    printflights(flights, flight_count);
    // city matrix
    city_matrix[0] = (char *)malloc(25 * sizeof(char));
    sprintf(city_matrix[0], flights[0].source);
    flights[0].source_index = 0;
    city_matrix[1] = (char *)malloc(25 * sizeof(char));
    sprintf(city_matrix[1], flights[0].destination);
    flights[0].destination_index = 1;
    city_count = 2;
    j = 1; // flighttable da index
    while (j < flight_count) {
        // source var mı
        i = 0;
        while ((i < city_count) && (strcmp(city_matrix[i], flights[j].source) != 0)) {
            i++;
        }
        if (i >= city_count) {
            city_count++;
            city_matrix[i] = (char *)malloc(25 * sizeof(char));
            *city_matrix = realloc(*city_matrix, city_count * sizeof(char *));
            sprintf(city_matrix[i], flights[j].source);
            flights[j].source_index = i;
        }
        if (strcmp(city_matrix[i], flights[j].source) == 0) {
            flights[j].source_index = i;
        }

        // destination var mı
        i = 0;
        while ((i < city_count) && (strcmp(city_matrix[i], flights[j].destination) != 0)) {
            i++;
        }
        if (i >= city_count) {
            city_count++;
            city_matrix[i] = (char *)malloc(25 * sizeof(char));
            *city_matrix = realloc(*city_matrix, city_count * sizeof(char *));
            sprintf(city_matrix[i], flights[j].destination);
            flights[j].destination_index = i;
        }
        if (strcmp(city_matrix[i], flights[j].destination) == 0) {
            flights[j].destination_index = i;
        }
        j++;
    }

    printf("\nNumber of cities in the file: %d\n", city_count);
    printf("City vs index:\n");
    for (i = 0; i < city_count; i++) {
        printf("\t%d - %s\n", i, city_matrix[i]);
    }

    adj_matrix = (struct adjacency_matrix_struct **)malloc(city_count * sizeof(struct adjacency_matrix_struct *));
    for (i = 0; i < city_count; i++) {
        adj_matrix[i] = (struct adjacency_matrix_struct *)malloc(city_count * sizeof(struct adjacency_matrix_struct));
    }
    // zero all values
    for (i = 0; i < city_count; i++) {
        for (j = 0; j < city_count; j++) {
            adj_matrix[i][j].adjacency = 0;
            adj_matrix[i][j].hour = 0;
            adj_matrix[i][j].minute = 0;
            adj_matrix[i][j].price = 0;
        }
    }
    for (i = 0; i < flight_count; i++) {
        c1 = flights[i].source_index;
        c2 = flights[i].destination_index;
        // first for the city 1 city 2 cell
        adj_matrix[c1][c2].adjacency = 1;
        adj_matrix[c1][c2].hour = flights[i].hour;
        adj_matrix[c1][c2].minute = flights[i].minute;
        adj_matrix[c1][c2].price = flights[i].price;
        // now for the city 2 city 2 cell
        adj_matrix[c2][c1].adjacency = 1;
        adj_matrix[c2][c1].hour = flights[i].hour;
        adj_matrix[c2][c1].minute = flights[i].minute;
        adj_matrix[c2][c1].price = flights[i].price;
    }
    printadjmat(city_count, adj_matrix);
    // getting info from user to search the graph accordingly
    selection_tocontinue = 'y';
    while (selection_tocontinue == 'y') {
        printf("\nPlease select your flight preferences.");
        // a loop for user to make new selections here
        printf("\nWhere would you like to lift off from?\t");
        scanf("%s", &user_source);
        printf("\nWhere would you like to land?\t");
        scanf("%s", &user_destination);
        printf("\nMaximum transfers you would like to allow:\t");
        scanf("%d", &max_transfer);
        while (max_transfer > city_count) {
            printf("\nThat is not allowed. Maximum allowed transfers are %d. Please pick again.\t", city_count);
            scanf("%d", &max_transfer);
        }
        printf("\nWould you like to set additional constraints? y/n\t");
        scanf("%c", &selection_forextrainfo);
        scanf("%c", &selection_forextrainfo);
        while ((selection_forextrainfo != 'y') && (selection_forextrainfo != 'n')) {
            printf("\nThat is not allowed. Please select one of the two y/n:\t");
            scanf("%c", &selection_forextrainfo);
            scanf("%c", &selection_forextrainfo);
        }
        if (selection_forextrainfo == 'y') {
            printf("\nAdd a duration constraint? y/n\t");
            scanf("%c", &selection_duration);
            scanf("%c", &selection_duration);
            while ((selection_duration != 'y') && (selection_duration != 'n')) {
                printf("\nThat is not allowed. Please select one of the two y/n:\t");
                scanf("%c", &selection_duration);
                scanf("%c", &selection_duration);
            }
            if (selection_duration == 'y') {
                printf("How many hours?");
                scanf("%d", &hour_constr);
                printf("How many minutes?");
                scanf("%d", &minute_constr);
            }

            printf("\nAdd a price constraint? y/n\t");
            scanf("%c", &selection_price);
            scanf("%c", &selection_price);
            while ((selection_price != 'y') && (selection_price != 'n')) {
                printf("\nThat is not allowed. Please select one of the two y/n:\t");
                scanf("%c", &selection_price);
                scanf("%c", &selection_price);
            }
            if (selection_price == 'y') {
                printf("Maximum price?");
                scanf("%d", &price_constr);
            }
        }

        printf("\nProgram ended. Would you like to make new choices? y/n\t");
        scanf("%c", &selection_tocontinue);
        scanf("%c", &selection_tocontinue);
        while ((selection_tocontinue != 'y') && (selection_tocontinue != 'n')) {
            printf("\nThat is not allowed. Please select one of the two y/n:\t");
            scanf("%c", &selection_tocontinue);
            scanf("%c", &selection_tocontinue);
        }
    }

    return 0;
}
void printadjmat(int city_count, struct adjacency_matrix_struct **table) {
    int i, j;
    printf("\nThe adjacency matrix is:\n");
    for (i = 0; i < city_count; i++) {
        for (j = 0; j < city_count; j++) {
            printf("  | %d %d %d %d |\t", table[i][j].adjacency, table[i][j].hour, table[i][j].minute, table[i][j].price);
        }
        printf("\n");
    }
}
void printflights(struct flighttable table[], int size) {
    int i;
    i = 0;
    while (i < size) {
        printf("\nThe flight to %s from %s  | %d hours %d minutes | Price: %d", table[i].source, table[i].destination, table[i].hour, table[i].minute, table[i].price);
        i++;
    }
}