#include <stdio.h>
#define DIM 3
#define ESPACO ' '

void inicializa(char s[][DIM]);
void mostra(char s[][DIM]);
int linha(char v[], char c);
int coluna(char g[][DIM], int col, char ch);
int diagonal(char g[][DIM], char ch);
int ganhou(char g[][DIM], char ch);

/* Inicia o tabuleiro */
void inicializa(char s[][DIM]) { /* Omitir uma dimencao */
    int i, j;
    for(i = 0; i < DIM; i++) {
        for(j = 0; j < DIM; j++)
            s[i][j] = ESPACO;
    }
}

/* Mostra o aspecto do tabuleiro */
void mostra(char s[DIM][DIM]) { /* Ambas as dimencoes sao mostradas */
    int i, j;
    for(i = 0; i < DIM; i++) {
        for(j = 0; j < DIM; j++)
        printf("%c %c", s[i][j], j == DIM - 1 ? ESPACO : '|');
        if(i != DIM - 1)
            printf("\n--------\n");
    }
}

/* Verifica de a n-esima linha esta preenchida com o char c */
int linha(char v[], char c) {
    return v[0] == v[1] && v[1] == v[2] && v[0] == c;
}

/* Verifica se a coluna col esta toda preenchida com o char ch */
int coluna(char g[][DIM], int col, char ch) {
    return g[0][col] == g[1][col] && g[1][col] == g[2][col] && g[0][col] == ch;
}

/* Verifica se alguma das diagonais esta preencida totalmente com o char ch */
int diagonal(char g[][DIM], char ch) {
    return((g[0][0] == g[1][1]) && (g[1][1] == g[2][2]) && (g[0][0] == ch) ||
           (g[0][2] == g[1][1]) && (g[1][1] == g[2][0]) && (g[0][2] == ch));
}

/* Verifica se o jogador do caractere ch ganhou o jogo */
int ganhou(char g[][DIM], char ch) {
    if(linha(g[0], ch) || linha(g[1], ch) || linha(g[2], ch))
        return 1;
    if(coluna(g, 0, ch) || coluna(g, 1, ch) || coluna(g, 2, ch))
        return 1;
    if(diagonal(g, ch))
        return 1;
    return 0; /* Nao ganhou o jogo */
}

int main() {
    char velha[DIM][DIM];
    int posx, posy;
    char ch = '0'; /* Caractere para jogar */
    int n_jogadas = 0;

    inicializa(velha);
    while(1) { /* Laco infinito */
        mostra(velha);
        printf("\n\nIntroduza a posicao de jogo (linha e coluna): ");
        scanf("%d %d", &posx, &posy);
        if(posx > DIM || posy > DIM) {
            printf("\n\n**** Valores Invalidos ****\n\n");
            continue; /* Proxima iteracao */
        }
        posx--; posy--; /* Pois os indices do vetor comecam em ZERO */
        if(velha[posx][posy] == ESPACO) { /* Casa livre */
            velha[posx][posy] = ch;
            ch = (ch == '0') ? 'X' : '0';
            n_jogadas++;
            if (ganhou(velha, ch)) { /* Basta verificar o jogador corrente */
                printf("\n\n**** Ganhou o Jogador %c ****\n\n", ch);
                break;
            }
        }
        else
            printf("Posicao ja ocupada\nJogue novamente!\n");
        if(n_jogadas == DIM * DIM) {
            printf("\n\n**** EMPATE TECNICO ****\n\n");
            break; /* Acaba o laco */
        }
    }
    mostra(velha);
    return 0;
}
