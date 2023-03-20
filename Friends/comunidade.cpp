#include <iostream>
#include <vector>
using namespace std;

int main (){
	short cases, n, m, a, b;
	// n -> num. citizens; m -> num. pairs of friends
	// a, b -> friends of each other
	cin >> cases;
	for (short t = 0; t < cases; t++){
		// create graph
		cin >> n;
		short graph[n][n];
		short x, y, z;
		for (x = 0; x < n; x++){
			for (y = 0; y < n; y++){
				graph[x][y]=0;
			}
		}
		// insert friendship relations
		cin >> m;
		for (int i = 0; i < m; i++){
			cin >> a;
			cin >> b;
			graph[a-1][b-1]=1;
			graph[b-1][a-1]=1;
		}
		// seek greatest group of friends
		short high = 0, highaux;
		// create auxiliar array to verify whether a vertex was visited
		short vaux[n];
		for (short k = 0; k < n; k++){
			vaux[k] = 0;
		}
		for (x = 0; x < n; x++){
			// friend must have not been visited yet
			if (! vaux[x]){
				// mark friend as visited
				vaux[x]=1;
				highaux = 1;
				// create callback stacks
				vector<short> runz;
				vector<short> runy;
				runz.push_back(0);
				runy.push_back(0);
				// create seek pointers
				z = x; y = 0;
				// callback stacks are simultaneously updated
				while (! runz.empty()) {
					if (y != z && y < n && graph[z][y]){
						// explore accessible friend
						if (! vaux[y]){
							vaux[y]=1;
							highaux++;
							runz.push_back(z);
							runy.push_back(y);
							z = y; y = 0;
						} else {
							if (y < n){
								// continue seeking accessible friends
								y++;
							} else {
								// return from saved position on stack
								z = runz[runz.size() - 1];
								runz.pop_back();
								y = runy[runy.size() - 1];
								runy.pop_back();
							}
						}
					} else {
						if (y < n){
							// continue seeking accessible friends
							y++;
						} else {
							// return from saved position on stack
							z = runz[runz.size() - 1];
							runz.pop_back();
							y = runy[runy.size() - 1];
							runy.pop_back();
						}
					}
				}
				// update highest found value (if higher found)
				if (highaux > high) high = highaux;
			}
		}
		// report obtained value
		cout << high << endl;
	}
	return 0;
}