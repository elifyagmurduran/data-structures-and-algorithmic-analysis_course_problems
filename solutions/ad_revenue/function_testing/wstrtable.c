#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ad {
    char index;
    int start;
    int duration;
    int endtime;
    int value;
};
struct prft {
    int revenue;
    char *ads;
};
void print(int n, struct ad table[]);
void merge(struct ad table[], int l, int m, int r);
void mergeSort(struct ad table[], int l, int r);
int max(int a, int b);
/*
 j | StartTime | Duration | Value
 ---------------------------------
 a |     5     |     3    |   3
 b |     9     |     4    |   7
 c |     11    |     6    |   9
 d |     4     |     7    |   5
 e |     1     |     3    |   2
 f |     2     |     5    |   3

 */
int main() {
    int i, j, k;
    int n = 6;
    struct prft profit[7];
    int x;
    char temp[1]; //strdup fonksiyonunu kullanabilmek için temp
    // strtable[i], profit[i] deki reklamları tutar
    // an itibariyle her gözde P var

    struct ad table[6] = {
        {'a', 5, 3, 0, 3},
        {'b', 9, 4, 0, 7},
        {'c', 11, 6, 0, 9},
        {'d', 4, 7, 0, 5},
        {'e', 1, 3, 0, 2},
        {'f', 2, 5, 0, 3}};
    printf("advertisements table:");
    print(n, table);
    printf("\nindex names have been changed to characters in order to avoid confusion.");
    // calculate end times
    printf("\ncalculating the ending hours...\n");
    for (i = 0; i < n; i++) {
        table[i].endtime = table[i].start + table[i].duration;
    }
    // sort
    printf("sorting...\n");
    mergeSort(table, 0, n - 1);
    printf("\nsorted table:");
    print(n, table);
    // solution

    // sıfırıncı göz ve birinci göz özel durumdur
    
    printf("!!!!!%s!!!", profit[0].ads);
    /*
        //  2 den hesaba başlanır
        for (i = 2; i < 7 + 1; i++) { // profitte gezen indis
            j = i - 1;
            k = i - 2; // table da j profitte i nin olduğu harfi, k bir önceki harfi gösterdi
            while ((k >= 0) && (table[k].endtime > table[j].start)) {
                k--;
            }
            //çakışma olmayan son reklam bulundu
            profit[i] = max((profit[k + 1] + table[j].value), profit[i - 1]);
        }
        for (i = 0; i < 7; i++) {
            printf("\n!!%d!!", profit[i]);
        }
        // solution end
    */
    //  display answer here
    printf("");
    printf("goodbye.\n");
    return 0;
}
void print(int n, struct ad table[]) {
    int i, j;
    printf("\n----------------------------------------------------");
    printf("\n i | StartTime |  Duration |  EndTime  |   Value\n----------------------------------------------------");
    for (i = 0; i < n; i++) {
        printf("\n %c |", table[i].index);
        if (table[i].start < 10) {
            printf("     %d     |", table[i].start);
        } else {
            printf("     %d    |", table[i].start);
        }
        printf("     %d     |", table[i].duration);
        if (table[i].endtime < 10) {
            printf("     %d     |", table[i].endtime);
        } else {
            printf("     %d    |", table[i].endtime);
        }
        printf("     %d     |", table[i].value);
    }
    printf("\n----------------------------------------------------\n");
}
void merge(struct ad table[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct ad L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = table[l + i];
    for (j = 0; j < n2; j++)
        R[j] = table[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
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

    while (i < n1) {
        table[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        table[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(struct ad table[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(table, l, m);
        mergeSort(table, m + 1, r);

        merge(table, l, m, r);
    }
}
int max(int a, int b) {
    if (a < b) {
        return b;
    } else {
        return a;
    }
}