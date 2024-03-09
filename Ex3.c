#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct vet {
    int dim;
    int* vettore;
};

void lettura_vettore(const char* txt, struct vet* istanza_vettore)
{
    FILE* file;
    int i;
    char buf[10];

    file = fopen(txt, "r");
    if (file == NULL) {
        printf("Impossibile aprire il file %s.\n", txt);
        return;
    }

    fgets(buf, sizeof(buf), file);
    sscanf(buf, "%d", &istanza_vettore->dim);

    istanza_vettore->vettore = malloc(istanza_vettore->dim * sizeof(int));

    for (i = 0; i < istanza_vettore->dim; i++) {
        fgets(buf, sizeof(buf), file);
        sscanf(buf, "%d", &istanza_vettore->vettore[i]);
    }

    fclose(file);
}

void stampa(struct vet istanza_vettore) {
    int i;

    puts("\nvettore");
    for (i = 0; i < istanza_vettore.dim; i++) {

        printf("%d ", istanza_vettore.vettore[i]);
    }
}
void somma(struct vet istanza_vettore1, struct vet istanza_vettore2) {
    int i;

    puts("\nsomma");
    for (i = 0; i < istanza_vettore1.dim; i++) {

        printf("%d ", istanza_vettore1.vettore[i]+istanza_vettore2.vettore[i]);
    }


}
int main() {
    struct vet istanza_vettore1;
    struct vet istanza_vettore2;

    lettura_vettore("Vettori1.txt", &istanza_vettore1);
    lettura_vettore("Vettori2.txt", &istanza_vettore2);

    stampa(istanza_vettore1);
    stampa(istanza_vettore2);

    somma(istanza_vettore1, istanza_vettore2);

    free(istanza_vettore1.vettore);
    free(istanza_vettore2.vettore);

    return 0;
}
