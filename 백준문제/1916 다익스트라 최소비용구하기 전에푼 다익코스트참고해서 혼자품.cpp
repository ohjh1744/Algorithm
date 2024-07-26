#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n, m;
int f_n, e_n;
vector < pair < int, int > > v[100001];
int dist[1001];

void dfs(int start)
{
	priority_queue< pair<int, int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
	pq.push({0, start});
	while(!pq.empty()){
		int c_d = pq.top().first;
		int c_n = pq.top().second;
		pq.pop();
		
		if(dist[c_n] < c_d){
			continue;
		}
		
		for(int i = 0; i < v[c_n].size(); i++){
			int n_d = c_d + v[c_n][i].second;
			int n_n = v[c_n][i].first;
			if(dist[n_n] > n_d){
				dist[n_n] = n_d;
				pq.push({n_d, n_n});
			}
		}
	}
	
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int st, ed, d;
		cin >> st >> ed >> d;
		v[st].push_back({ed, d});
	}
	cin >> f_n >> e_n;
	
	for(int i = 0; i <= n; i++){
		dist[i] = 999999999;
	}
	
	dist[f_n] = 0;
	dfs(f_n);
	
	cout << dist[e_n] << "\n";

}
