#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M1 997
#define M2 996
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

int main() {
    int i, j, k;
    int size;
    int item_count = 0;
    float loadfactor;
    // file temps
    char filestr[250];
    char temp_id[5];
    char temp_name[50];
    char temp_surname[50];
    int temp_year;
    char temp_city[25];
    struct person_info temp_item;
    printf("Enter the size of the table:");
    scanf("%d", &size);
    struct person_info *hash_table;
    hash_table = (struct person_info *)calloc(size, sizeof(struct person_info));
    FILE *fptr;
    fptr = fopen("test.txt", "r");
    if (fptr == NULL) {
        printf("test.txt failed to open.");
        exit(0);
    } else {
        printf("\nThe file is now opened.\n");

        while (fgets(filestr, 50, fptr) != NULL) {
            sscanf(filestr, "%s %s %d %d %d", temp_id, temp_name, temp_surname, &temp_year, temp_city);

            hash_insert();
           
            item_count++;
        }
        fclose(fptr);
        printf("\n\nThe file is now closed.\n");
        hash_print();
    }
    return 0;
}
int horners(char key[5]) {
    int hashed_key;
    int i;
    for (i = 0; i < 5; i++) {
        hashed_key = R * hashed_key + (key[i] - 'A' + 1);
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

struct person_info *hashfunc_search(char key[5], struct person_info hash_table[M1]) {
    int i = 1;
    int index = double_hash(horners(key), i);

    while (hash_table[index].id != 0 && i <= M1) {
        // Kelime bulunan index'te ise, Item*'ini dondur
        if (hash_table[index].id == key)
            return hash_table[index];
        i++;                        // i'yi arttir
        index = doubleHash(key, i); // Yeni i degerine gore double hash ile index belirle
    }

    // Kelime bulunamadiysa NULL dondur
    return NULL;
}
/*
void insert(char *keyString, char *document) {
    Item *item = find(keyString); // Girilen keyString ile tabloyu ara

    // Eger kelime tabloda zaten varsa kelimenin gectigi dokumanlari guncelle ve fonksiyondan cik
    if (item != NULL) {
        item->documents = strcat(item->documents, ",");      // Kelimenin documents stringine ',' ekle
        item->documents = strcat(item->documents, document); // Kelimenin documents stringine yeni dokumanin adini ekle
        return;                                              // Fonksiyondan cik
    }

    // Eger kelime tabloda yoksa tabloya yeni bir eleman olarak olarak ekle
    int key = hornersMethod(keyString); // keyString'i int'e cevirip key'de tut
    int i = 1;                          // doubleHash'deki i carpanini 1 olarak ilklendir
    int index = doubleHash(key, i);     // key ve i degerleri ile double hash yapip index bul

    item = (Item *)malloc(sizeof(Item));                // Struct icin yer allocate et
    item->key = key;                                    // Kelimenin keyini Horners Method ile bulunan sayisal karsiligi olarak ata
    item->documents = (char *)malloc(sizeof(document)); // Documents stringi icin yer allocate et
    strcpy(item->documents, document);                  // Allocate edilen yere yeni dokumani yerlestir

    // Tabloda bos veya silinmis bir yer bulana kadar dene (limit: tablo boyutu)
    while (table[index] != NULL && table[index]->key != -1 && i <= M) {
        index = doubleHash(key, i);
        i++;
    }

    // Eger uygun yer bulunamamis ise fonksiyondan cik
    if (i == M)
        return;

    // Bulunmus ise tabloya yerlestir
    else
        table[index] = item;
}*/
/*
void delete (char *keyString) {
    Item *item = find(keyString); // Kelimeyi tabloda ara

    // Kelime bulunamadiysa fonksiyondan cik
    if (item == NULL)
        return;

    item->key = -1; // Kelimenin silindigi anlamina gelen -1 isareti koy
    return;         // Fonksiyondan cik
}
*/
