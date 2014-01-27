#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	int dp[101], presum[100], sum[100], n, map[101][101], max = 0;
	cin >> n;
	for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) cin >> map[i][j];
	for (int i = 0; i<n; i++) {
		memset(presum, 0, sizeof(presum));
		for (int j = i; j<n; j++) {
			sum[0] = presum[0]+map[0][j];
			presum[0] = sum[0];
			dp[0] = sum[0];
			for (int k=1; k<n; k++) {
				sum[k] = presum[k]+map[k][j];
				presum[k] = sum[k];
				dp[k] = dp[k-1]<=0 ? sum[k] : dp[k-1]+sum[k];
				if (dp[k] > max) max = dp[k];
			}
		}
	}
	cout << max <<endl;
	//system("PAUSE");
	return 0;
}