/*
 ============================================================================
 Name        : ESTRUCTURAS_garaje.c
 Author      : Serulvan
 Version     : 0.1
 Copyright   : psa
 Description : trabajo con estructuras
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Coche {
    char matricula[7];
    char marca[15];
    char modelo[15];
    int cv;
};

int size(struct Coche taller[]) {
    return sizeof (taller) / sizeof (taller[0]);
}

int buscar(struct Coche taller[], char matricula[]) {
    int i = 0;
    do {
        if (strcasecmp(matricula, taller[i].matricula) == 0) {
            return i;
        }
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
    } else {
        int i = buscar(taller, " ");
        if (i != -1) {
            taller[i] = coche;
            return 0;
        }
    }
    return 1;

}

int borrar(struct Coche taller[], char matricula[]) {
    int i = buscar(taller, matricula);
    if (i == -1) {
        return 1;
    } else {
        strcpy(taller[i].matricula, " ");
        return 0;
    }
}

int main(void) {
    setbuf(stdout, NULL);
    struct Coche taller[10];
    int i;
    for (i = 0; i < 10; i++) {
        strcpy(taller[i].matricula, " ");
    }

    printf("%d\n", size(taller));
    return EXIT_SUCCESS;
}
