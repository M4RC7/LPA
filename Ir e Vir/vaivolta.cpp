#include <iostream>
#include <vector>
using namespace std;

int main () {
	// n -> vertices: num. intersecoes; m -> arestas: num. ruas
	short n, m, v, w, p;
	// v, w -> duas intersecoes quaisquer; p -> indicador de tipo de sentido
	
	// ler ate ler um zero
	while (cin >> n && n && cin >> m && m){
		// inicializar grafo
		short graph[n][n];
		short x, y, z;
		for (x = 0; x < n; x++){
			for (y = 0; y < n; y++){
				graph[x][y]=0;
			}
		}
		// inserir ruas ligando intersecoes
		for (int i = 0; i < m; i++){
			cin >> v;
			cin >> w;
			graph[v-1][w-1]=1;
			cin >> p;
			if (p == 2){
				// inserir rua ligando intersecao reciprocamente
				graph[w-1][v-1]=1;
			}
			//debug v,w,p pos leituras
			/*cout << v << " " << w << " " << p << endl;*/
		}
		// debug grafo pos insercoes
		/*cout << endl;
		for (x = 0; x < n; x++){
			for (y = 0; y < n; y++){
				cout << graph[x][y] << " ";
			}
			cout << endl;
		}*/
		
		// verificar se requisito de conexidade* e satisfeito
		bool valid = true;
		short vaux[n];
		for (x = 0; x < n; x++){
			for (short k = 0; k < n; k++){
				vaux[k] = 0;
			}
			// inicializar pilhas de retorno
			vector<short> runz;
			vector<short> runy;
			runz.push_back(0);
			runy.push_back(0);
			// inicializar navegadores
			z = x; y = 0;
			// pilhas de retorno sao simultaneamente atualizadas
			while (! runz.empty()) {
				// pular posicoes da diagonal principal
				if (y != z && graph[z][y]){
					// explorar intersecao acessivel
					if (! vaux[y]){
						vaux[y]=1;
						runz.push_back(z);
						runy.push_back(y);
						z = y; y = 0;
					} else {
						if (y < n){
							// continuar procurando intersecoes acessiveis
							y++;
						} else {
							// retornar de posicao salva na pilha
							z = runz[runz.size() - 1];
							runz.pop_back();
							y = runy[runy.size() - 1];
							runy.pop_back();
						}
					}
				} else {
					if (y < n){
						// continuar procurando intersecoes acessiveis
						y++;
					} else {
						// retornar de posicao salva na pilha
						z = runz[runz.size() - 1];
						runz.pop_back();
						y = runy[runy.size() - 1];
						runy.pop_back();
					}
				}
			}
			for (short k = 0; k < n; k++){
				if (k != x && ! vaux[k]) {
					valid = false;
					break;
				}
			}
		}
		// informar validade
		if (valid) cout << "1" << endl;
		else cout << "0" << endl;
	}
	
	return 0;
}
// *chegar numa intersecao a partir de qualquer outra