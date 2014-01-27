#include <cstdio>
using namespace std;

int main() {
	int m;
	while (scanf("%d", &m)!=EOF) {
		int n,tmp = 0;
		for (int i = 0; i<m; i++) {
			scanf("%d", &n);
			tmp ^= n;
		}
		if (tmp == 0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
