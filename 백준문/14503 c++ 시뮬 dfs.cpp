#include <iostream>
using namespace std;

int n, m;
int r, c, d; 
int dy[4] = {-1, 0, 1 , 0}; // 0  1  2  3
int dx[4] = {0 , 1 , 0 ,-1};  // 북 동 남 서 

int graph[50][50];
int visited[50][50];
int ct = 0;

void dfs(int y , int x , int cd)
{
	if(!visited[y][x] && graph[y][x] == 0){ 
		ct++;
	}
	visited[y][x] = true;
	
	for(int i = 0; i < 4; i++){  
		int nd = (cd + 3 - i) % 4;  // 현재 방향에서  왼쪽 순체크해서 청소공간잇으면 앞으로나아감, 없으면 방향돌리기 
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
			continue;
		}
		
		if(!visited[ny][nx] && graph[ny][nx] == 0){ 
			dfs(ny, nx, nd);
		}		
	}
	// 포문을 다거치면 다시 현재 바라보는 방향으로 돌아옴. 즉, 4방향  이미청소되거나, 벽인경우 
	int nd = (cd + 2) % 4;	// 뒤로 이동 
	if(graph[y+ dy[nd]][x+ dx[nd]] == 1){
		cout << ct << endl;
		exit(0); 
	}
	else{
		dfs(y+ dy[nd] , x+ dx[nd] , cd);
	}
}

int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;	

	for(int i = 0; i < n; i++){
		for( int j = 0; j < m; j++){
			cin >> graph[i][j];
		}
	}
		
	dfs(r, c, d);
	return 0;
	
}
