#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int dx[4] = {0 , 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int graph[8][8];
int visited[8][8];
int virus = 0;
int alive;
int ans = 0;

void dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i =0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx <0 || ny >= n || nx >= m){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == 0){
			virus++;
			dfs(ny, nx);
		}
	}
}

void reset(){
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			visited[i][j] = 0;
		}
	}
}


void solve(int wall) //w = 3  0이되면 벽 3개 다 설치 
{

	if(wall == 0){
		virus = 0;
		reset(); // 방문 초기화 
		for(int i = 0; i < n; i++){
			for(int j =0; j < m; j++){
				if(!visited[i][j] && graph[i][j] == 2){
					dfs(i, j);
				}
			}
		}
		ans = max( ans , alive - virus);
		return ;
	}
	
	else{
		for(int i = 0; i < n; i++){
		  for(int j= 0; j < m; j++){
			if(graph[i][j] == 0){
				graph[i][j] = 1;
				solve(wall-1);
				graph[i][j] = 0; // 벽 초기화 
			}
		  }
	    }
	}
}

  // // 솔브 3 -> 솔브2 -> 솔브 1 -> 솔브 0 return -> 솔브 1 이중포문계속돌아감 -> 끝나면 솔브 2 i 가 넘어감 -> 다시 솔브1 이중포문 시작 
  //-> 솔브1의 이중포문 끝나면 솔브 2 i가 또다시 넘어감 -> 반복해서 솔브2의 이중포문이 끝나면 -> 솔브 1 의 i가 넘어감 -> 맨첨으로 돌아가 다시 반복  이런식으로 3개의 위치가 계쏙바뀜 

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j= 0; j < m; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 0){
				alive++;
			}
		}
	}
	
	alive = alive - 3; // 벽을 3개세워야므로 
	solve(3);
	
    cout << ans << endl;
	
	
	
	
	
}
