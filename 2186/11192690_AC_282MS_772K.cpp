#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ei, le[10003],a,b, dfn[10003], low[10003], id[10003], sta[10003], top, idx, scnt;
bool insta[10003], out[10003];

struct edge {
	int to, next;
}e[50004];

void tarjan(int x) {
	insta[x] = 1; sta[top++] = x;
	low[x] = dfn[x] = ++idx;
	int v, tmp;
	for (int i = le[x]; i!=0; i = e[i].next) {
		v = e[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if (insta[v] && dfn[v]<low[x]) low[x] = dfn[v];
	}
	if (low[x] == dfn[x]) {
		scnt++;
		do {
			tmp = sta[--top];
			insta[tmp] = 0;
			id[tmp] = scnt;
		}while(tmp!=x);
	}
}

int main()
{
	memset(le, 0, sizeof(le));
	memset(insta, 0, sizeof(insta));
	memset(out, 0, sizeof ( out));
	cin >> n >> m;
	ei = 1;
	top = 0;
	scnt = 0;
	idx=0;
	int ans = 0;
	int cnt = 0;
	int tmp;
	while (m--) {
		cin >> a >> b;
		e[ei].to = b;
		e[ei].next = le[a];
		le[a] = ei++;
	}
	for (int i = 1; i<=n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i<=n; i++) {
		if (out[id[i]]) continue;
		for (int j = le[i]; j!=0; j = e[j].next) {
			if (id[e[j].to]!=id[i]) {
				out[id[i]] = 1;
				cnt++;
				break;
			}
		}
	}
	if ((scnt-cnt)>1) cout << 0 << endl;
	else {
		for (int i = 1; i<=scnt ; i++) if (!out[i]) tmp = i;
		for (int i = 1; i<=n; i++) if (id[i]==tmp) ans++;
		cout << ans << endl;
	}
	//system("PAUSE");
	return 0;
}