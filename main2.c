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

typedef struct producto_t {
    char *tipo;
    char *nombre;
    float precio;
    int cantidad;
} producto_t;

int main(int argc, char **argv) {
    int opc = 0, j = 0;
    char *input = NULL;
    char *token = NULL;
    producto_t *producto = (producto_t *) malloc(sizeof(producto_t) * (j + 1));
    do {
        printf("Menu:\n1.Introducir nuevo producto\n2.Mostrar productos\n3.Salir\n");
        scanf("%d", &opc);
        while (getchar() != '\n');
        switch (opc) {
            case 1:
                producto = (producto_t *) realloc(producto, sizeof(producto_t) * (j + 1));
                printf("Introduzca el tipo de producto, el nombre, el precio y la cantidad, en una sola línea y separados por el carácter “punto y coma” (;).\n");
                input = leelineaDinamica();
                token = strtok(input, ";");
                producto[j].tipo = token;
                for (int i = 0; i < 3; i++) { //while(producto[j].tipo!=NULL);
                    token = strtok(NULL, ";");
                    switch (i) {
                        case 0:
                            producto[j].nombre = token;
                            break;
                        case 1:
                            producto[j].precio = strtol(token, NULL, 10);
                            break;
                        case 2:
                            producto[j].cantidad = strtol(token, NULL, 10);
                            break;
                    }
                }
                j++;
                break;
            case 2:
                for (int i = 0; i < j; i++) {
                    printf("Producto %d:\nTipo: %s\nNombre: %s\nPrecio: %f\nCantidad: %d\n", i, producto[i].tipo,
                           producto[i].nombre, producto[i].precio, producto[i].cantidad);
                }
                break;
            case 3:
                printf("BYE\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while (opc != 3);
    for (int i = 0; i < j; i++) {
        free(producto[i].tipo);
        free(producto[i].nombre);
    }
    free(producto);
    return 0;
}