#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cuenta(FILE *f, int *histo) {
    char c[5];
    int ret;
    while (!feof(f)){
        fgets(c,6,f);
        if (c[0]=='1' && c[1]=='0'){
            histo[10]++;
        } else{
            histo[c[0]-48]++;
        }
        /*switch (c[0]) {
            case '0':
                histo[0]++;
                break;
            case '1':
                if (c[1]=='0'){
                    histo[10]++;
                }else histo[1]++;
                break;
            case '2':
                histo[2]++;
                break;
            case '3':
                histo[3]++;
                break;
            case '4':
                histo[4]++;
                break;
            case '6':
                histo[6]++;
                break;
            case '8':
                histo[8]++;
                break;
            case '9':
                histo[9]++;
                break;
            case '7':
                histo[7]++;
                break;
            case '5':
                histo[5]++;
                break;
        }*/
    }
}

void escribe(FILE* f, int *hist){
    for (int i = 0; i < 11; i++) {
        fprintf(f,"Notas %d: ",i);
        for (int j = 0; j < hist[i]; ++j) {
            fprintf(f,"*");
        }
        fprintf(f,"\n");
    }
}


int main(int argc, char **argv) {
    FILE *notas = NULL;
    FILE *notasHISTO = NULL;
    const char *nombreF = argv[1];
    int hist[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};

    notas = fopen(nombreF, "r");
    cuenta(notas, hist);
    fclose(notas);
    for (int i = 0; i < 11; i++) {
        printf("%d: %d\n",i,hist[i]);
    }

    notasHISTO = fopen("histo.txt","w+");
    escribe(notasHISTO,hist);
    fclose(notasHISTO);

    return 0;
}
