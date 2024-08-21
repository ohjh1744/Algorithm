#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

vector<int> v[501];
int visited[501];
queue<int> q;

int ct = 0;

void bfs(int x){
	q.push(x);
	visited[x] = 1;    
	while(!q.empty()){
		int nx = q.front();
		q.pop();
		for(int i = 0; i< v[nx].size(); i++){
			int y = v[nx][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = visited[nx] + 1;    
			}
			
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;
	
	int f1, f2;
	
	for(int i = 0; i < m; i++){
		cin >> f1 >> f2;
		v[f1].push_back(f2);
		v[f2].push_back(f1);
	}
	
	for(int i = 1; i <= n; i++){
		sort(v[i].begin(), v[i].end());
	}
	
	
	bfs(1);
	
	for(int i = 1; i <= n; i++){
		if(visited[i] == 2 || visited[i] == 3){
			ct++;
		}
	}
	
	cout << ct;
	
	
	
	

	
	
}
