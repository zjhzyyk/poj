#include <iostream>
#include <string>
using namespace std;

struct edge{
	int f, t;
	double d;
}e[1000];

double dist[35];
string curs[35];

int n;

int index(string& str){
	for (int i = 0; i<n; i++)
		if (curs[i]==str) return i;
	return 0;
}

int main(){
	int ei, m, cn = 1;
	string first, second;
	bool flag;
	double rate;
	while (cin >> n && n) {
		ei = 0;
		for (int i = 0; i<n; i++)
			cin >> curs[i];
		cin >> m;
		for (int i = 0; i<m; i++) {
			cin >> first >> rate >> second;
			e[ei].f = index(first);
			e[ei].t = index(second);
			e[ei].d = rate;
			ei++;
		}

		for (int i = 0; i<n+2; i++) dist[i] = 0;
		dist[0] = 1;
		for (int i = 1; i<n; i++) {
			flag = false;
			for (int j = 0; j<ei; j++) {
				if (dist[e[j].f]*e[j].d>dist[e[j].t]) {
					flag = true;
					dist[e[j].t] = dist[e[j].f]*e[j].d;
				}
			}
			if (!flag)
				break;
		}
		flag = false;
		for (int j = 0; j<ei; j++) {
			if (dist[e[j].f]*e[j].d>dist[e[j].t]) {
				flag = true;
				break;
			}
		}
		if (flag) cout << "Case " << cn++ << ": Yes" << endl;
		else cout << "Case " << cn++ << ": No" << endl;
	}
	return 0;
}
