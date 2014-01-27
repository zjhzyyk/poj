#include <iostream>
#include <cstdio>
#include <algorithm>
#define IMAX 4000000
using namespace std;

int main(){
    int dp[305][35], cost[302][302], d[303], v, p;
    cin >> v >> p;
    for ( int i = 1; i<=v; i++) {
        cin >> d[i];
        cost[i][i] = 0;
        dp[i][0] = IMAX;
        for (int j = 1; j<=p; j++) dp[i][j] = IMAX;
    }
    for (int i = 0; i<=p; i++) dp[1][i] = 0;
    for (int i = 1; i<=v; i++) {
        for (int j = i+1; j<=v; j++) {
            cost[i][j] = cost[i][j-1] + d[j]-d[(i+j)/2];
        }
        dp[i][1] = cost[1][i];
    }
    for (int i = 2; i<=v; i++)
        for (int j = 1; j<i; j++)
            for (int n = 2; n<=(j+1) && n<=p; n++) {
                dp[i][n] = min(dp[j][n-1] + cost[j+1][i], dp[i][n]);
            }
    cout << dp[v][p] << endl;
    return 0;
}