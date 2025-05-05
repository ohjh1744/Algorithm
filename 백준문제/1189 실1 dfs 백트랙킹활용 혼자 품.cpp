#include <iostream>
#include <vector>
using namespace std;

char graph[6][6]; 
int visited[6][6];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int r, c, k;
int ans;

void dfs(int y, int x , int ey, int ex, int cnt){
	visited[y][x] = true;
	
	if(y == ey && x == ex && cnt == k){
		ans++;
	}
	for(int i = 0; i< 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= r || nx >= c){
			continue;
		}
		
		if(visited[ny][nx] == false && graph[ny][nx] != 'T'){
			dfs(ny, nx, ey, ex, cnt+1);
			visited[ny][nx] = false;
		}
	}
}

int main(){
	
	cin >> r >> c >> k;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> graph[i][j];
		}
	}
	
	dfs(r-1, 0, 0, c-1, 1);
	
	cout << ans;
}
