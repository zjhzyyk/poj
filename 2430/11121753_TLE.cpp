#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool comp(int* a, int* b){
	if (a[0]==b[0])
		return a[1] < b[1];
	else return a[0] < b[0];
}

int main() {
	int n, k, b, area[1000][1000], dp[1001][1001], times;
	int **c = new int*[1000];
	cin >> n >> k >> b;
	memset (dp, 0, sizeof(dp[1001])*1001);
	for (int i =0; i<n; i++) c[i] = new int[2];
	for (int i =0; i<n; i++) cin >> c[i][1] >> c[i][0];
	sort(c, c+n, comp);
	for (int i=0; i<n; i++) {
		times = 1;
		area[i][i] = 1;
		for (int j=i+1; j<n; j++) {
			if (c[j][0]==c[j-1][0]) {
				if (times==2) area[i][j] = area[i][j-1];
				else {
					area[i][j] = 2*area[i][j-1];
					times =2;
				}
			}
			else if (times==2 || c[j][1]!=c[j-1][1]) {
				times = 2;
				area[i][j] = area[i][j-1] + 2*(c[j][0]-c[j-1][0]);
			}
			else
				area[i][j] = area[i][j-1] + c[j][0] - c[j-1][0];
		}
	}
	for (int i = 1; i<=k; i++) { //#barn
		for (int j = i; j<=n; j++) { //#cow
			if (i==1) {
				dp[i][j] = area[i-1][j-1];
				continue;
			}
			for (int k=i; k<=j; k++) { //start index (base:1)
				if (dp[i][j]==0) {
					dp[i][j] = dp[i-1][k-1]+area[k-1][j-1];
					continue;
				}
				if (dp[i-1][k-1]+area[k-1][j-1] < dp[i][j])
					dp[i][j] = dp[i-1][k-1]+area[k-1][j-1];
			}
		}
	}
	cout << dp[k][n];
	return 0;
}
