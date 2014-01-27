#include <iostream>
#include <cstring>
using namespace std;

bool g[1002][1002];
int fle[1002], tle[1002], fei, tei;

struct edge {
	int a, n;
}from[1000002], to[1000002];

void addfrom(int a, int b) {
	from[fei].a = a;
	from[fei].n = fle[b];
	fle[b] = fei++;
}

void addto(int a, int b) {
	to[tei].a = b;
	to[tei].n = tle[a];
	tle[a] = tei++;
}

int main() {
	memset(g, 0, sizeof(g));
	memset(fle, 0, sizeof(fle));
	memset(tle, 0, sizeof(tle));
	int n, m, x, y ,f ,t, cnt = 0;
	fei = 1; tei = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++)  {
		cin >> x >> y;
		if (!g[x][y]) {
			g[x][y] = 1;
			cnt++;
			addfrom(x, y);
			addto(x, y);
		}
	}
	for (int k = 1; k<=n; k++)
		for (int i = fle[k]; i!=0; i = from[i].n) {
			f = from[i].a;
			for (int j = tle[k]; j!=0; j = to[j].n) {
				t = to[j].a;
				if (!g[f][t]) {
					g[f][t] = 1;
					cnt++;
					addto(f, t);
					addfrom(f, t);
				}
			}
		}
	cout << n*(n-1)/2-cnt << endl;
	//system("PAUSE");
}