/*
 ============================================================================
 Name        : ESTRUCTURAS_garaje.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int size(struct Coche taller[]){
	return sizeof(taller)/sizeof(taller[0]);
}

int buscar (struct Coche taller[], char matricula[]){
	int i = 0;
	do {
		if(strcasecmp(matricula, taller[i].matricula)==0)return i;
	} while (++i<size(taller));
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
