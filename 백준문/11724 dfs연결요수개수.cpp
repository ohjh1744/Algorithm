#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int visit[1001];
vector<int> graph[1001];

int ct = 0;

void dfs(int x)
{
	visit[x] = true;
	for(int i =0; i< graph[x].size(); i++){
		int nx = graph[x][i];
		if(!visit[nx]){
			dfs(nx);
		}
	}
}

int main()
{
	int n , m;
	cin >> n >> m;
	
	int u ,v ;
	
	for(int i =0; i < m; i++){
	   cin >> u >> v;
	   graph[u].push_back(v);
	   graph[v].push_back(u);
	}
	
	graph[u].push_back(v);
	
	for(int i = 0; i< n; i++){
	  sort(graph[i+1].begin(), graph[i+1].end());	
	}
	
	for(int i = 1; i <=n; i++){
		if(!visit[i]){
			ct++;
			dfs(i);
		}
	}
	
	cout << ct;
	
}
