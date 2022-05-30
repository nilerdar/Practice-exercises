#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carton_t {
    int alt, anch;
    int **nums;
    int *marc;
} carton_t;

typedef struct usuario_t {
    carton_t carton;
    char *nombre;
} usuario_t;

char *leelineaDinamica() {
    char *cad = NULL;
    char c = 0;
    int cadsize = 0;
    do {
        c = getchar();
        cad = (char *) realloc(cad, sizeof(char) * (cadsize + 1));
        cad[cadsize] = c;
        cadsize++;
    } while (c != '\n');
    cad[cadsize - 1] = '\0';
    return cad;
}

int main(int argc, char **argv) {
    usuario_t *usuarios = (usuario_t *) malloc(sizeof(usuario_t) * 1);
    int j = 0;
    char opc;
    char *input = "1,2,3,4";
    char *token = NULL;
    int alt = strtol(argv[2], NULL, 10);
    int anch = strtol(argv[1], NULL, 10);
    do {
        printf("1-Introducir jugador\n2-Mostrar cartones\n3-Salir");
        scanf("%c", &opc);
        while (getchar() != '\n');
        switch (opc) {
            case '1':
                usuarios = realloc(usuarios, sizeof(usuario_t) * (j + 1));
                printf("Introduzca nombre y numeros\n");
                usuarios[j].nombre = leelineaDinamica();
                printf("Introduzca numeros:\n");

                token = strtok(input, ",");
                usuarios[j].carton.alt = alt;
                usuarios[j].carton.anch = anch;
               /* usuarios[j].carton.nums = malloc(sizeof(int *) * alt);
                for (int k = 0; k < alt; k++) {
                    usuarios[j].carton.nums = malloc(sizeof(int) * anch);
                }

                usuarios[j].carton.nums[0][0] = strtol(token, NULL, 10);
                for (int k = 0; k < alt; k++) {
                    for (int l = 0; l < anch; l++) {
                        if (k != 0 && l != 0) {
                            token = strtok(NULL, ",");
                            usuarios[j].carton.nums[k][l] = strtol(token, NULL, 10);
                        }
                    }
                }*/
                j++;
                break;
            case '2':
                for (int k = 0; k < j; k++) {
                    printf("Jugador %d: %s\n", k, usuarios[k].nombre);
                    printf("Carton:");
                    for (int l = 0; l < alt; l++) {
                        for (int m = 0; m < anch; m++) {
                            printf("%d ", usuarios[k].carton.nums[l][m]);
                        }
                    }
                    printf("\n");
                }
                break;

        }
    } while (opc != '3');
    for (int k = 0; k < j; k++) {
        free(usuarios[k].nombre);
    }
    free(input);
    free(usuarios);
    return 0;
}
