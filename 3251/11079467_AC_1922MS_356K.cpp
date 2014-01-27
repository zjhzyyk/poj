#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	char ch;
	int grid[100][100];
	int jpos[10000][2];
	int max = 0;
	memset(grid, 0, sizeof(grid[0][0]) * 100 * 100);
	int jnum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == 'J') {
				grid[j][i] = 1;
				jpos[jnum][0] = j;
				jpos[jnum][1] = i;
				jnum++;
			}
			else if (ch == 'B')
				grid[j][i] = -1;
			else
				grid[j][i] = 0;
		}
	}
	int a, b, c, d, x1, y1, x2, y2, dx, dy;
	for (int i = 0; i < jnum; i++) {
		for (int j = i + 1; j < jnum; j++) {
			x1 = jpos[i][0];
			y1 = jpos[i][1];
			x2 = jpos[j][0];
			y2 = jpos[j][1];
			dx = x1 - x2;
			dy = y1 - y2;
			if (grid[x1][y1] == 1 && grid[x2][y2] == 1) {
				a = x2 - dy;
				b = y2 + dx;
				c = x1 - dy;
				d = y1 + dx;
				if (a >= 0 && a < n && b >= 0 && b < n && c >= 0 && c < n
						&& d >= 0 && d < n
						&& (grid[a][b] == 1 || grid[c][d] == 1)
						&& (grid[a][b] != -1 && grid[c][d] != -1)
						&& (dx * dx + dy * dy) > max)
					max = dx * dx + dy * dy;
				else {
					a = x2 + dy;
					b = y2 - dx;
					c = x1 + dy;
					d = y1 - dx;
					if (a >= 0 && a < n && b >= 0 && b < n && c >= 0 && c < n
							&& d >= 0 && d < n
							&& (grid[a][b] == 1 || grid[c][d] == 1)
							&& (grid[a][b] != -1 && grid[c][d] != -1)
							&& (dx * dx + dy * dy) > max)
						max = dx * dx + dy * dy;
				}
			}
		}
	}
	cout << max;
	return 0;
}
