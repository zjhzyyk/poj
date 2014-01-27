#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int t[400004], ans[400004];
int l;
//string in;
char in[400004];

int main(){
	int top;
	while (scanf("%s",in)!=EOF) {
		l = strlen(in);
//		buildTable();

		t[0] = -1;
		int i=0, j=-1;
		while (i<l) {
			if(j==-1||in[i]==in[j]){
				i++,j++;
				t[i]=j;
			}else j=t[j];
		}
//		for (int i = 0; i<=l; i++) {
//			cout << t[i] <<endl;
//		}
		top = 0;
		ans[top++] = l;
		while (l>-1 && t[l]) {
			ans[top++] = t[l];
			l = t[l];
		}
		top--;
		while (1) {
			printf("%d", ans[top--]);
			if (top==-1) {
				printf("\n");
				break;
			}
			else
				printf(" ");
		}
	}
	return 0;
}
