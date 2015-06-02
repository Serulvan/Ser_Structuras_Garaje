/*
 ============================================================================
 Name        : ESTRUCTURAS_garaje.c
 Author      : Serulvan
 Version     : 1.0
 Copyright   : psa
 Description : trabajo con estructuras
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

static int tam;

struct Coche {
    char matricula[8];
    char marca[15];
    char modelo[15];
    int cv;
};

int size(struct Coche taller[]) {
    //el 'sizeof(taller)' no devuelve el tama�o del array de structuras correctamente.
    return sizeof (taller) / sizeof (taller[0]);
}

int buscar(struct Coche taller[], char matricula[]) {
    int i = 0;
    do {
        if (strcasecmp(matricula, taller[i].matricula) == 0) {
            return i;
        }
    } while (++i < tam);
    return -1;
}

void ordenar(struct Coche taller[]) {
    struct Coche aux;
    int i, j;
    for (i = 0; i < tam - 1; ++i) {
        for (j = i-1; j < tam; ++j) {
            if (strcasecmp(taller[i].matricula, taller[j].matricula) > 0) {
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

void imprimir(struct Coche taller[], char matricula[]) {
    int i = buscar(taller, matricula);
    if (i != -1) {
        printf("la matricula es \t%s\n", taller[i].matricula);
        printf("la marca es     \t%s\n", taller[i].marca);
        printf("el modelo es    \t%s\n", taller[i].modelo);
        printf("los caballos son \t%d\n", taller[i].cv);
    } else {
        printf("coche no encontrado\n");
    }
}

int main(void) {
    setbuf(stdout, NULL);
    tam = 10;
    struct Coche taller[tam];
    int i;
    for (i = 0; i < tam; i++) {
        strcpy(taller[i].matricula, " ");
    }
    printf("bienvenido al taller, �que quieres hacer?\n");
    int n = -1;
    struct Coche cAInsertar;
    char mat[8];
    while (n != 5) {
        printf("1: introducir nuevo veh�culo\n"
                "2: Borrar un vehiculo\n"
                "3: ordenar los veh�culos\n"
                "4: Mostrar los datos de un veh�culo\n"
                "5: Salir\n\n");
        scanf("%d", &n);
        switch (n) {
            case 1:
                scanf("introduce la matricula: %s\n", &cAInsertar.matricula);
                scanf("introduce la marca: %s\n", &cAInsertar.marca);
                scanf("introduce el modelo: %s\n", &cAInsertar.modelo);
                scanf("introduce los cv: %d\n", &cAInsertar.cv);
                switch (insertar(cAInsertar, taller)) {
                    case 0:
                        printf("insertado correctamente");
                        break;
                    case 1:
                        printf("no hay sitio en el taller");
                        break;
                    case 2:
                        printf("la matricula ya existe");
                        break;
                    default:
                        printf("esto no tendria que mostrarse");
                }
                break;
            case 2:
                scanf("introduce la matricula: %s\n", &mat);
                switch (borrar(taller, mat)){
                    case 0:
                        printf("borrado correctamente");
                        break;
                    case 1:
                        printf("no encontrado");
                        break;
                    case 2:
                        printf("esto no tendria que mostrarse");
                        break;
                    default:
                        printf("esto no tendria que mostrarse");
                }
                break;
            case 3:
                scanf("Introduce la matricula: %s\n", &mat);
                imprimir(taller, mat);
                break;
            case 4:
                ordenar(taller);
                printf("Echo.");
                break;
            case 5:
                printf("Adios.");
                break;
            default:
                printf("por favor, elije:\n");
        }
    }


    return EXIT_SUCCESS;
}
