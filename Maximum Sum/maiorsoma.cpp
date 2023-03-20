#include<iostream>
#include<cstring>
#include<algorithm>
#define maxN 105
using namespace std;
int N, m[maxN][maxN], x[maxN];

int encontrarMaior() {
    int somaAtual=x[0], soma=0;
	// obter a soma cumulativa dos elementos da coluna
    for (int l = 0; l < N; l++) {
        soma += x[l];
        somaAtual = max(soma, somaAtual);
        // descartar somas negativas
        if (soma < 0) soma = 0;
    }
    return somaAtual;
}

int main(void) {
	// ultimo valor a ser lido sera nulo
    while(cin >> N) {
		/* preencher matriz */
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> m[i][j];
        /* procurar maior soma e escreve-la na tela */ 
        int maiorSoma = -500;
		for (int i = 0; i < N; i++) {
			// inicializar vetor aux para somas
			memset(x, 0, sizeof(x));
			// obter a soma em cada coluna
			for (int j = i; j < N; j++) {
				for (int k = 0; k < N; k++) x[k] += m[j][k];
				// encontrar o retangulo com a maior soma
				maiorSoma = max(maiorSoma, encontrarMaior());
			}
		}
		// escrever resposta
		cout << maiorSoma << endl;
    }

    return 0;
}