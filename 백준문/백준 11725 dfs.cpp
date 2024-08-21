#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool visited[100001];
vector<int> v[100001];
int parent[100001];

void dfs(int node){
	visited[node] = true;
	for(int i =0; i<v[node].size(); i++){
		int next = v[node][i];
		if(!visited[next]){
			parent[next] = node;
			dfs(next);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i<n-1; i++){
	   int a, b;
	   cin >> a >> b;
	   v[a].push_back(b);
	   v[b].push_back(a);	
	}
	
   for(int i = 0; i< n; i++){
	  sort(v[i+1].begin(), v[i+1].end());	
	}
    
    dfs(1);
    
    for(int i =2; i <=n; i++){
    	cout << parent[i] << "\n";
	}
	
	return 0;
}
