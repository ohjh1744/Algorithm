#include <iostream>
using namespace std;

int graph[1001][1001];
int visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1 ,0, 0};
int n, m, t;
int ans;

void dfs(int y, int x){
	
	visited[y][x] = true;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= n || nx >= m){
			continue;
		}
		
		if(visited[ny][nx] == false && graph[ny][nx] == 255){
			dfs(ny, nx);
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int r, g, b;
			cin >> r >> g >> b;
			graph[i][j] = (r+g+b)/3;
		}
	}
	
	cin >> t;
	// t�� ��հ����ؼ� ũ�ų� ������  255�� �ƴϸ� 0���� ��ȯ 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(t <= graph[i][j]){
				graph[i][j] = 255;
			}
			else{
				graph[i][j] = 0;
			}
		}
	}
	
	// dfsŽ���ؼ� ���� � �������� Ȯ�� 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j] == false && graph[i][j] == 255){
				ans++;
				dfs(i,j);
			} 
		}
	}
	
	cout << ans ;	
}
