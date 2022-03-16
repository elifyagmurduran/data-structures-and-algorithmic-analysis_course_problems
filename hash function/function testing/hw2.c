// ---------- ON ISLEMCI TANIMLARI ----------

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1500
#define M 997
#define MM 996
#define R 31

// ---------- GLOBAL TANIMLAMALAR ----------

// Hash'lenmis kelimeyi ve o kelimenin gectigi dokumanlardan olusan listeyi tutan struct
struct ItemStruct {
    int key;
    char *documents;
};
typedef struct ItemStruct Item;

// Item tipinde verileri tutan hash table dizisi
Item *table[M];

// -------- FONKSIYON PROTOTIPLERI --------

// Girilen stringi temsil edecek int tipindeki sayiyi Horner's Method ile bulur ve dondurur
int hornersMethod(char *str);

// doubleHash fonksiyonunda kullanılacak hash1
int hash1(int key);

// doubleHash fonksiyonunda kullanılacak hash2
int hash2(int key);

// Girilen key'i, i parametresine gore hash1 ve hash2 fonksiyonlarini kullanarak hashler ve sonucu dondurur
int doubleHash(int key, int i);

// Girilen keyString'i hash table icinde arar, bulursa Item*'ini, bulamazsa NULL degerini dondurur
Item *find(char *keyString);

// Girilen keyString, tabloda mevcutsa documents listesine girilen document'i ekler, mevcut degilse yeni item olarak tabloya ekler
void insert(char *keyString, char *document);

// Girilen keyString tabloda mevcutsa siler ve documents listesini dondurur, mevcut degilse -1 dondurur
void delete (char *keyString);

// ---------- MAIN FONKSIYONU ----------

int main() {
    insert("ahmet", "doc1");
    insert("mehmet", "doc2");
    insert("ali", "doc3");
    insert("ahmet", "doc4");

    printf("ahmet: %s\n", find("ahmet")->documents);
    printf("mehmet: %s\n", find("mehmet")->documents);
    printf("ali: %s\n", find("ali")->documents);
    return 0;
}

// ---------- FONKSIYON TANIMLARI ----------

int hornersMethod(char *str) {
    int key = 0;
    int i;
    int length = strlen(str);

    for (i = 1; i <= length; i++)
        key += pow((double)R, (double)(length - i)) * str[i - 1];
    return key;
}

int hash1(int key) {
    return key % M;
}

int hash2(int key) {
    return 1 + (key % MM);
}

int doubleHash(int key, int i) {
    return (hash1(key) + (i * hash2(key))) % M;
}

Item *find(char *keyString) {
    int key = hornersMethod(keyString); // keyString'i int'e cevirip key'de tut
    int i = 1;                          // doubleHash'deki i carpanini 1 olarak ilklendir
    int index = doubleHash(key, i);     // key ve i degerleri ile double hash yapip index bul

    // Kelimeyi veya bos bir yeri (bos yerden sonra kelimenin olma ihtimali yok) bulana kadar aramaya devam et (i'nin ust limiti: M)
    while (table[index] != NULL && i <= M) {
        // Kelime bulunan index'te ise, Item*'ini dondur
        if (table[index]->key == key)
            return table[index];

        i++;                        // i'yi arttir
        index = doubleHash(key, i); // Yeni i degerine gore double hash ile index belirle
    }

    // Kelime bulunamadiysa NULL dondur
    return NULL;
}

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
}

void delete (char *keyString) {
    Item *item = find(keyString); // Kelimeyi tabloda ara

    // Kelime bulunamadiysa fonksiyondan cik
    if (item == NULL)
        return;

    item->key = -1; // Kelimenin silindigi anlamina gelen -1 isareti koy
    return;         // Fonksiyondan cik
}
