#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define R 31
int horners(char str[]); 
int main(){
	int M = 1019;

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
