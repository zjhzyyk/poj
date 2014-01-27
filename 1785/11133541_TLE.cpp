#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
struct node{
	string self;
	int left, right, p;
}nd[50010];

inline bool cmp(const node& a, const node& b){
	return a.p > b.p;
}

string ans(int r) {
	if (r==-1) return "";
	stringstream ss;
	ss << nd[r].p;
	string str = ss.str();
	return "(" + ans(nd[r].left) + nd[r].self + "/" + str + ans(nd[r].right) + ")";
}

int main() {
	int n, cur, mid;
	string in;
	while (cin >> n && n!=0) {
		for (int i = 0; i<n; i++) {
			cin >> in;
			mid = in.find_last_of("/");
			nd[i].self = in.substr(0,mid);
			stringstream(in.substr(mid+1)) >> nd[i].p;
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
