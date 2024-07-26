#include <iostream>
#include <vector>
using namespace std;

int n, m;
int visited[1001][1001];
char graph[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ans;

void dfs(int y, int x)
{
	if(visited[y][x] == 2){
		return;
	}
	if(visited[y][x] == 1){
		ans++;
		return;
	}
	visited[y][x] = 1;
	if(graph[y][x] == 'R'){
		dfs(y+ dy[0] , x + dx[0]);
	}
	else if(graph[y][x] == 'L'){
		dfs(y+ dy[1] , x + dx[1]);
	}
	else if(graph[y][x] == 'D'){
		dfs(y+ dy[2] , x + dx[2]);
	}
	else if(graph[y][x] == 'U'){
		dfs(y+ dy[3] , x + dx[3]);
	}
	visited[y][x] = 2;
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
			if(visited[i][j] == 2){
				continue;
			}
			dfs(i, j);			
		}
	}
	
	cout << ans << "\n";
}
