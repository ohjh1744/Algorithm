#include <iostream>
using namespace std;


int dx[] = {0, 0, 1 , -1, 1, -1, 1 , -1};
int dy[] = {1, -1, 0 , 0, 1, -1, -1, 1};

int graph[251][251];
int visited[251][251];

int m , n; // y x

void dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 8; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny <= 0 || nx <= 0 || ny > m || nx > n){
			continue;
		}  
		if(!visited[ny][nx] && graph[ny][nx] == 1){
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	
	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	
	int ct = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(!visited[i][j] && graph[i][j] == 1){
			  ct++;
			  dfs(i, j);
		    }
		}
	}
	
	cout << ct << endl;
		
}
