#include <iostream>
#include <cmath>

#define PACKSIZE 50

using namespace std;

int main (){
	unsigned int cas, pac;
	int x, y;
	unsigned short bestq, bestp, spare;
	// numero de casos
	cin >> cas;
	for (unsigned int casx = 0; casx < cas; casx++){
		// numero de pacotes do caso
		cin >> pac;
		// dados do caso (qtde e peso dos pacotes)
		unsigned short dados[pac][2];
		for (x = 0; x < pac; x++){
			cin >> dados[x][0];
			cin >> dados[x][1];
		}
		// agrupamento por forca bruta
		// ordernar por qtde
		unsigned short aux[1][2];
		for (x=0; x<pac; x++){
			for (y=x; y<pac; y++){
				if (dados[y][0] < dados[x][0]){
					aux[0][0]=dados[y][0];
					aux[0][1]=dados[y][1];
					dados[y][0]=dados[x][0];
					dados[y][1]=dados[x][1];
					dados[x][0]=aux[0][0];
					dados[x][1]=aux[0][1];
				}
			}
		}
		/*for (x = 0; x < pac; x++){
			for (y = 0; y < 2; y++){
				cout << dados[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		// tentar inserir pacotes no saco
		spare = pac; bestp = 0; bestq = 0;
		for (x = pac-1; x > 0; x--) {
			if (bestp+dados[x][1]<PACKSIZE) {
				bestp+=dados[x][1];
				bestq+=dados[x][0];
				spare--;
			}
		}
		// escrever resultado
		cout << bestq << " brinquedos" << endl;
		cout << "Peso: " << bestp << " kg" << endl;
		cout << "sobra(m) " << spare << " pacote(s)" << endl;
		cout << endl;
	}
	return 0;
}