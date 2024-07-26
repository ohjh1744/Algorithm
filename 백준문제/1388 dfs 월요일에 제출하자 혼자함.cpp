#include <iostream>
using namespace std;

char graph[51][51];
int visited[51][51];

int n, m; // 세로 , 가로 
int f_ct, s_ct; // ㅡ개수, l 개수 

int dx[4] = {1, -1 , 0 , 0}; 
int dy[4] = {0, 0 , 1 , -1};

void f_dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 2; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx <= 0 || ny <= 0 || nx > m || ny > n){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == '-'){
			f_dfs(ny, nx);
		}
	}	
}

void s_dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i = 2; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx <= 0 || ny <= 0 || nx > m || ny > n){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == '|'){
			s_dfs(ny, nx);
		}
	}	
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
			if(!visited[i][j] && graph[i][j] == '-'){
			  f_dfs(i, j);
			  f_ct++;
		    }
			
			else if(!visited[i][j] && graph[i][j] == '|'){
			  s_dfs(i, j);
			  s_ct++;
		    }
		}
	}
	
	cout << f_ct + s_ct << endl;
	
	
}
