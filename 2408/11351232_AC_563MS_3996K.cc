#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

string words[30003];

struct g{
	int num;
	vector<int> list;
	g(){}
	g(int id){
		num=1;
		list.push_back(id);
	}
};

g v[30005];
map<string, int> m;

bool vcmp(const g& a, const g& b) {
	return a.num>b.num;
}

bool vcmp2(const g& a, const g& b) {
	return a.num==b.num ? words[a.list[0]] < words[b.list[0]] : a.num>b.num;
}

bool listcmp(int i, int j) {
	return words[i] < words[j];
}

int main(){
	string in,pre="", cur;
	int id = 0;
	int tmp;
	int count = 0;
	while (cin >> in && in!="#") {
		words[id] = in;
		sort(in.begin(), in.end());
		if (m.count(in)==0) {
			v[count] = g(id);
			m[in] = count++;
		}
		else {
			tmp = m[in];
			v[tmp].num++;
			v[tmp].list.push_back(id);
		}
		id++;
	}
	sort(v, v+count, vcmp);
	int i;
	for (i = 0; (i<5 || (i>2 && v[i].num==v[i-1].num)) && i<count; i++) {
		sort(v[i].list.begin(), v[i].list.end(), listcmp);
	}
	sort(v, v+i, vcmp2);
	int size;
	for (i = 0; i<5 && i<count; i++) {
		cout << "Group of size " << v[i].num << ": ";
		size = v[i].list.size();
		for (int j = 0; j<size; j++) {
			cur = words[v[i].list[j]];
			if (cur!=pre)
				cout << cur <<" ";
			pre = cur;
		}
		cout << "." << endl;
	}
	return 0;
}
