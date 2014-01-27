#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int main() {
	int cn, node[10010], parent, child, n, a, b;
	set<int> sa, sb;
	scanf("%d", &cn);
	while (cn--) {
		memset(node, 0, sizeof(node));
		scanf("%d", &n);
		for (int i = 0; i < n - 1; i++) {
			scanf("%d %d", &parent, &child);
			node[child] = parent;
		}
		scanf("%d %d", &a, &b);
		sa.clear();
		sb.clear();
		while (a != 0 || b != 0) {
			sa.insert(a);
			sb.insert(b);
			if (sb.find(a)!=sb.end()) {
				printf("%d\n", a);
				break;
			}
			if (sa.find(b)!=sa.end()) {
				printf("%d\n", b);
				break;
			}
			a = node[a];
			b = node[b];
		}
	}
	return 0;
}