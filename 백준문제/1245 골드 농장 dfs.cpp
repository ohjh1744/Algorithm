#include <iostream>
using namespace std;

int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

int n, m;
int graph[101][71];
int visited[101][71];

int ct = 0;
bool peak = true;

void dfs(int y , int x){
	visited[y][x] = true;
    for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || ny > n || nx > m){
			continue;
		}
		
		if(graph[y][x] < graph[ny][nx]){ //자기보다 큰 봉우리만나면 봉우리아님 
			peak = false;
		}
		
		if(visited[ny][nx]){
			continue;
		}
		
		if(graph[y][x] == graph[ny][nx]){ //자기랑 같은 높이의 봉우리만나면 조사 
			dfs(ny, nx);
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
			if(!visited[i][j]){
				peak = true;
				dfs(i, j);
				if(peak){
					ct++;
				}
			}
		}
	}
	cout << ct << endl;
} 
