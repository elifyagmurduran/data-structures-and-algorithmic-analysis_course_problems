#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M1 97
#define M2 96
#define R 31
struct person_info {
    char id[5];
    int key;
    char name[50];
    char surname[50];
    int year;
    char city[25];
    bool deleted;
};
struct person_info *hash_table[M1];
int horners(char *str);
int h1(int key);
int h2(int key);
int double_hash(int key, int i);
struct person_info *find_hashfunc(char *keyString);
void insert_hashfunc(char id[5], struct person_info temp);
void delete_hashfunc(char *keyString);
void print_hashfunc();

int main() {
    int i, j, k;
    int size;
    int item_count = 0;
    float loadfactor;
    // file temps
    char filestr[250];
    struct person_info temp_item;
    FILE *fptr;
    fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        printf("test.txt failed to open.");
        exit(0);
    } else {
        printf("\nThe file is now opened.\n");
        while (fgets(filestr, 50, fptr) != NULL) {
            sscanf(filestr, "%s %s %s %d %s", temp_item.id, temp_item.name, temp_item.surname, &temp_item.year, temp_item.city);
            insert_hashfunc(temp_item.id, temp_item);
            item_count++;
        }
        fclose(fptr);
        printf("\n\nThe file is now closed.\n");
        print_hashfunc();
    }
    return 0;
}
void print_hashfunc() {
    printf("current hashtable look is:");
    int i;
    for (i = 0; i < M1; i++) {
        if (hash_table[i]->key != 0) {
            printf("\ni = %d | id: %s / Name, Surname: %s %s / Year: %d / City: %s", i, hash_table[i]->id, hash_table[i]->name, hash_table[i]->surname, hash_table[i]->year, hash_table[i]->city);
        }
    }
}
int horners(char str[5]) {
    int hashed_key;
    int i;
    for (i = 0; i < 5; i++) {
        hashed_key = R * hashed_key + (str[i] - 'A' + 1);
    }
    return hashed_key;
}
int h1(int key) {
    return key % M1;
}
int h2(int key) {
    return 1 + (key % M2);
}
int double_hash(int key, int i) {
    return (h1(key) + (i * h2(key))) % M1;
}

struct person_info *find_hashfunc(char id[5]) {
    int key = horners(id);
    int i = 1;
    int index = double_hash(key, i);

    while ((hash_table[index]->key != 0) && i <= M1) {
        if (hash_table[index]->key == key) {
            return hash_table[index];
        }
        i++;
        index = double_hash(key, i);
    }
    return NULL;
}

void insert_hashfunc(char id[5], struct person_info temp) {
    struct person_info *item = find_hashfunc(id);
    int key = horners(id);
    int i = 1;
    int index = double_hash(key, i);

    item = (struct person_info *)malloc(sizeof(struct person_info));

    strcpy(item->id, temp.id);
    strcpy(item->name, temp.name);
    strcpy(item->surname, temp.surname);
    item->year = temp.year;
    strcpy(item->city, temp.city);
    item->deleted = false;

    while (hash_table[index] != NULL && i <= M1) {
        index = double_hash(key, i);
        i++;
    }

    if (i == M1) {
        return;
    } else {
        hash_table[index] = item;
    }
}

void delete_hashfunc(char *id) {
    struct person_info *item = find_hashfunc(id);
    if (item == NULL) {
        return;
    } else {
    	strcpy(item->id, "0");
    	strcpy(item->name, "0");
    	strcpy(item->surname, "0");
    	item->year = 0;
    	strcpy(item->city, "0");
        item->deleted = true;
        return;
    }
}
