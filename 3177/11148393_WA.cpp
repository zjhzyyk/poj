#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int en[5002], f, r, a, b, count =0;
	scanf("%d %d", &f, &r);
	memset(en, 0, f);
	while (r--) {
		scanf("%d %d", &a, &b);
		en[a]++;
		en[b]++;
	}
	for (int i = 1; i<(f+1); i++)
		if (en[i]==1)
			count ++;
	double ans = count/2.0;
	if (ans==(double)(count/2)) printf("%d", count/2);
	else printf("%d", (count/2)+1);
	return 0;
}
