#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;

int main(){
	int map[105][105], n, here, size, weight;
	bool used[105];
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	PII tmp;
	while (cin >> n) {
		memset(used, 0, sizeof(used));
		for (int i = 0; i<n; i++)
			for (int j = 0; j< n ; j++)
				cin >> map[i][j];
		while (!pq.empty()) pq.pop();
		used[0] = 1;
		size = 1;
		weight = 0;
		for (int i = 0; i<n; i++)
			if (i!=0) pq.push(make_pair(map[0][i], i));
		while (!pq.empty() && size!=n) {
			tmp = pq.top();
			pq.pop();
			here = tmp.second;
			if (!used[here]) {
				used[here] = 1;
				size++;
				weight+=tmp.first;
				for (int i = 0; i<n; i++)
					if (!used[i]) pq.push(make_pair(map[here][i], i));
			}
		}
		cout << weight << endl;
	}
	return 0;
}
