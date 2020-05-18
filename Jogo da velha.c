#include <stdio.h>
#define DIM 3
#define ESPACO ' '

void inicializa(char s[][DIM]) { /* Omitir uma dimencao */
    int i, j;
    for(i = 0; i < DIM; i++) {
        for(j = 0; j < DIM; j++)
            s[i][j] = ESPACO;
    }
}

void mostra(char s[DIM][DIM]) { /* Ambas as dimencoes sa mostradas */
    int i, j;
    for(i = 0; i < DIM; i++) {
        for(j = 0; j < DIM; j++)
        printf("%c %c", s[i][j], j == DIM - 1 ? ESPACO : '|');
        if(i != DIM - 1)
            printf("\n--------\n");
    }
}

int main() {
    char velha[DIM][DIM];
    int posx, posy;
    char ch = '0'; /* Caractere para jogar */
    int n_jogadas = 0;

    inicializa(velha);
    while(1) { /* Laco infinito */
        mostra(velha);
        printf("\nIntroduza a posicao de jogo (linha e coluna): ");
        scanf("%d %d", &posx, &posy);
        posx -= 1; posy -= 1; /* Pois os indices do vetor comecam em 0 */
        if(velha[posx][posy] == ESPACO) { /* Casa livre */
            velha[posx][posy] = ch;
            ch = (ch == '0') ? 'X' : '0';
            n_jogadas++;
        }
        else
            printf("Posicao ja ocupada\nJogue novamente!\n");
        if(n_jogadas == DIM * DIM)
        break; /* Acaba o programa */
    }
    mostra(velha);
    return 0;
}
