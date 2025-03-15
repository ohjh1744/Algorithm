#include <iostream>
#include <queue>
using namespace std;


int n, m;
int h, w;
int sy, sx;
int fy, fx;
int graph[1001][1001];
int visited[1001][1001];
int dp[1001][1001]; 
int dy[4] = { 0, 0, 1, -1};
int dx[4]= {1, -1, 0, 0};

// ���簢�� ���ο� ���� �ִ��� Ȯ�� 
bool check(int y, int x){
	int downRightY = y + (h-1);
	int downRightX = x + (w-1);
	int result = dp[downRightY][downRightX] - dp[downRightY][x-1] - dp[y-1][downRightX] + dp[y-1][x-1];
	 
	// ���� 1���̻��ֵ��� 
	if(result >= 1){
		return false;
	}
	// ���� ���ٸ� 
	else{
		return true;
	}
}

void bfs(int y , int x)
{
	visited[y][x] = true;
	
	queue < pair < int , int> > q;
	
	q.push({y, x});
	
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		//  ���� ���� �����ϸ� ���� 
		if(cy == fy  && cx == fx){
			return;
		}
		
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(ny < 1 || nx < 1 || ny > n - (h - 1) || nx > m - (w - 1)){
				continue;
			}
			
			//nynx�� ������ ���̶�� �Ҷ� ���簢�� ���ο� ���� �ִ��� Ȯ��
			if(check(ny, nx) == false){
				continue;
			} 
			
			if(!visited[ny][nx] && graph[ny][nx] == 0){
				visited[ny][nx] = visited[cy][cx] + 1;
				q.push({ny, nx});
			}
		} 
	}
	
}

int main(){
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	
	cin >> h >> w >> sy >> sx >> fy >> fx;
	
	// �������� ���� i, j �������� 1�� � �ִ��� Ȯ�� 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i][j];
		}
	} 
	
	bfs(sy, sx);
	
	if(visited[fy][fx] == 0){
		cout << -1;
	}
	else{
		cout << visited[fy][fx] - 1;
	}
	
	
}
