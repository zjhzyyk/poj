#include <iostream>
using namespace std;

struct edge{
	int f, t, d;
}e[5210];

int dist[510];

int main(){
	int f,n,m,w,s,ex,t, ei;
	bool flag;
	cin >> f;
	while (f--) {
		ei = 0;
		cin >> n >> m >> w;
		for (int i = 0; i<m; i++) {
			cin >> s >> ex >> t;
			e[ei].f = s;
			e[ei].t = ex;
			e[ei++].d = t;
			e[ei].f = ex;
			e[ei].t = s;
			e[ei++].d = t;
		}
		for (int i = 0; i<w; i++) {
			cin >> s >> ex >> t;
			e[ei].f = s;
			e[ei].t = ex;
			e[ei++].d = -t;
		}
		for (int i = 0; i<n+2; i++) dist[i] = 0x7fffffff;
		dist[1] = 0;
		for (int i = 1; i<n; i++) {
			flag = false;
			for (int j = 0; j<ei; j++) {
				if (dist[e[j].f]+e[j].d<dist[e[j].t]) {
					flag = true;
					dist[e[j].t] = dist[e[j].f]+e[j].d;
				}
			}
			if (!flag)
				break;
		}
		flag = false;
		for (int j = 0; j<ei; j++) {
			if (dist[e[j].f]+e[j].d<dist[e[j].t]) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
