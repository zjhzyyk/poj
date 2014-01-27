#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define IMAX 0x7fffffff
using namespace std;

int main(){
	int cn, m, l, dp[32][13], cost[31][31], pre[31][31], ans[13];
	int count[30];
	char in[34];
	cin >> cn;
	while (cn--) {
		cin >> m;
		memset(count, 0, sizeof(count));
		for (int i = 0; i<m; i++) {
			cin >> in;
			l = strlen(in);
			for (int j = 0; j<l; j++) {
				if (in[j] == '+') count[26]++;
				else if (in[j]=='*') count[27]++;
				else if (in[j]=='/') count[28]++;
				else if (in[j]=='?') count[29]++;
				else count[in[j]-'a']++;
			}
		}
		for (int i = 0; i <30; i++){
			cost[i][i] = count[i];
			for (int j = i+1; j<30; j++)
				cost[i][j] = cost[i][j-1] + (j-i+1)*count[j];
		}
		for (int i = 0; i<30; i++) dp[i][0] = cost[0][i];
		for (int i = 1; i<=11; i++) 
			for (int j = i; j<30; j++){
				dp[j][i] = IMAX;
				pre[j][i] = 50;
				for (int k = i-1; k<j; k++) {
					if ((dp[k][i-1]+cost[k+1][j])==dp[j][i] && k<pre[j][i])
						pre[j][i] = k;
					if ((dp[k][i-1]+cost[k+1][j])<dp[j][i]) {
						dp[j][i] = dp[k][i-1]+cost[k+1][j];
						pre[j][i] = k;
					}
				}
			}
		ans[12] = 29;
		for (int i = 11; i>=1; i--) ans[i] = pre[ans[i+1]-1][i]+1;
		for (int i = 1; i<=11; i++) {
			if (ans[i] == 26 ) cout << "+";
			else if (ans[i] == 27) cout << "*";
			else if (ans[i] == 28) cout << "/";
			else if (ans[i] == 29) cout << "?";
			else printf("%c", ans[i]+'a');
		}
		cout << endl;
	}
	//system("PAUSE");
	return 0;
}