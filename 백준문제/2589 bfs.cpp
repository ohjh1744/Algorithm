#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char graph[51][51];
int visited[51][51];

int n, m;
int island = 0;
void bfs(int y , int x)
{
	visited[y][x] = true;
	queue <pair < pair <int, int> , int> > q;
	q.push({{y , x} , 0});
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cl = q.front().second;
		q.pop();
		island = max(island, cl);
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny <1 || nx < 1 || ny > n || nx > m){
				continue;
			}
			if(!visited[ny][nx] && graph[ny][nx] == 'L'){
				q.push({{ny, nx}, cl+1});
				visited[ny][nx] = true;
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
			cin >>graph[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(graph[i][j] == 'L'){
				bfs(i,j);
			}
			reset();
		}
	}
	cout << island << endl;
}



