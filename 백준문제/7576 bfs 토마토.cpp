#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n; // 가로 세로 
int visited[1001][1001];
int graph[1001][1001];
vector < pair <int, int > > v; // 익은 토마토 저장공간 
int dx[4] = {0 , 0 , 1 , -1};
int dy[4] = {1 , -1, 0, 0};
int ans;
void bfs()
{
	queue < pair <pair < int, int > , int > > q;
	for(int i = 0; i < v.size(); i++){
		q.push({{v[i].first, v[i].second} , 0});
	}
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int ct = q.front().second;
		ans = ct;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 1 || nx < 1 || ny > n || nx > m){
				continue;
			}
			if(!visited[ny][nx] && graph[ny][nx] == 0){
				q.push({{ny, nx} , ct + 1});
				visited[ny][nx] = true;
			}
		}
	}
	
}

int main()
{
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 1){
				v.push_back({i, j}); // 익은 토마토 위치 저장 
				visited[i][j] = true;
			}
			else if(graph[i][j] == -1){
				visited[i][j] = true;   // 벽인곳은  방문체크해주기 
			}
		}
	}
	
	bool full_tomato = true;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(visited[i][j] == false){  // 모두 익은 상태인지 확인 
			   full_tomato = false;			
			}
		}
	}
	if(full_tomato){  //다익은상태면 0 출력 
		cout << 0 ;
		return 0;
	}
	
	bfs();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(visited[i][j] == 0){ //안익은 토마토가 있다면 -1 출력 
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
	
}
