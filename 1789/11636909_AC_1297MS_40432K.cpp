#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;

string strs[2005];
int dist[2005][2005];
bool used[2005];
int n;

int prim(){
	int size, weight, here;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	PII tmp;
	memset(used, 0, sizeof(used));
	used[0] = 1;
	size = 1;
	weight = 0;
	for (int i = 0; i<n; i++)
	    if (i!=0) pq.push(make_pair(dist[0][i], i));
	while (!pq.empty() && size!=n) {
	    tmp = pq.top();
	    pq.pop();
	    here = tmp.second;
	    if (!used[here]) {
		    used[here] = 1;
		    size++;
		    weight+=tmp.first;
		    for (int i = 0; i<n; i++)
			    if (!used[i]) pq.push(make_pair(dist[here][i], i));
	    }
	}
	return weight;
}

int main(){
	int num;
	while (cin >> n && n) {
		for (int i = 0; i<n; i++)
			cin >> strs[i];
		for (int i = 0; i<n; i++) {
			for (int j = i+1; j<n; j++) {
				num = 0;
				for (int k = 0; k<7; k++) {
					if (strs[i][k]!=strs[j][k]) num++;
				}
				dist[i][j] = dist[j][i] = num;
			}
		}
		cout << "The highest possible quality is 1/" << prim() << "." << endl;
	}

	return 0;
}
