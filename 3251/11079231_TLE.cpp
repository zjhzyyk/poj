#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int x = -1;
int y = -1;
int maxa = 0;
bool bpos[100][100];
void ans(int xx, int yy, int area) {
	if (bpos[xx][yy]) return;
	maxa = area;
	x = xx;
	y = yy;
}

void square(int a, int b, int c, int d, int e, int f) {

	int ac = ((a-c)*(a-c)) + ((b-d)*(b-d));
	int ae = ((a-e)*(a-e)) + ((b-f)*(b-f));
	int ce = ((c-e)*(c-e)) + ((d-f)*(d-f));

	if (ac > maxa) {
		if (ac==ae && (ac+ae)==ce) {
			ans(c+e-a,d+f-b,ac);
		}
		if (ac==ce && (ac+ce)==ae) {
			ans(a+e-c,b+f-d,ac);
		}
	}
	else if (ae > maxa) {
		if (ae==ce && (ae+ce)==ac) {
			ans(a+c-e,b+d-f,ae);
		}
	}
}

int main(){
	int n;
	cin>>n;
	string in;
	int l;
	int jpos[10000][2];
	int jnum = 0;
	for (int i = 0; i<n; i++) {
		cin>>in;
		l = in.length();
		for(int j = 0; j<l; j++) {
			if (in[j]=='J') {
				jpos[jnum][0] = j;
				jpos[jnum][1] = i;
				jnum++;
			}
			else if (in[j]=='B') {
				bpos[j][i] = true;
			}
		}
	}
	for (int i = 0; i<jnum; i++) {
		for (int j = i+1; j<jnum; j++) {
			for (int k = j+1; k<jnum; k++) {
				square(jpos[i][0],jpos[i][1],jpos[j][0],jpos[j][1],jpos[k][0],jpos[k][1]);
			}
		}
	}
	cout << maxa<<endl;
	return 0;
}
