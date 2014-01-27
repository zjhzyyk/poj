#include <cstdio>
using namespace std;
int n, k, num[10005];

bool reverse(int x, int sum) {
	if (x==n-1) {
		if (sum%k==0) return true;
		else return false;
	}
	if (reverse(x+1, sum-num[x+1])) return true;
	if (reverse(x+1, sum+num[x+1])) return true;
	return false;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i<n; i++) scanf("%d", &num[i]);
	if (reverse(0, num[0]))
		printf("Divisible");
	else
		printf("Not divisible");
	return 0;
}
