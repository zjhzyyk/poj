#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	char ch;
	int grid[100][100];
	int max = 0;
	memset(grid, 0, sizeof(grid[0][0]) * 100 * 100);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == 'J')
				grid[j][i] = 1;
			else if (ch == 'B')
				grid[j][i] = -1;
			else
				grid[j][i] = 0;
		}
	}
	int a, b, c, d, x1, y1, x2, y2, total = n * n, dx, dy;
	for (int i = 0; i < total; i++) {
		for (int j = i + 1; j < total; j++) {
			x1 = i % n;
			y1 = i / n;
			x2 = j % n;
			y2 = j / n;
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
