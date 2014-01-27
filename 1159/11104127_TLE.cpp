#include <iostream>
using namespace std;
#define INF 0x7FFFFFFF
char in[5000];
int ans = INF;
void r(int a, int b, int n) {
	if (a==b || b-a==1) {
		if (n<ans) ans = n;
		return;
	}
	if (in[a]==in[b]) r(a+1, b-1, n);
	else  {
		r(a+1, b, n+1);
		r(a, b-1, n+1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) cin >> in[i];
	r(0, n-1, 0);
	cout << ans;
	return 0;
}
