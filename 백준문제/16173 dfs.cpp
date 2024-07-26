#include <iostream>
using namespace std;

int visited[65][65];
int graph[65][65];

int dx[2] = {1 , 0};
int dy[2] = {0 , 1};

int n;

void dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 2; i++){
		int nx = x + (dx[i] * graph[y][x]);
		int ny = y + (dy[i] * graph[y][x]);
		
		if(ny < 1 || nx < 1 || ny > n || nx > n){
			continue;
		}
		if(!visited[ny][nx]){
			dfs(ny, nx);
		}		
	}
}


int main()
{
	cin >> n;
   	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <=n; j++){
			cin >> graph[i][j];
		}
	}
	
	if(graph[1][1] > 0){
		dfs(1, 1);
	}
	
	if(visited[n][n] == true){
		cout << "HaruHaru" << endl;
	}
	else{
		cout << "Hing" << endl;
	}	
	
}
