#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMEROS 49        /* Total de numeros do jogo */
#define MIN_APOSTA 6      /* Aposta minima = 6 numeros */
#define NUM_LIN 7         /* Numero de numeros apresentados por linha no volante */

/* Declaracao das funcoes */
void inicializacaoAleatoria();
void inicializacaoNula(int v[NUMEROS]);
int lerNumerosAposta();
void geraAleatoriamente(int v[], int n);
void apresentar(int res[]);

/* Inicia o gerador de numeros aleatorios com um numero que depende da hora que se executa a função */
void inicializacaoAleatoria() {
    long ultime;
    time(&ultime);
    srand((unsigned) ultime);
}

/* Inicializa com ZERO o vetor de controle dos numeros selecionados */
void inicializacaoNula(int v[]) {
    int i;
    for(i = 0; i < NUMEROS; i++)
        v[i] = 0;
}

/* Le o numero de numeros a apostar. Aceita valores entre MIN_APOSTA e NUMEROS */
/* Aceita o valor ZERO para se indicar que quer terminar o programa */
int lerNumerosAposta() {
    int n;
    do {
        printf("Quantos numeros quer apostar (0 - Terminar): ");
        scanf("%d", &n);
    }
    while ((n < MIN_APOSTA || n > NUMEROS) && n!= 0);
    return n;
}

/* Gera n numeros aleatorios e coloca a respectiva posição do vetor com o valor 1, que indica que esse numero foi selecionado */
void geraAleatoriamente(int v[], int n) {
    int i, indice;
    for(i = 1; i <= n; i++) {
        indice = rand()%NUMEROS;   /* Devolve numero aleatorio entre 0 e NUMERO - 1 */
        if(v[indice] == 0)         /* Nao foi selecionado */
            v[indice] = 1;
        else                       /* Este numero ja tinha sido selecionado, logo decrementa-se o contador */
            i--;                   /* para voltar a calcular mais de uma vez o i-esimo numero aleatorio */
    }
}

/* Apresenta o formato do volante colocando XX nos numeros selecionados para a aposta */
void apresentar(int res[]) {
    int i;
    for(i = 0; i < NUMEROS; i++) {
        if(res[i] == 0)
            printf(" %2d", i + 1);
        else
            printf(" XX");
        if((i + 1) % NUM_LIN == 0)
            putchar('\n');
    }
    putchar('\n');
}

int main() {
    int vetor[NUMEROS];
    int n_numeros; /* Numero de numeros para jogar no jogo (6... 49) */

    inicializacaoAleatoria();
    while(1) {
        inicializacaoNula(vetor);
        if((n_numeros = lerNumerosAposta()) == 0)
            break;
        geraAleatoriamente(vetor, n_numeros); /* Gera os numeros a apostar */
        apresentar(vetor);
    }
    return 0;
}
