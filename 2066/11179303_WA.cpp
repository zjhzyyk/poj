#include <iostream>
#include <algorithm>
#include <cstring>
#define IMAX 0x7fffffff
using namespace std;

int m;

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
	return cross(a, b, (a+1)%m) * cross(a, b, (a-1)%m)<=0 && 
		cross(c, a, (m+c-1)%m) * cross(c, a, (c+1)%m) <=0 &&
		cross(c, b, (m+c-1)%m) * cross(c, b, (c+1)%m) <=0;
}

double area(int a, int b, int c){
	return abs(cross(c, a, b))/2.0;
}

int main(){
	double dp[51][51];
	int cn;
	cin >> cn;
	cout.setf(ios::fixed);
	cout.precision(1);
	while (cn--) {
		cin >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i<m; i++) cin >> p[i].x >> p[i].y;
		for (int i = 3; i<=m; i++){ //# of point in the closed interval
			for (int j=0; j<m; j++){ //start point
				dp[j][(j+i-1)%m] = IMAX;
				for (int k = j+1; k<j+i-1; k++) {
					if (triangle(j, (j+i-1)%m, k%m))
						dp[j][(j+i-1)%m] = min(dp[j][(j+i-1)%m], max(max(dp[j][k%m], dp[k%m][(j+i-1)%m]), area(j, (j+i-1)%m, k%m)));
					else if (i==3)
						dp[j][(j+i-1)%m] = 0;
				}
			}
		}
		cout << dp[0][m-1] << endl;
	}
	//system("PAUSE");
	return 0;
}