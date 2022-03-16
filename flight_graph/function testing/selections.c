#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, k;
    // user info variables
    char user_source[25];
    char user_destination[25];
    int max_transfer; // 0<transfer<city
    int max_duration;
    int max_price;
    char criteria;
    char selection_forextrainfo;
    char selection_tocontinue;
    char selection_duration;
    int hour_constr;
    int minute_constr;
    char selection_price;
    int price_constr;
    int city_count = 8;
    //  get info from user
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