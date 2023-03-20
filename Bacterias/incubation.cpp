#include <iostream>

using namespace std;

int main () {
	int n, x, y, sum1, sum2;

	while (cin >> n && n){
		short cups[n];
		for (x = 0; x < 4; x++){
			cin >> cups[x];
		}
		while (x < n){
			sum1 = 0;
			sum2 = 0;
			for (y = x-4; y < x; y++){
				sum1 += cups[y];
			}
			cups[x] = sum1;
			sum1 += sum1;
			sum2 = sum1 - cups[x-4];
			/*for (int z = 0; z < n; z++){
				cout << cups[z] << " ";
			}	
			cout << endl;*/
			x++;
		}
		cout << sum2 << endl;
	}

	return 0;
}
