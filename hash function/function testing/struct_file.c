#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define R 31
#define M 997
#define MM 996

int horners(char str[]);
int h1(int key);
int h2(int key);
int hashDouble(int key, int i);

struct ItemStruct {
    int key;
    char docs[50];
};
typedef struct ItemStruct item;
item* hashtable[M];


int main (){ 
	FILE *outfile; 
      
  
    outfile = fopen ("person.txt", "w"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } 
  
    item input1 = {7, "anan"}; 
    item input2 = {5, "eben"}; 
 
    fwrite (&input1, sizeof(item), 1, outfile); 
    fwrite (&input2, sizeof(item), 1, outfile); 
      
    if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
  
    fclose (outfile);
    
    outfile = fopen ("person.txt", "r"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
      
    while(fread(&input1, sizeof(item), 1, outfile)) 
        printf ("id = %d name = %s\n", input1.key, 
        input1.docs); 
  
    fclose (outfile);
  
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






