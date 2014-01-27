#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct node {
	int state, op, step;
	node(){}
	node(int a, int b, int c):state(a), op(b), step(c) {}
}nd[65540];

bool vis[65540];
int q[65540], head=0, tail=0;

int flip(int pos, int state) {
	int num = 0xF << (4*(3-pos/4));
	for (int i = 0; i<4; i++)
		num = num | 1<<(4*(3-i)+(3-pos%4));
	return state ^ num;
}

int main(){
	bool flag = false;
	char str[5];
	int state = 0, ndx = 0, tmp, result, ans, op;
	for (int i = 0; i<4; i++) {
		scanf("%s", str);
		state<<=4;
		for (int j = 0; j<4; j++)
			if (str[j]=='+') state+=(1<<(3-j));
	}
	vis[state] = 1;
	nd[ndx++] = node(state, 0, 0);
	q[tail++] = 0;
	while (head<tail) {
		tmp = q[head++];
		for (int i = 0; i<16; i++) {
			if ((nd[tmp].op & (1<<i)) == 0) {
				result = flip(i, nd[tmp].state);
				if (result==0) {
					flag = true;
					ans = nd[tmp].step+1;
					op = nd[tmp].op | (1<<i);
					break;
				}
				if (vis[result]==false){
					vis[result]=true;
					nd[ndx] = node(result, nd[tmp].op | (1<<i), nd[tmp].step+1);
					q[tail++] = ndx;
					ndx++;
				}
			}
		}
		if (flag) break;
	}
	cout << ans << endl;
	for (int i = 0; i<16; i++) {
		if ((op & (1<<i)) !=0 )
			cout << (i/4+1) << " " << (i%4+1) << endl;
	}
	return 0;
}
