#include <cstdio>
#include <cstring>
using namespace std;

int main(){
//	freopen("in", "r", stdin);
	char spaces[12][13]={
			"", // 0
			" ", //1
			"  ", //2
			"   ", //3
			"    ", //4
			"     ", //5
			"      ", //6
			"       ", //7
			"        ", //8
			"         ", //9
			"          ", //10
			"           "//11
	};
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
		leading=count;
		printf("%s", spaces[leading]);
		printf("%s\r\n", str[curstr]);
		curstr = !curstr;
	}
}
