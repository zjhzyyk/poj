#include <cstdio>
using namespace std;
int n, k, num[10005];
bool f[10002][102], flag = false;

bool recurse(int x, int sum) {
	if (x==n-1) {
		if (sum%k==0) {
			flag = true;
			return flag;
		}
		else return flag;
	}
	if (!f[x][sum]) {
		f[x][sum]  = true;
		if (recurse(x+1, (k+sum-num[x+1])%k)) return true;
		if (recurse(x+1, (sum+num[x+1])%k)) return true;
	}
	return flag;
}

int main() {
	scanf("%d %d", &n, &k);
	int in;
	for (int i = 0; i<n; i++) {
		scanf("%d", &in);
		num[i] = in%k;
	}
	if (recurse(0, num[0]%k))
		printf("Divisible");
	else
		printf("Not divisible");
	return 0;
}
