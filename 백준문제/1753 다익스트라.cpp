#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector < pair <int, int> > v[20001]; // 노드와 가중치 
int dist[20001];
int V, E;
int f_node;

void dstra(int start)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //최소힙 구조  
	pq.push({0 , start});
	while(!pq.empty()){
		int c_val = pq.top().first;
		int c_node = pq.top().second;
		pq.pop();
		
		if(dist[c_node] < c_val){
			continue;
		}
		for(int i = 0; i < v[c_node].size(); i++){
			int n_node = v[c_node][i].first;
			int new_val = c_val + v[c_node][i].second;
			if(new_val < dist[n_node]){
				dist[n_node] = new_val;
				pq.push({new_val, n_node});
			}
		}
	}
}

int main()
{
	cin >> V >> E;
	cin >> f_node;
	for(int i = 0; i < E; i++){
		int u, v2, w;
		cin >> u >> v2 >> w;
		v[u].push_back({v2, w});
	}
	
	for(int i = 1; i <= V; i++){
		dist[i] = 987654321;
	}
	dist[f_node] = 0;	
	dstra(f_node);
	for(int i = 1; i <= V; i++){
		if(dist[i] == 987654321){
			cout << "INF" << "\n";
		}
		else{
			cout << dist[i] << "\n";
		}
	}
	
	
}
