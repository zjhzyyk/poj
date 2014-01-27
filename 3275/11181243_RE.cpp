#include <iostream>
#include <cstring>
using namespace std;

bool conn[1002][1002];
int fle[1003], tle[1003], fei, tei;

struct edge {
	int a, n;
}from[20000], to[20000];

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
	memset(conn, 0, sizeof(conn));
	memset(fle, 0, sizeof(fle));
	memset(tle, 0, sizeof(tle));
	int n, m, x, y ,f ,t, cnt = 0;
	fei = 1; tei = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++)  {
		cin >> x >> y;
		addfrom(x, y);
		addto(x, y);
	}
	for (int k = 1; k<=n; k++)
		for (int i = fle[k]; i!=0; i = from[i].n) {
			f = from[i].a;
			conn[k][f] = conn[f][k] = 1;
			for (int j = tle[k]; j!=0; j = to[j].n) {
				t = to[j].a;
				conn[k][t] = conn[t][k] = 1;
				conn[f][t] = conn[t][f] = 1;
				addto(f, t);
				addfrom(f, t);
			}
		}
	for (int i = 1; i<n; i++) for (int j= i+1; j<=n; j++) if(conn[i][j]) cnt++;
	cout << n*(n-1)/2-cnt << endl;
	//system("PAUSE");
}