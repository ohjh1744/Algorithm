#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int graph[51][51];
int visited[51][51];

int dx[8] = {0 , 0, 1, -1, 1 , -1, -1 , 1};
int dy[8] = {1, -1, 0, 0, 1 , -1 , 1 , -1};

int n, m;
int m_depth = 0;

void bfs(int y, int x)
{
	queue<pair<pair<int, int >, int > > q;
    q.push({{y, x} , 0});

	while(!q.empty()){
		int cx = q.front().first.second;
		int cy = q.front().first.first;
		int ct = q.front().second;
		q.pop();
		
		if(graph[cy][cx] == 1){
			m_depth = max(m_depth , ct);
			return;
		}
		
		for(int i = 0; i < 8; i++){
			int nx = cx + dx[i];
			int ny= cy + dy[i];
			
			if(nx < 1 || ny < 1 || ny > n || nx > m){
				continue;
			}
			if(!visited[ny][nx]){
				visited[ny][nx] = true;
				q.push(make_pair(make_pair(ny, nx), ct+1));
			}
		}
	}
}

void reset()
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			visited[i][j] = 0;
		}
	}
}


int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(graph[i][j] == 0){
				reset();
				bfs(i, j);
			}
		}
	}
	
	cout << m_depth << endl;
}
