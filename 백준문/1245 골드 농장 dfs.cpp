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
		
		if(graph[y][x] < graph[ny][nx]){ //�ڱ⺸�� ū ���츮������ ���츮�ƴ� 
			peak = false;
		}
		
		if(visited[ny][nx]){
			continue;
		}
		
		if(graph[y][x] == graph[ny][nx]){ //�ڱ�� ���� ������ ���츮������ ���� 
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
