#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int parent[100001];
int r[100001];
vector < pair < int , pair < int, int > > > v;
int cost;
int big_cost = 0;

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
	
	if(r[u] > r[v]){
		parent[v] = u;
	}
	else{
		parent[u] = v;
		if(r[u] == r[v]){
			r[v] = r[v] + 1;
		}
	}
	
}
void make_set()
{
	for(int i = 0; i <= n; i++){
		parent[i] = i;
		r[i] = 0;
	}
}


int main(){
	cin >> n >> m;
	
	make_set();
	
	for(int i = 0; i < m; i++){
		int start , end, dist;
		cin >> start >> end >> dist;
		v.push_back({dist, {start, end}});
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++){
		if(find_set(v[i].second.first) != find_set(v[i].second.second)){
			merge(v[i].second.first , v[i].second.second);
			if(big_cost < v[i].first){
				big_cost = v[i].first;
			}
			cost = cost + v[i].first;
			
		}
	}
	
	cost = cost - big_cost;
	
	cout << cost << "\n";	
}
