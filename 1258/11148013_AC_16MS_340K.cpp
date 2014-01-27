#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, map[102][102], en, p[102], r[102], md;
bool done;

struct edge {
	int a, b, d;
}e[10000];

void makeset(int x) {
	for (int i = 0; i<x; i++) {
		p[i] = i;
		r[i] = 1;
	}
}

int find(int x) {
	int tmp;
	if (x==p[x]) return x;
	tmp = p[x];
	p[x] = find(tmp);
	return p[x];
}

void unionset(int c) {
	int x = e[c].a;
	int y = e[c].b;
	int dist = e[c].d;
	x = find(x);
	y = find(y);
	if (x==y) return;
	if (r[x]<=r[y]) {
		p[x] = y;
		r[y]+=r[x];
	}
	else {
		p[y] = x;
		r[x]+=r[y];
	}
	md += dist;
	if (r[x] == n || r[y]==n) done = true;
}

class cmp {
public:
	bool operator() (const int& a, const int& b) const {
		return e[a].d > e[b].d;
	}
};

int main() {
	priority_queue<int, vector<int>, cmp> pq;
	while (scanf("%d", &n)!=EOF) {
		md = 0;
		en = 0;
		done = false;
		makeset(n);
		for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) {
			if (j<i) {
				scanf("%*d");
				continue;
			}
			scanf("%d", &map[i][j]);
			if (map[i][j]) {
			e[en].a = i;e[en].b = j;
			e[en].d = map[i][j];
			pq.push(en++);
			}
		}
		while (!done && !pq.empty()){
			int tmp = pq.top();
			pq.pop();
			unionset(tmp);
		}
		printf("%d\n", md);
		while (!pq.empty()) pq.pop();
	}
	return 0;
}