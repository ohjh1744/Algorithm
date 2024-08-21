#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m , k;
int r, c;

int dx[] = {1 , -1, 0,  0};
int dy[] = {0 , 0, -1,  1};

int graph[101][101]; // 세로 가로 
int visited[101][101];
int ct;

vector<int> v;

void dfs(int y , int x)
{
	ct++;
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny <= 0 || nx <= 0 || ny > n || nx > m){
			continue;
		}
		if(graph[ny][nx] == 1 && visited[ny][nx] == 0){
			dfs(ny, nx);
		}
	}
}

void reset()
{
	ct = 0;
}

int main()
{
	cin >> n >> m >> k;
	
	for(int i = 0 ; i < k; i++)
	{
		cin >> r >> c;
		graph[r][c] = 1;
	}
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m ; j++){
			if(graph[i][j] == 1 && visited[i][j] == 0){
			  dfs(i, j);
			  v.push_back(ct);
			  reset();
		    }
		}
	}
	
	sort(v.begin(), v.end());
	cout << v.back();
	
	
	
}
