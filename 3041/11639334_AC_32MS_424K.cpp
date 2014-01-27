#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n,k;
bool map[505][505];
int match, mat[505], used[505];

bool find(int a){
	for(int i = 1; i<=n; i++) {
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
	cin >> n >> k;
	int r,c;
	match = 0;
	for (int i =0; i<k; i++) {
		cin >> r >> c;
		map[r][c] = 1;
	}
	hungarian();
	cout << match;
	return 0;
}
