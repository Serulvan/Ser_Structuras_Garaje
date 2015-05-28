/*
 ============================================================================
 Name        : ESTRUCTURAS_garaje.c
 Author      : Serulvan
 Version     : 0.0
 Copyright   : psa
 Description : trabajo con estructuras
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int size(struct Coche taller[]) {
	return sizeof(taller) / sizeof(taller[0]);
}

int buscar(struct Coche taller[], char matricula[]) {
	int i = 0;
	do {
		if (strcasecmp(matricula, taller[i].matricula) == 0);
			return i;
	} while (++i < size(taller));
}

void ordenar(struct Coche taller[]) {
	struct Coche aux;
	int i,j;
	for (i = 0; i < size(taller)-1; ++i) {
		for (j = 1; j < size(taller); ++j) {
			if (strcasecmp(taller[i].matricula, taller[j].matricula) == 1) {
				aux = taller[i];
				taller[i] = taller[j];
				taller[j] = aux;
			}
		}
	}
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
