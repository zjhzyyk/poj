#include <cstdio>
#include <cstring>
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

		t[0] = 0;
		int i=1, j=0;
		while (i<l) {
			if (in[i]==in[j]) {
				t[i] = j+1;
				i++;j++;
			}
			else if (j>0) j = t[j];
			else {
				t[i] = 0; i++;
			}
		}

		top = 0;
		ans[top++] = l;
		while (l>0 && t[l-1]) {
			ans[top++] = t[l-1];
			l = t[l-1];
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
