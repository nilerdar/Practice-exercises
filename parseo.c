#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum tiposDatos_e {
    c = 0,
    i = 1,
    f = 2
} tiposDatos_e;

int getInt(char *arg, int gc, char **gv) {
    char *token = NULL;
    int num = 0;
    token = strtok(gv[1], "=");
    if (!strcmp(arg, token)) {
        token = strtok(NULL, "=");
        num = strtol(token, NULL, 10);
        return num;
    }
    return 0;
}

tiposDatos_e getTipo(char *arg, int gc, char **gv) {
    char *token = NULL;
    tiposDatos_e tipo;
    token = strtok(gv[2], "=");
    if (!strcmp(arg, token)) {
        token = strtok(NULL, "=");
        char a = *token;
        switch (a) {
            case 'c':
                tipo = c;
                break;
            case 'i':
                tipo = i;
                break;
            case 'f':
                tipo = f;
                break;
        }
        return tipo;
    }
    return 0;
}

char *getStr(char *arg, int gc, char **gv) {
    char *token = NULL;
    char *datos = NULL;
    token = strtok(gv[3], "=");
    if (!strcmp(arg, token)) {
        token = strtok(NULL, "=");
        datos = token;
        return datos;
    }
    return 0;
}

void printDc(char *datos, int num){
    char *token=NULL;
    char lista[num];
    token = strtok(datos,",");
    lista[0]= *token;
    printf("Dato 0: %c\n",lista[0]);
    for (int j = 1; j <num ; j++) {
        token= strtok(NULL,",");
        lista[j]=*token;
        printf("Dato %d: %c\n",j, lista[j]);
    }
}

void printI(char *datos, int num){
    char *token=NULL;
    int lista[num];
    token = strtok(datos,",");
    lista[0] = strtol(token, NULL, 10);
    printf("Dato 0: %d\n",lista[0]);
    for (int j = 1; j < num; j++) {
        token= strtok(NULL, ",");
        lista[j]= strtol(token, NULL,10);
        printf("Dato %d: %d\n", j,lista[j]);
    }
}

void printF(char *datos, int num){
    char *token=NULL;
    float lista[num];
    token = strtok(datos,",");
    lista[0] = strtol(token, NULL, 10);
    printf("Dato 0: %f\n",lista[0]);
    for (int j = 1; j < num; j++) {
        token= strtok(NULL, ",");
        lista[j]= strtol(token, NULL,10);
        printf("Dato %d: %f\n", j,lista[j]);
    }
}

int main(int argc, char **argv) {
    int cant = 0;
    tiposDatos_e tipo = 0;
    char *lista;
    cant = getInt("--numDatos", argc, argv);
    tipo = getTipo("--tipoDatos", argc, argv);
    lista = getStr("--listaDatos", argc, argv);

    switch (tipo) {
        case c:
            printDc(lista,cant);
            break;
        case i:
            printI(lista,cant);
            break;
        case f:
            printF(lista,cant);
            break;
    }
    return 0;
}