#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n!=0) {
		if (n>2) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}