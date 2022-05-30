#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *leelineaDinamicaDeFichero(FILE *f) {
    char *cad = NULL;
    char c = '\0';
    int cadSize = 0;
    do {
        c = getc(f);
        cad = (char *) realloc(cad, sizeof(char) * (cadSize + 1));
        if (!feof(f))
            cad[cadSize] = c;
        else
            cad[cadSize] = '\0';
        cadSize++;
    } while (cad[cadSize - 1] != '\0' && cad[cadSize - 1] != '\n');

    cad[cadSize - 1] = '\0';
    return cad;
}

typedef struct producto_t {
    char *nombre;
    float precio;
    int cant, min, max, nec;
} producto_t;

int main(int argc, char **argv) {
    FILE *almacen = NULL;
    FILE *compra = NULL;
    int j = 0;
    char *nombreF = argv[1];
    char *input = NULL;
    char *token = NULL;
    producto_t *producto = (producto_t *) malloc(sizeof(producto_t) * (j + 1));

    almacen = fopen(nombreF, "r");
    while (!feof(almacen)) {
        producto = (producto_t *) realloc(producto, sizeof(producto_t) * (j + 1));
        input = leelineaDinamicaDeFichero(almacen);
        token = strtok(input, ";");
        producto[j].nombre = token;
        for (int i = 0; i <= 3; i++) {
            token = strtok(NULL, ";");
            switch (i) {
                case 0:
                    producto[j].precio = strtol(token, NULL, 10);
                    break;
                case 1:
                    producto[j].cant = strtol(token, NULL, 10);
                    break;
                case 2:
                    producto[j].min = strtol(token, NULL, 10);
                    break;
                case 3:
                    producto[j].max = strtol(token, NULL, 10);
                    break;
                default:
                    printf("ERROR\n");
            }
        }
        j++;
    }
    fclose(almacen);
    for (int i = 0; i < j; i++) {
        if (producto[i].min > producto[i].cant) {
            producto[i].nec = producto[i].max - producto[i].cant;
        }
    }
    compra = fopen("compra.txt", "w+");
    for (int i = 0; i < j; i++) {
        if (producto[i].nec != 0) {
            fprintf(compra, "%s;%f,%d\n", producto[i].nombre, producto[i].precio, producto[i].nec);
        }
    }
    fclose(compra);
    for (int i = 0; i < j; i++) {
        free(producto[i].nombre);
    }
    free(producto);
    return 0;
}