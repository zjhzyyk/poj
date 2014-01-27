#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
struct node{
	char self;
	int left, right, p;
}nd[50010];

inline bool cmp(const node& a, const node& b){
	return a.p > b.p;
}

string ans(int r) {
	if (r==-1) return "";
	char num;
	itoa(nd[r].p, &num, 10);
	return "(" + ans(nd[r].left) + nd[r].self + "/" + num + ans(nd[r].right) + ")";
}

int main() {
	int n, cur;
	char ignore;
	while (cin >> n && n!=0) {
		for (int i = 0; i<n; i++) {
			cin >> nd[i].self >> ignore >> nd[i].p;
			nd[i].left = -1;
			nd[i].right = -1;
		}
		sort(nd, nd+n, cmp);
		for (int i = 1; i<n; i++) {
			cur = 0;
			while (1) {
				if (nd[i].self > nd[cur].self)
					if (nd[cur].right!=-1) {
						cur = nd[cur].right;
					}
					else {
						nd[cur].right = i;
						break;
					}
				else
					if (nd[cur].left!=-1) {
						cur = nd[cur].left;
					}
					else {
						nd[cur].left = i;
						break;
					}
			}
		}
		printf("%s\n", ans(0).c_str());
	}
	return 0;
}
