#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[3][5005];
char in[5005];

int main(){
	int n;
	cin >> n >> in;
	memset(dp, 0, sizeof(dp));
	for (int size = 2; size <=n; size++) {
		int x = size%3, y = (size-1)%3 , z = (size-2)%3; 
		for ( int a = 0; a<n-size+1; a++) {
			if ( in[a] == in[a+size-1] ) dp[x][a] = dp[z][a+1]; 
			else dp[x][a] = dp[z][a+1] + 2; 
			dp[x][a] = min( dp[x][a] , dp[y][a] + 1 ); 
			dp[x][a] = min( dp[x][a] , dp[y][a+1] + 1 );
		}
	}
	cout << dp[n%3][0]<<endl;
	//system("PAUSE");
	return 0;
}