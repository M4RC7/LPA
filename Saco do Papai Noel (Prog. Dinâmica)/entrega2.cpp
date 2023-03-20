#include <iostream>
#include <cmath>

#define PACKSIZE 50

using namespace std;

int power (int b, int exp) {
	int result;
	if (exp == 0){
		return 1;
	} else {
		result = b;
		for (int x = 1; x < exp; x++){
			result*=b;
		}
		return result;
	}
}

int main (){
	unsigned int cas, pac, aux;
	int x, y;
	/*unsigned int bestq, bestp, bests, auxq, auxp, spare, power2;*/
	// numero de casos
	cin >> cas;
	for (short casx = 0; casx < cas; casx++){
		// numero de pacotes do caso
		cin >> pac;
		// dados do caso (qtde e peso dos pacotes)
		unsigned short dados[pac][2];
		for (x = 0; x < pac; x++){
			cin >> dados[x][0];
			cin >> dados[x][1];
		}
		// agrupamento por problema da mochila
		// qtde = value, peso = size
		unsigned short cost[PACKSIZE+1];
		short best[PACKSIZE+1];
		for (x = 0; x < pac; x++){
			cost[x] = 0;
		} for (x = 0; x < pac; x++){
			best[x] = -1;
		}
		for (y = 0; y < pac; y++) {
			for (x = 1; x <= PACKSIZE; x++) {
				if (x >= dados[y][1]) {
					if (cost[x] < cost[x-dados[y][1]] + dados[y][0]) {
						cost[x] = cost[x-dados[y][1]] + dados[y][0];
						best[x]=y;
					}
				}
			}
		}
		
		// escrever resultado
		cout << bestq << " brinquedos" << endl;
		cout << "Peso: " << bestp << " kg" << endl;
		cout << "sobra(m) " << bests << " pacote(s)" << endl;
		cout << endl;
	}
	
	return 0;
}