#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, en, p[2005], r[2005], m = 0, ln;
bool done;

struct edge {
	int a, b, d;
} e[10005];

void makeset(int x) {
	for (int i = 0; i < x; i++) {
		p[i] = i;
		r[i] = 1;
	}
}

int find(int x) {
	int tmp;
	if (x == p[x])
		return x;
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
	if (x == y)
		return;
	if (r[x] <= r[y]) {
		p[x] = y;
		r[y] += r[x];
	} else {
		p[y] = x;
		r[x] += r[y];
	}
	if (dist > m) m = dist;
	if (r[x] == n || r[y] == n)
		done = true;
}

class cmp {
public:
	bool operator()(const int& a, const int& b) const {
		return e[a].d > e[b].d;
	}
};

int main() {
	priority_queue<int, vector<int>, cmp> pq;
	scanf("%d %d", &n, &ln);
	en = 0;
	done = false;
	makeset(n);
	while (ln--) {
		scanf("%d %d %d", &e[en].a, &e[en].b, &e[en].d);
		pq.push(en++);
	}
	while (!done && !pq.empty()) {
		int tmp = pq.top();
		pq.pop();
		unionset(tmp);
	}
	printf("%d", m);
	return 0;
}
