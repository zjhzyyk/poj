#include <iostream>
#include <algorithm>
#include <cstring>
#define IMAX 0x7fffffff
using namespace std;

struct point {
	int x, y;
}p[51];

int cross(int a, int b, int c){
	int x1 = p[b].x-p[a].x;
	int x2 = p[c].x-p[a].x;
	int y1 = p[b].y-p[a].y;
	int y2 = p[c].y-p[a].y;
	return x1*y2-x2*y1;
}

bool triangle(int a, int b, int c){
	return cross(a, b, a+1)*cross(a,b,a-1)<=0 && 
		((cross(c, c-1, a)<=0 && cross(c, a,b)<=0 && cross(c, b, c+1)<=0)
		|| (cross(c, c-1, a)>=0 && cross(c, a,b)>=0 && cross(c, b, c+1)>=0));
}

double area(int a, int b, int c){
	return abs(cross(c, a, b))/2.0;
}

int main(){
	double dp[51][51];
	int cn, m;
	cin >> cn;
	cout.setf(ios::fixed);
	cout.precision(1);
	while (cn--) {
		cin >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i<m; i++) cin >> p[i].x >> p[i].y;
		for (int i = 3; i<=m; i++){ //# of point in the closed interval
			for (int j=0; (j+i-1)<m; j++){ //start point
				dp[j][j+i-1] = IMAX;
				for (int k = j+1; k<j+i-1; k++) {
					if (triangle(j, j+i-1, k))
						dp[j][j+i-1] = min(dp[j][j+i-1], max(max(dp[j][k], dp[k][j+i-1]), area(j, j+i-1, k)));
					else if (i==3)
						dp[j][j+i-1] = 0;
				}
			}
		}
		cout << dp[0][m-1] << endl;
	}
	//system("PAUSE");
	return 0;
}