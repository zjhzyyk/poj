#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct edge {
	int to, next;
}e[40005];

int le[20005], n, ei, bal[20005], sum[20005], mmin;

void dfs(int x, int fa) {
	sum[x] = 1;
	int mmax = 0;
	for (int i = le[x]; i!=0; i = e[i].next) {
		if (e[i].to==fa) continue;
		dfs(e[i].to, x);
		sum[x]+=sum[e[i].to];
		if (sum[e[i].to] > mmax) mmax = sum[e[i].to];
	}
	bal[x] = max(n-sum[x], mmax);
	if (bal[x]==bal[mmin] && x<mmin) mmin = x;
	if (bal[x] < bal[mmin]) mmin = x;
}

int main(){
	int cn, a, b;
	cin >> cn;
	while (cn--) {
		cin >> n;
		ei = 1;
		mmin = 0;
		memset(le, 0, sizeof(le));
		memset(bal, 0, sizeof(bal));
		memset(sum, 0, sizeof(sum));
		bal[0] = n+10;
		for (int i = 1; i<n; i++) {
			cin >> a >> b;
			e[ei].to = b;
			e[ei].next = le[a];
			le[a] = ei++;
			e[ei].to = a;
			e[ei].next = le[b];
			le[b] = ei++;
		}
		dfs(1, 0);
		cout << mmin << " " << bal[mmin] << endl;
	}
	//system("PAUSE");
	return 0;
}