#include <cstdio>
using namespace std;
int n, k, num[10005];
bool f[10002][102];

bool recurse(int x, int sum) {
	for (int i = 0; i<102; i++) f[x][i] = true;
	if (x==n-1) {
		if (sum%k==0) return true;
		else return false;
	}
	if (f[x][sum]) {
		if (recurse(x+1, (k+sum-num[x+1])%k)) return true;
		if (recurse(x+1, (sum+num[x+1])%k)) return true;
		f[x][sum]  = false;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i<n; i++) scanf("%d", &num[i]);
	if (recurse(0, num[0]%k))
		printf("Divisible");
	else
		printf("Not divisible");
	return 0;
}
