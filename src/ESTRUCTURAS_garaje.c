/*
 ============================================================================
 Name        : ESTRUCTURAS_garaje.c
 Author      : Serulvan
 Version     : 1.1
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
    //el 'sizeof(taller)' no devuelve el tamaño del array de structuras correctamente.
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
    for (i = 0; i < tam - 1; i++) {
        for (j = i+1; j < tam; j++) {
            if (strcasecmp(taller[i].matricula, taller[j].matricula) > 0) {
                aux = taller[i];
                taller[i] = taller[j];
                taller[j] = aux;
            }
        }
    }
/*
    for (i = 0; i < tam; i++) {
        printf("%s\n",taller[i].matricula);

    }
*/

}

int insertar(struct Coche coche, struct Coche taller[]) {
    if (buscar(taller, coche.matricula) != -1) {
        return 2;
    } else {
        int i = buscar(taller, "~~");
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
        strcpy(taller[i].matricula, "~~");
        return 0;
    }
}

void imprimir(struct Coche taller[], char matricula[]) {
    int i = buscar(taller, matricula);
    if (i != -1) {
        printf("la matrícula es \t%s\n", taller[i].matricula);
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
        strcpy(taller[i].matricula, "~~");
    }
/*
    strcpy(taller[0].matricula, "333");
    strcpy(taller[1].matricula, "111");
    strcpy(taller[2].matricula, "777");
    strcpy(taller[3].matricula, "222");
*/

    printf("bienvenido al taller, ¿que quieres hacer?\n");
    int n = -1;
    struct Coche cAInsertar;
    char mat[8];
    while (n != 5) {
        printf("\n1: introducir nuevo vehículo\n"
                "2: Borrar un vehículo\n"
                "3: Mostrar los datos de un vehículo\n"
                "4: ordenar los vehículos\n"
                "5: Salir\n\n");
        setbuf(stdin, NULL);
        scanf("%d", &n);
        switch (n) {
            case 1:
            	printf("introduce la matrícula:\n");
                scanf("%s", cAInsertar.matricula);
                printf("introduce la marca:\n");
                scanf("%s", cAInsertar.marca);
                printf("introduce el modelo:\n");
                scanf("%s", cAInsertar.modelo);
                printf("introduce los caballos:\n");
                scanf("%d", &cAInsertar.cv);
                printf("\n");
                switch (insertar(cAInsertar, taller)) {
                    case 0:
                        printf("insertado correctamente\n");
                        break;
                    case 1:
                        printf("no hay sitio en el taller\n");
                        break;
                    case 2:
                        printf("la matricula ya existe\n");
                        break;
                    default:
                        printf("esto no tendría que mostrarse\n");
                }
                break;
            case 2:
                printf("introduce la matrícula: \n");
                scanf("%s", &mat);
                switch (borrar(taller, mat)){
                    case 0:
                        printf("borrado correctamente\n");
                        break;
                    case 1:
                        printf("no encontrado\n");
                        break;
                    case 2:
                        printf("esto no tendría que mostrarse\n");
                        break;
                    default:
                        printf("esto no tendría que mostrarse\n");
                }
                break;
            case 3:
                printf("introduce la matrícula: \n");
                scanf("%s", &mat);
                imprimir(taller, mat);
                break;
            case 4:
                ordenar(taller);
                printf("Hecho.\n");
                break;
            case 5:
                printf("Adios.\n");
                break;
            default:
                printf("Por favor, elige:\n");
        }
    }


    return EXIT_SUCCESS;
}
