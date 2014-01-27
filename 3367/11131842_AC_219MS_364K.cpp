#include <stdio.h>
#include <cstring>
#include <deque>
using namespace std;

struct node {
	int left;
	int right;
	char self;
} nd[10010];

int main() {
	int cn, len,id, first, second, tmp;
	char in[10010];
	deque<int> dq;
	scanf("%d", &cn);
	while (cn--) {
		scanf("%s", in);
		id = 0;
		dq.clear();
		len = strlen(in);
		for (int i = 0; i<len; i++) {
			if ((in[i]-'a')>=0) {
				nd[id].left = -1;
				nd[id].right = -1;
				nd[id].self = in[i];
				dq.push_back(id++);
			}
			else {
				first = dq.back();
				dq.pop_back();
				second = dq.back();
				dq.pop_back();
				nd[id].left = second;
				nd[id].right = first;
				nd[id].self = in[i];
				dq.push_back(id++);
			}
		}
		for (int i = len-1; i>=0; i--) {
			tmp = dq.back();
			dq.pop_back();
			in[i] = nd[tmp].self;
			if (nd[tmp].left!=-1) {
			dq.push_front(nd[tmp].left);
			dq.push_front(nd[tmp].right);
			}
		}
		printf("%s\n", in);
	}
	return 0;
}
