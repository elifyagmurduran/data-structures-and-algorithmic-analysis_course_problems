#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define R 31
#define M 997
#define MM 996

struct ItemStruct {
    int key;
    char* docs;
};
typedef struct ItemStruct item;
item* table[M];


int horners(char str[]);
int h1(int key);
int h2(int key);
int hashDouble(int key, int i);
item* find(char str[]);
void insert(char str[], char docname[]);

int main(){
	int wordcount = 0;
	int load_factor = 0;
	int selection;
	FILE *fhash;
	FILE *f1;
	char filename[50];
	char tmptxt[20];
	item* tmp;
	fhash = fopen("hashfile.txt", "w");
	printf("to add a new document, select 1. to search for a word, select 2. if you want to exit the program, select 0.\t");
	scanf("%d", &selection);
	
	while( selection != 0 ){
		if(selection == 1){/*scan a new doc*/
			
			printf("\nenter name of document:");
			scanf("%s", filename);
			f1 = fopen(filename, "w");
			if( f1 == NULL ){
				printf("file failed to open.") ; 
			}else{
				while( f1 != NULL){
					fscanf(f1,"%s",tmptxt);
					insert(tmptxt, filename);
					wordcount++;
					load_factor = wordcount/M;
					if( load_factor >= 0.8){
						printf("\nwarning. hash table is filled too much.");
					}
					if( load_factor >= 1){
						printf("\nhash table full. exiting program.");
						selection = 0;
					}	
				}	
			}
		}else if(selection == 2){/*search for a word*/
			printf("\nenter word:\t");
			scanf("%s", tmptxt);
			if(find(tmptxt) == NULL){
				printf("\ncouldn't find word.");
			}else{
				tmp = find(tmptxt);
				printf("\ndocs that include given word:%s\t", tmp->docs);
			}			
		}else{
			printf("\nwrong selection. please enter 1 to add a new document, or 2, to search for a word.\t");
		}
		printf("\nto add a new document, select 1. to search for a word, select 2. if you want to exit the program, select 0.\t");
		scanf("%d", &selection);
	}
	

	printf("\nexiting program. have a nice day.");
	return 0;
}

int horners(char str[]){
	int key = 0;
	int i;
	int n = strlen(str);
	for( i=0 ; i<n ; i++){
		key =+ ( pow(R, n-i-1)*str[i] );
	}
	return key;
}
int h1(int key){
	return key % M;
}
int h2(int key){
	return 1 + (key % MM);
}
int hashDouble(int key, int i){
	return ( h1(key) + i*h2(key) ) % M;
}
item* find(char str[]){
    int key = horners(str);  
    int i = 1;                        
    int j = hashDouble(key, i);      
    while (i <= M && table[j] != NULL){
        if (table[j]->key == key){
        	return table[j];
		}
        i++;                       
        j = hashDouble(key, i);  
    }
    return NULL;
}
void insert(char str[], char docname[]) {

}






