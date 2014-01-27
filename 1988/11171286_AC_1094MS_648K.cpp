#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int p, fa[30005], r[30005], top[30005];

void makeset(int n){
	for (int i = 0; i<30002; i++) {
		fa[i] = i;
		r[i] = 1;
		top[i] = 0;
	}
}

int find(int a){
	int tmp;
	if (a==fa[a]) return a;
	tmp = fa[a];
	fa[a] = find(tmp);
	top[a]+=top[tmp];
	return fa[a];
}

void unionset(int a, int b) {
	int xa = find(a);
	int xb = find(b);
	if (xa==xb) return;
	fa[xb] = xa;
	top[xb]+= r[xa];
	r[xa] += r[xb];
}

int main() {
	cin >> p;
	int x, y;
	char operation;
	makeset(30004);
	while (p--) {
		cin >> operation;
		if (operation=='M') {
			cin >>x>>y;
			unionset(x,y);
		}
		else {
			cin >>x;
			cout << (r[find(x)]-top[x]-1)<<endl;
		}
		
	}
	system("PAUSE");
	return 0;
}