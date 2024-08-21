#include <iostream>
using namespace std;

int t, h, w;
int visited[101][101];
char graph[101][101];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 1 || nx < 1 || ny > h || nx > w){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == '#'){
			dfs(ny, nx);
		}
	}
	
}

void reset()
{
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <=w; j++){
			visited[i][j] = 0;
		}
	}
}

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> h >> w;
		int ct = 0;
		for(int j = 1; j <= h; j++){
			for(int z = 1; z <= w; z++){
				cin >> graph[j][z];
			}
		}
		
		for(int j = 1; j <= h; j++){
			for(int z = 1; z <= w; z++){
				if(!visited[j][z] && graph[j][z] == '#'){
					ct++;
					dfs(j, z);
				}
			}
		}
		cout << ct << endl;
		reset();
	}
	
}
