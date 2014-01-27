#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	freopen("in", "r", stdin);
	char str[2][11]={"",""};
	int curstr=0;
	int leading = 0,l0,l1,count;
	while (~scanf("%s", str[curstr]) && strcmp(str[curstr], "")){
		count = 0;
		l0 = strlen(str[0]);
		l1 = strlen(str[1]);
		for (int i=0; i<leading+1 && i<l0 && i<l1; i++) {
			if (str[0][i]!=str[1][i]){
				break;
			}
			count++;
		}
		if (count==leading+1){
			leading++;
			for (int i = 0; i<leading; i++) printf(" ");
		}
		else {
			leading=count;
			for (int i = 0; i<leading; i++) printf(" ");
		}
		printf("%s\n", str[curstr]);
		curstr = !curstr;
	}
}
