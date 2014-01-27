#include <cstdio>
#include <cstring>
#include <iostream>
#define N 1000005
using namespace std;

char in[N];
int t[N];

int main(){
	int n, cn = 1;
	while (scanf("%d", &n) && n!=0) {
		scanf("%s", in);
		t[0] = -1;
		int i=0, j=-1;
		while (i<n) {
			if(j==-1||in[i]==in[j]){
				i++,j++;
				t[i]=j;
			}else j=t[j];
		}
//		for (i=0; i<=n; i++) cout << t[i] << endl;
		printf("Test case #%d\n", cn++);
		for (i = 2; i<=n; i++) {
			int div = i / (i-t[i]);
			if (i % (i-t[i])==0 && div!=1)
				printf("%d %d\n", i, div);
		}
		printf("\n");
	}
	return 0;
}
