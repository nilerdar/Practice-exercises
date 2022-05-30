#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leelineaDinamica() {
    char *cad = NULL;
    char c = 0;
    int cadSize = 0;
    do {
        c = getchar();
        cad = (char *) realloc(cad, sizeof(char) * cadSize + 1);
        cad[cadSize] = c;
        cadSize++;
    } while (c != '\n');

    cad[cadSize - 1] = '\0';
    return cad;
}

typedef struct atleta_t {
    char *NombreAtleta;
    int IdAtleta, Puntuacion, Estado;
} atleta_t;

int main(int argc, char **argv) {
    int opc = 0, j = 0, aux = 0, error = 1, salir = 0, igual = 0;
    atleta_t *atleta = (atleta_t *) malloc(sizeof(atleta_t) * (j + 1));
    do {
        printf("Menu:\n1.Introducir nuevo atleta\n2.Borrar atleta\n3.Mostrar atletas\n4.Mostrar activos\n5.Salir\n");
        scanf("%d", &opc);
        while (getchar() != '\n');
        switch (opc) {
            case 1:
                atleta = (atleta_t *) realloc(atleta, sizeof(atleta_t) * (j + 1));
                printf("Introduzca atleta\nIntroduzca nombre y apellidos\n");
                atleta[j].NombreAtleta = leelineaDinamica();
                printf("Dorsal:\n");
                scanf("%d", &aux);
                if (j != 0) {
                    salir=0;
                    do {

                        for (int i = 0; i < j; i++) {
                            if (atleta[i].IdAtleta == aux) {
                                igual = 1;
                            }
                        }
                        if (igual == 0) {
                            printf("todo bien");
                            atleta[j].IdAtleta = aux;
                            salir = 1;
                        }
                        if (igual == 1) {
                            printf("ERROR mete otro\n");
                            scanf("%d",&aux);
                            igual = 0;
                        }
                    } while (!salir);
                    /*while (!salir){
                        if (atleta[i].IdAtleta==aux){
                            igual = 1;
                        }
                        if (igual){
                            printf("ese ya existe\n");
                        }
                        if (!igual){
                            salir = 1;
                        }

                    }*/
                    /*do {
                        for (int i = 0; i < j; i++) {
                            if (atleta[i].IdAtleta == aux) {
                                igual = 1;
                            }
                        }
                        if (igual){
                            printf("No valido introduzca otro:\n");
                            scanf("%d", &aux);
                            while (getchar() != '\n');
                        } else{
                            printf("entra %d",aux);
                            atleta[j].IdAtleta = aux;
                            printf(" %d",atleta[j].IdAtleta);
                            salir = 1;
                        }
                        igual=0;
                    } while (!salir);*/
                } else{
                    atleta[j].IdAtleta=aux;
                }

                do {
                    printf("Puntuacion:\n");
                    scanf("%d", &aux);
                    while (getchar() != '\n');
                } while (aux > 100 || aux < 0);
                atleta[j].Puntuacion = aux;
                atleta[j].Estado = 1;
                j++;
                break;
            case 2:
                printf("Dame dorsal\n");
                scanf("%d", &aux);
                for (int i = 0; i < j; i++) {
                    if (atleta[i].IdAtleta == aux) {
                        atleta[i].Estado = 0;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < j; i++) {
                    printf("Atleta:\nNombre: %s\nDorsal: %d\nPunt: %d\n", atleta[i].NombreAtleta, atleta[i].IdAtleta,
                           atleta[i].Puntuacion);
                }
                break;
            case 4:
                for (int i = 0; i < j; i++) {
                    if (atleta[i].Estado == 1) {
                        printf("Atleta:\nNombre: %s\nDorsal: %d\nPunt: %d\n", atleta[i].NombreAtleta,
                               atleta[i].IdAtleta, atleta[i].Puntuacion);
                    }
                }
                break;
            case 5:
                printf("BYE");
        }
    } while (opc != 5);
    for (int i = 0; i < j; i++) {
        free(atleta[i].NombreAtleta);
    }
    free(atleta);
    return 0;
}