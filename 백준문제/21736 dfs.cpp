#include <iostream>
using namespace std;

int n, m;
int visited[601][601];
char graph[601][601];

int dx[4] = {0 , 0, 1, -1};
int dy[4] = {1 , -1, 0, 0};
int ct = 0;

void dfs(int y, int x)
{
	visited[y][x] = true;
	if(graph[y][x] == 'P'){
		ct++;
	}
	for(int i =0; i <4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 1 || nx < 1 || ny > n || nx > m){
			continue;
		}
		if((!visited[ny][nx] && graph[ny][nx] == 'O') || (!visited[ny][nx] && graph[ny][nx] == 'P')){
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m ; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m ; j++){
			if(graph[i][j] == 'I'){
				dfs(i, j);
			}
		}
	}
	
	if(ct == 0){
		cout << "TT" << endl;
	}
	else{
		cout << ct << endl;
	}
	
}
