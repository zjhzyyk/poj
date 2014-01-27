#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int r = -1, f, t, cn = 0, node,en=0, ts, count;
	vector<int> to[5000];
	int from[5000];
	bool visited[5000];
	stack<int> s;
	while (scanf("%d %d", &f, &t) && f>=0 && t>=0) {
		cn++;
		en = 0;
		for (int i = 0; i<5000; i++) {
			to[i].clear();
		}
		memset(from, 0, sizeof(from));
		memset(visited, false, sizeof(visited));
		while (f>0 && t>0) {
			from[t] = 1;
			if (from[f]!=1) from[f] = -1;
			en++;
			to[f].push_back(t);
			scanf("%d %d", &f, &t);
		}
		for (int i = 0; i<5000; i++) if (from[i] == -1) {r = i;break;}
		if (r==-1) {
			printf("Case %d is not a tree.\n", cn);
			continue;
		}
		s.push(r);
		count = 0;
		while (!s.empty()) {
			node = s.top();
			s.pop();
			visited[node] = true;
			ts = to[node].size();
			for (int i = 0; i<ts; i++){
				if (!visited[to[node][i]]) {
					s.push(to[node][i]);
					count++;
				}
			}
		}
		if (count<en) printf("Case %d is not a tree.\n", cn);
		else printf("Case %d is a tree.\n", cn);
	}
	return 0;
}
