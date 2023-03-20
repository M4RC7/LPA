#include <iostream>
#include <vector>
using namespace std;

int main () {
	// n -> number of vertexes: cities
	unsigned short n, x, y, h, k, a, b;
	// e -> number of edges: letter sending agreements
	unsigned int e;
	
	/* program stops at reading zero */
	while (cin >> n && n && cin >> e && e){
		/* initialize graph */
		unsigned short map[n][n];
		for (a = 0; a < n; a++){
			for (b = 0; b < n; b++){
				map[a][b]=0;
			}
		}
		
		/* populate graph */
		for (a = 0; a < e; a++){
			cin >> x;
			cin >> y;
			// h -> number of hours to deliver
			// a letter between x and y
			cin >> h;
			map [x-1][y-1] = h;
		}
		
		/*for (a = 0; a < n; a++){
			for (b = 0; b < n; b++){
				cout << map[a][b] << " ";
			}
			cout << endl;
		}*/
		
		/* calculate letter ETA */
		bool rmap[n], arrvd;
		unsigned short eta;
		for (cin >> k; k > 0; k--){
			arrvd = false;
			eta = 0;
			// initialize aux which determines visitation
			for(a = 0; a < n; a++){
				rmap[a] = false;
			}
			cin >> x;
			cin >> y;
			// initialize callback stacks
			vector<unsigned short> runa;
			vector<unsigned short> runb;
			runa.push_back(0);
			runb.push_back(0);
			// initialize browsing parameters
			a = x-1; b = 0;
			// mark starting line as visited
			rmap[a]=true;
			// callback stacks are simultaneously updated
			while (! runa.empty()) {
				// skip main diagonal
				if (a != b && map[a][b]){
					// go to accessible line
					if (! rmap[b]){
						rmap[b] = true;
						// sum only if both lines are not in same country
						if (! map[b][a]){
							eta += map[a][b];	
						}
						// quit repetition if destination reached
						if (b == y-1){
							arrvd = true;
							cout << eta << "\n";
							break;
						}
						runa.push_back(a);
						runb.push_back(b);
						
						/*cout << "Arrived?" << arrvd << endl << "Insert:" << endl;
						for(auto i = runa.begin(); i != runa.end(); i++){
							cout << *i << " ";
						}
						cout << endl;
						for(auto j = runb.begin(); j != runb.end(); j++){
							cout << *j << " ";
						}
						cout << endl;*/
						
						a = b; b = 0;
					} else {
						if (b < n){
							// continue run through line
							b++;
						} else {
							// return from callback position
							a = runa[runa.size() - 1];
							runa.pop_back();
							b = runb[runb.size() - 1];
							runb.pop_back();
							
							/*cout << "Remove:" << endl;
							for(auto i = runa.begin(); i != runa.end(); i++){
								cout << *i << " ";
							}
							cout << endl;
							for(auto j = runb.begin(); j != runb.end(); j++){
								cout << *j << " ";
							}
							cout << endl;*/
							
							if (! map[b][a]){
								eta -= map[a][b];	
							}
						}
					}
				} else {
					if (b < n){
						// continue run through line
						b++;
					} else {
						// return from callback position
						a = runa[runa.size() - 1];
						runa.pop_back();
						b = runb[runb.size() - 1];
						runb.pop_back();
						
						/*cout << "Remove:" << endl;
						for(auto i = runa.begin(); i != runa.end(); i++){
							cout << *i << " ";
						}
						cout << endl;
						for(auto j = runb.begin(); j != runb.end(); j++){
							cout << *j << " ";
						}
						cout << endl;*/
						
						if (! map[b][a]){
							eta -= map[a][b];	
						}
					}
				}
			}
			if (! arrvd){
				cout << "Nao e possivel entregar a carta\n";
			}
		}
		// blank line indicates case transition
		cout << "\n";
	}
	
	return 0;
}