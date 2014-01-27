#include <iostream>
#include <cstring>
using namespace std;

int n, le[1005], ei, ans[1002];
bool vis[1003], flag;
char w[1003][2];
char words[1003][21];

struct edge {
	int to, next;
}e[1000005];

void addedge(int a, int b) {
	e[ei].to = b;
	e[ei].next = le[a];
	le[a] = ei++;
}

void dfs(int x, int cnt) {
	vis[x] = 1;
	int to;
	if (cnt == n) {
		flag = 1;
		ans[n] = x;
		return;
	}
	for (int i = le[x]; i!=0; i = e[i].next) {
		to = e[i].to;
		if (!vis[to]) dfs(to, cnt+1);
		if (flag) {
			ans[cnt] = x;
			return;
		}
	}
	vis[x] = 0;
}

int main() {
	int cn;
	cin >> cn;
	while (cn--){
		cin >> n;
		ei = 1;
		flag = false;
		memset(le, 0, sizeof(le));
		for (int i =1; i<=n; i++) {
			cin >> words[i];
			w[i][0] = words[i][0];
			w[i][1] = words[i][strlen(words[i])-1];
			for (int j  = 1; j<i; j++) {
				if (w[j][0] == w[i][1]) addedge(i, j);
				if (w[j][1] == w[i][0]) addedge(j, i);
			}
		}
		for (int i = 1; i<=n; i++) {
			dfs(i, 1);
			if (flag) {
				ans[1] = i;
				break;
			}
		}
		if (flag) {
			for(int i = 1; i<=n; i++) {
				cout << words[ans[i]];
				if (i!=n) cout << ".";
			}
			cout << endl;
		}
		else
			cout <<"***"<<endl;
	}
	//system("PAUSE");
	return 0;
}
