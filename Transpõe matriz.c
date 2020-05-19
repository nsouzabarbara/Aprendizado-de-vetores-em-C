#include <stdio.h>
#define DIM 3 /* Para teste vamos usar o 3 */

float transpoe(int v[][DIM]);
void imprime(int v[][DIM]);
void preenche(int v[][DIM]);


/* Programa de teste */
int main() {
    int x[DIM][DIM];

    printf("Insira as entradas da matriz %d por %d: ", DIM, DIM);
    preenche(x);
    printf("MATRIZ INICIAL\n");
    imprime(x);
    transpoe(x);
    printf("DEPOIS DA TRANSPOSICAO\n");
    imprime(x);
    return 0;
}

float transpoe(int v[][DIM]) {
    int i, j, aux;
    for(i = 0; i < DIM; i++) {
        for(j = i + 1; j < DIM; j++) {
            aux = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = aux;
        }
    }
}

void imprime(int v[][DIM]) {
    int i, j;
    for(i = 0; i < DIM; i++) {
        for(j = 0; j < DIM; j++)
            printf("%d ", v[i][j]);
        putchar('\n');
    }
}

void preenche(int v[][DIM]) {
    int i,j;
    for(i = 0; i < DIM; i++) {
        for(j = 0; j < DIM; j++)
            scanf("%d", &v[i][j]);
    }
}
