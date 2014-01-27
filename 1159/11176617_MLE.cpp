#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[5005][5005];

int main(){
	char in[5005];
	int n;
	cin >> n >> in;
	memset(dp, 0, sizeof(dp));
	for (int size = 2; size <=n; size++) {
		for ( int a = 0; a<n; a++) {
			int b = a+size-1;
			if (in[a]==in[b])
				dp[a][b] = dp[a+1][b-1];
			else
				dp[a][b] = min(dp[a][b-1], dp[a+1][b])+1;
		}
	}
	cout << dp[0][n-1]<<endl;
	//system("PAUSE");
	return 0;
}