#include <iostream>
#include <math.h>

using namespace std;

int main () {
	int n, b, d, h, j;
	string x, y;
	cin >> n;

	for (int k = 0; k < n; k++){
		cin >> x;
		cin >> y;
		cout << "Case " << k+1 << ":" << endl;
		switch (y){
			case "bin":
				d = 0;
				for (j = 0; j < x.size(); j++){
					if (x[j] == '1') d += exp(1,2);
					else d += exp(0,2);
				}
				cout << d << " dec" << endl;
			case "dec":
				d = 0;
				
				int aux = d;
				while (x)
			case "hex":
				
		}
		
		//cout << x << " " << y << endl;
	}

	return 0;
}
