#include <cstdio>
using namespace std;

bool visited[9][9], flag;
int h,w, dx[]={-1, 1, -2, 2, -2, 2, -1, 1}, dy[]={-2, -2, -1, -1, 1, 1, 2, 2}, count,step, cnn = 1;

struct point{
	int x, y;
}next[70];

void flood(int x, int y) {
	count++;step++;
	if (x>=0 && y>=0 && y<w && x<h && !visited[x][y] && !flag) {
		visited[x][y] = true;
		if (count == h*w) {
			flag = true;
			return;
		}
		for (int i = 0; i<8; i++) {
			next[step].x = x+dx[i];
			next[step].y = y+dy[i];
			flood(x+dx[i], y+dy[i]);
			if (flag) return;
			count--;
			step--;
		}
		visited[x][y] = false;
	}
}

int main() {
	int cn;
	scanf("%d", &cn);
	while (cn--) {
		scanf("%d %d", &h, &w);
		for (int i = 0; i<h; i++) for (int j = 0 ; j<w; j++) visited[i][j] = false;
		count = 0;
		step = 0;
		flag = false;
		flood(0,0);
		printf("Scenario #%d:\n", cnn++);
		if (flag) {
			for (int i = 0; i<step; i++)
				printf("%c%d", next[i].y+'A', next[i].x+1);
			printf("\n");
		}
		else
			printf("impossible\n");
		if (cn!=0) printf("\n");
	}
	return 0;
}
