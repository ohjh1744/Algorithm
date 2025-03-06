#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
int visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int startY, startX;

void bfs(int y, int x){
		
	visited[y][x] = 0;
	
	queue < pair < int , int > > q;
	
	q.push({y, x});
	
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(ny < 1 || nx < 1 || ny > n || nx > m){
				continue;
			} 
			
			if(visited[ny][nx] == false && graph[ny][nx] == 1){
				visited[ny][nx] = visited[cy][cx] + 1;
				q.push({ny, nx});
			}
		}
	}

}


int main(){
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 2){
				startY = i;
				startX = j;
			}
		}
	}
	
	bfs(startY, startX);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//방문하지 못하는 갈 수 있는 땅의 경우 
			if(visited[i][j] == 0 && graph[i][j] == 1){
				cout << -1 << " "; 
			}
			else{
				cout << visited[i][j] << " ";
			}
		}
		cout << "\n";
	}
}
