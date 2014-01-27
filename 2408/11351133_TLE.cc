#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

string words[30003];

class cmp {
public:
	bool operator() (const int& a, const int& b) const{
		return words[a]>words[b];
	}
};

typedef priority_queue<int, vector<int>, cmp> pq;

struct g{
	int num;
	pq list;
	g(int id){
		num=1;
		list.push(id);
	}
};

vector<g> v;
map<string, int> m;

bool intcmp(int a, int b) {
	return words[a] < words[b];
}

bool vcmp(const g& a, const g& b) {
	return a.num==b.num ? intcmp(a.list.top(), b.list.top()) : a.num>b.num;
}

int main(){
	string in,pre="", cur;
	int id = 0;
	int tmp;
	while (cin >> in) {
		words[id] = in;
		sort(in.begin(), in.end());
		if (m.count(in)==0) {
			v.push_back(g(id));
			m[in] = v.size()-1;
		}
		else {
			tmp = m[in];
			v[tmp].num++;
			v[tmp].list.push(id);
		}
		id++;
	}
	sort(v.begin(), v.end(), vcmp);
	int i;
	for (i = 0; i<5 && i<v.size(); i++) {
		cout << "Group of size " << v[i].num << ": ";
		while (!v[i].list.empty()) {
			cur = words[v[i].list.top()];
			if (cur!=pre)
				cout << cur <<" ";
			pre = cur;
			v[i].list.pop();
		}
		cout << "." << endl;
	}
	return 0;
}
