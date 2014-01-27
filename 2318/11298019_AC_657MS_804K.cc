#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct p{
	int x, y;
	p(){}
	p(int a, int b) : x(a), y(b) {}
	p operator- (const p& a){
		return p(this->x-a.x, this->y-a.y);
	}
	int cross (const p& a) {
		return this->x*a.y-this->y*a.x;
	}
};

struct line {
	p up, down;
	line(){}
	line(p a, p b): up(a), down(b) {}
	int check(p a){
		if ((up-down).cross(a-down) < 0) return 1; //should be on the right side
		else return -1;//left
	}
}lines[5005];

int main(){
	int n, m, x1, y1, x2, y2,ui, li,x,y,low,high,mid,num[5005];
	lines[0] = line(p(x1, y1),p(x1,y2));
	while (cin >> n && n!=0 && cin>> m >> x1>> y1>>x2>>y2) {
		memset(num, 0, sizeof(num));
		for (int i = 1; i<=n; i++) {
			cin >> ui >> li;
			lines[i] = line(p(ui, y1), p(li, y2));
		}
		lines[n+1] = line(p(x2, y1),p(x2,y2));
		for (int i=0; i<m; i++) {
			cin >> x >> y;
			low = 0;
			high = n+1;
			while (low+1<high) {
				mid = (low+high)/2;
				if (lines[mid].check(p(x,y))==1) {
					low = mid;
				}
				else high = mid;
			}
			num[low]++;
		}
		for (int i = 0; i<n+1; i++) {
			cout << i << ": " << num[i]<<endl;
		}
		cout << endl;
	}
	return 0;
}
