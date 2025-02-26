#include <iostream>
#include <queue>
using namespace std;

int n;
int m;
int graph[101][101];
int breakWall[101][101]; 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int y, int x){
	
	breakWall[y][x] = 0;
	queue < pair < int, int > > q;
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
			
			if(graph[ny][nx] == 1){
				if(breakWall[ny][nx] > breakWall[cy][cx] + 1){
					breakWall[ny][nx] = breakWall[cy][cx] + 1;
					q.push({ny, nx});
				}			
			}
			else if(graph[ny][nx] == 0){
				if(breakWall[ny][nx] > breakWall[cy][cx]){
					breakWall[ny][nx] = breakWall[cy][cx];
					q.push({ny, nx});
				}
			}			
		}
	}
}
 
int main(){
	cin >> m >> n;
	
	for(int i = 1; i<= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%1d", &graph[i][j]);
			breakWall[i][j] = 999999;
		}
	}
	
	bfs(1, 1);
	
	cout << breakWall[n][m];

}
