#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct autor_t {
    char *autor;
    int numl;
    char **libs;
} autor_t;

typedef struct genero_t {
    enum generos{
        novelas,
        didacticos,
        cronicas
    }generos;
} genero_t;

typedef struct libro_t {
    char *titulo;
    autor_t *autor;
    genero_t genero;
} libro_t;


int main(int argc, char **argv) {
    FILE *f;
    char *nombre = argv[1];
    int numAutores, numLibros;
    autor_t *autores;
    libro_t *libros;
    if (nombre == NULL) {
        printf("fail\n");
    }

    f = fopen(nombre, "r+");




    return 0;
}
