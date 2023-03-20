#include<stdio.h>
 
#define MAX 30002
 
static long long man[MAX];
static const unsigned moedas[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
 
int main(){
    float n;
 
	// contar o numero de combinacoes possiveis para pagar
    man[0] = 1;
    for(int i = 0; i < 11; ++i){
        for(int j = moedas[i]; j < MAX; ++j)
            man[j] += man[j - moedas[i]];
    }
 
    // leitura deve parar ao ler 0
    while(scanf("%f", &n) == 1 && n){
        unsigned int valor = (unsigned)((n + 0.001) * 100);
 
        // imprimir entrada e numero de maneiras justificado
        printf("%6.2f%17lld\n", n, man[valor]);
    }
    return 0;
}
