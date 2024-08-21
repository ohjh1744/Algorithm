#include <iostream>
using namespace std;

int n;

int visited[101][101];
char graph[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int red = 0, blue = 0 , green = 0 , rg = 0;

void dfs_r(int y ,int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > n){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == 'R'){
			dfs_r(ny, nx);
		}
	}
}

void dfs_b(int y ,int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > n){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == 'B'){
			dfs_b(ny, nx);
		}
	}
}

void dfs_g(int y ,int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > n){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == 'G'){
			dfs_g(ny, nx);
		}
	}
}

void dfs_rg(int y ,int x)   //ภ๛ณ์ 
{
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > n || ny > n){
			continue;
		}
		if(!visited[ny][nx] && (graph[ny][nx] == 'G' || graph[ny][nx] == 'R' )){
			dfs_rg(ny, nx);
		}
	}
}

void reset()
{
	red = 0, blue = 0 , green = 0 , rg = 0;
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n ; j++){
			visited[i][j] = 0;
		}
	}	
} 


int main()
{
	cin >> n;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n ; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n ; j++){
			if(!visited[i][j] && graph[i][j] == 'R'){
				red++;
				dfs_r(i, j);
			}
			else if(!visited[i][j] && graph[i][j] == 'B'){
				blue++;
				dfs_b(i, j);
			}
			else if(!visited[i][j] && graph[i][j] == 'G'){
				green++;
				dfs_g(i, j);
			}
		}
	}
	
	cout << red + blue + green << " ";
	reset();
	
    for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n ; j++){
			if(!visited[i][j] && (graph[i][j] == 'G' || graph[i][j] == 'R' )){
				rg++;
				dfs_rg(i, j);
			}
			else if(!visited[i][j] && graph[i][j] == 'B'){
				blue++;
				dfs_b(i, j);
			}
		}
	}
	
	cout << rg + blue << endl;
	
}


