#include <stdio.h>

void inicializacao(int s[], int n) {
    int i;
    for(i = 0; i < n; i++)
        s[i] = 0;
}

int main() {
    int x[10], y[20];
    inicializacao(x, 10);
    inicializacao(y, 20);
    return 0;
}
