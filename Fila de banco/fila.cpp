#include <iostream>
#include <math.h>

using namespace std;

int main () {
	int n, a, b, c, d, ways;
	int e;
	char fila[n];
	while (cin >> n && n){
		ways = 0;
		for(c = n-1; c >= 0; c--){
			for (d = 0; d < n; d++){
				fila[d]='z';
			}
			if (c+1 != n){
				fila[c+1]='z';
			}
			fila[c]='c';
			for(b = c-1; b >= 0; b--){
				if (b+1 != c){
					fila[b+1]='z';
				}
				fila[b]='b';
				for(a = b-1; a >= 0; a--){
					if (a+1 != b){
						fila[a+1]='z';
					}
					fila[a]='a';
					ways++;
					for (e = 0; e < n; e++){
						cout << fila[e];
					}
					cout << endl;
					if (a == 0){
						fila[a]='z';
					}
				}
			}
		}
		//ways = modf(ways,1000000009);
		cout << ways << endl;
	}
	return 0;
}
