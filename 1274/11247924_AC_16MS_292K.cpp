#include <iostream>
#include <cstring>
using namespace std;

int n,m, match, mat[410];
bool map[205][205], used[410];

bool find(int a){
	for(int i = 1; i<=m; i++) {
		if (map[a][i] && !used[i]) {
			used[i] = 1;
			if (mat[i]==0 || find(mat[i])) {
				mat[i] = a;
				return true;
			}
		}
	}
	return false;
}

void hungarian(){
	for (int i =1; i<=n; i++) {
		if (find(i))
			match++;
		memset(used, 0, sizeof(used));
	}
}

int main(){
	int a, b;
	while (cin >> n >> m) {
		match = 0;
		memset(map, 0, sizeof(map));
		memset(mat, 0, sizeof(mat));
		for(int i = 1; i<=n; i++) {
			cin >> a;
			while (a--) {
				cin >> b;
				map[i][b] = 1;
			}
		}
		hungarian();
		cout << match << endl;
	}
	//system("PAUSE");
	return 0;
}