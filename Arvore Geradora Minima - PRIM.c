/*PRIM*/
#include <stdio.h>
#define INF 100
#define TAM 6

int prim(int G[TAM][TAM]) {
    int i, u;
    int U[TAM], d[TAM];  // inicialmente nenhum vértice está em U

    for (i = 0; i < TAM; i++) {
        U[i] = 0; // vetor de vertices
        d[i] = INF; // vetor de arestas
    }

    d[0] = 0; // iniciará montagem a partir do vértice 0

    for (i = 0; i < TAM; i++) {
        int menor = INF, j;   // seleciona vértice u de menor aresta

        for (j = 0; j < TAM; j++) {
            if (U[j] == 0 && d[j] < menor) {
                menor = d[j];
                u = j;
            }
        }

        U[u] = 1; // incorpora vértice u ao conjunto U

        for (j = 0; j < TAM; j++) {
            // atualiza distância de todos os vértices adjacentes a u
            if (U[j] == 0 && G[u][j] < d[j]) {
                d[j] = G[u][j];
            }
        }
    }

    int soma = 0;
    for (i = 0; i < TAM; i++) {
        soma += d[i];
    }

    return soma;
}


void escreve(int matriz[TAM][TAM]){
    //Exibir a matriz
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            printf("%4.3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matriz[6][6] = {
    {0, 2, 5, 2, 3, INF},
    {2, INF, INF, 0, INF, INF},
    {5, INF, 0, 1, 6, INF},
    {2, INF, 1, 0, 4, 8},
    {3, INF, 6, 4, 0, INF},
    {INF, INF, INF, 8, INF, 0}
};
    
    escreve(matriz);
    int a = prim(matriz);
    
    printf("Soma: %d", a);

	return 0;
}