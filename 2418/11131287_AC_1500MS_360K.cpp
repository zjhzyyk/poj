#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main() {
	char c[32];
	map<string, int> mp;
	map<string, int>::iterator it;
	int s = 0;
	while (gets(c)!=NULL){
		mp[c]++;
		s++;
	}

	for (it = mp.begin(); it != mp.end(); it++) {
		printf("%s %.4lf\n", it->first.c_str(), (it->second)*100.0/(double)s);
	}
	return 0;
}
