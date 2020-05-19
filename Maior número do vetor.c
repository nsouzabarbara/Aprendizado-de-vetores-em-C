#include <stdio.h>

float maiorNumero(float v[], int n) {
    int i;
    float maior = v[0];
    for(i = 0; i < n; i++) {
        if(v[i] > maior)
            maior = v[i];
    }
    return maior;
}

/* Programa de teste */
int main() {
    int tam, i, n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tam);
    float v[tam];

    printf("Insira as entradas do vetor: ");
    for(i = 0; i < tam; i++)
        scanf("%f", &v[i]);
    printf("Insira o limite superior do intervalo de analise: ");
    scanf("%d", &n);
    printf("O maior dos %d primeiros elementos = %.2f\n", n, maiorNumero(v, n));
    return 0;
}
