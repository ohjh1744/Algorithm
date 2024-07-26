#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int  n, m;
int s;
vector < pair < int, int > > v[500001];
long long dist[500001];

void dijkstra(int start)
{
	for(int i = 1; i <= n; i++){
		dist[i] = 1e9;
	}
	dist[start] = 0;	
	priority_queue< pair<int, int>, vector<pair<int,int>> , greater<pair<int,int> > > pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int c_d = pq.top().first;
		int c_n = pq.top().second;
		pq.pop();
		
		//이 방문처리 빼도 AC 
		if(dist[c_n] < c_d){
			continue;
		}
		
		for(int i = 0; i < v[c_n].size(); i++){
			int n_d = v[c_n][i].second;
			int n_n = v[c_n][i].first;
			if(dist[n_n] > c_d + n_d){
				dist[n_n]  = c_d+ n_d;
				pq.push({dist[n_n], n_n});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= m; i++){
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({to, dist});
		v[to].push_back({from, dist});
	}
	
	dijkstra(s);
	
	for(int i = 1; i <= n; i++){
		if(dist[i] == 1e9){
			cout << "INF" << "\n";
		} 
		else{
			cout << dist[i] << "\n";
		}
	}
	
	
}
