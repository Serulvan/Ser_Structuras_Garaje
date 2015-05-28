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
		if (strcasecmp(matricula, taller[i].matricula) == 0)
			return i;
	} while (++i < size(taller));
	return -1;
}

void ordenar(struct Coche taller[]) {
	struct Coche aux;
	int i, j;
	for (i = 0; i < size(taller) - 1; ++i) {
		for (j = 1; j < size(taller); ++j) {
			if (strcasecmp(taller[i].matricula, taller[j].matricula) == 1) {
				aux = taller[i];
				taller[i] = taller[j];
				taller[j] = aux;
			}
		}
	}
}

int insertar(struct Coche coche, struct Coche taller[]) {
	if (buscar(taller, coche.matricula) != -1) {
		return 2;
	} else if (buscar(taller, NULL) != -1) {
		taller[bucar(taller, NULL)] = coche;
		return 0;
	} else
		return 1;
}

int borrar(struct Coche taller[], char matricula[]) {
	if (buscar(taller, matricula) == -1) {
		return 1;
	} else{
		taller[buscar(taller, matricula)] == NULL;
		return 0;
	}
}

int main(void) {
	setbuf(stdout, NULL);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
