#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int index;
int parent[500001];
vector < pair < int, pair < int, int >  > > v;
long long cost;
int index_w;

int check = 0;


int find_set(int u)
{
	if(u == parent[u]){
		return u;
	}
	else{
		return parent[u] = find_set(parent[u]);
	}
}

void merge(int u, int v)
{
	u = find_set(u);
	v = find_set(v);
	parent[v] = u;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	cin >> index;
	for(int i = 1; i <= m; i++){
		int from, to, w;
		cin >> from >> to >> w;
		v.push_back({w, {from , to}});
		v.push_back({w, {to , from}});
	}
	
	//make_Set
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++){
		if(find_set(v[i].second.first) != find_set(v[i].second.second)){
			merge(v[i].second.first, v[i].second.second);
			cost = cost + v[i].first;
			check++;
			if(check == index){
				index_w = v[i].first;
			}
		}
	}
	
	cout << cost << "\n";
	cout << index_w << "\n";
	
}
