#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF -10000000000;

int main() {
	int len[501][501][4];
	int a[500], b[500], ans[500];
	int la, lb, x, y;
	len[0][0][0] = 0;
	len[0][0][1] = INF;
	len[0][0][2] = 0;
	len[0][0][3] = 0;
	cin >> la;
	for (int i = 0; i < la; i++) cin >> a[i];
	cin >> lb;
	for (int i = 0; i < lb; i++) cin >> b[i];
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			len[i][j][0] = 0;
			len[i][j][1] = INF;
			if (len[i][j - 1][0] > len[i - 1][j][0]) {
				len[i][j][0] = len[i][j - 1][0];
				len[i][j][1] = len[i][j - 1][1];
				len[i][j][2] = len[i][j - 1][2];
				len[i][j][3] = len[i][j - 1][3];
			} else {
				len[i][j][0] = len[i - 1][j][0];
				len[i][j][1] = len[i - 1][j][1];
				len[i][j][2] = len[i - 1][j][2];
				len[i][j][3] = len[i - 1][j][3];
			}
			x = len[i - 1][j - 1][2];
			y = len[i - 1][j - 1][3];
			if (i > 0 && j > 0 && a[i - 1] == b[j - 1]
					&& a[i - 1] > len[i - 1][j - 1][1]) {

				if ((len[i - 1][j - 1][0] + 1) > len[i][j][0]) {
					len[i][j][0] = len[i - 1][j - 1][0] + 1;
					len[i][j][1] = a[i - 1];
					len[i][j][2] = i - 1;
					len[i][j][3] = j - 1;
				}
			} else if (i > 0 && j > 0 && a[i - 1] == b[j - 1]
					&& a[i - 1] > len[x][y][1]) {

				if (len[x][y][0] + 1 >= len[i][j][0]) {
					len[i][j][0] = len[x][y][0] + 1;
					len[i][j][1] = a[i - 1];
					len[i][j][2] = x;
					len[i][j][3] = y;
				}
			}
		}
	}
	cout << len[la][lb][0] << endl;
	int i, j, n = len[la][lb][0], tmp;
	i = la;
	j = lb;
	while (n != 0) {
		ans[(n--) - 1] = len[i][j][1];
		tmp = len[i][j][2];
		j = len[i][j][3];
		i = tmp;
	}
	n = len[la][lb][0];
	for (i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
