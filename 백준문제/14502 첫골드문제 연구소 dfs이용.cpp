#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

int dx[4] = {0 , 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int graph[8][8];
int visited[8][8];
int virus = 0;
int alive;
int ans = 0;

void dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i =0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx <0 || ny >= n || nx >= m){
			continue;
		}
		if(!visited[ny][nx] && graph[ny][nx] == 0){
			virus++;
			dfs(ny, nx);
		}
	}
}

void reset(){
	for(int i =0; i < n; i++){
		for(int j = 0; j < m; j++){
			visited[i][j] = 0;
		}
	}
}


void solve(int wall) //w = 3  0�̵Ǹ� �� 3�� �� ��ġ 
{

	if(wall == 0){
		virus = 0;
		reset(); // �湮 �ʱ�ȭ 
		for(int i = 0; i < n; i++){
			for(int j =0; j < m; j++){
				if(!visited[i][j] && graph[i][j] == 2){
					dfs(i, j);
				}
			}
		}
		ans = max( ans , alive - virus);
		return ;
	}
	
	else{
		for(int i = 0; i < n; i++){
		  for(int j= 0; j < m; j++){
			if(graph[i][j] == 0){
				graph[i][j] = 1;
				solve(wall-1);
				graph[i][j] = 0; // �� �ʱ�ȭ 
			}
		  }
	    }
	}
}

  // // �ֺ� 3 -> �ֺ�2 -> �ֺ� 1 -> �ֺ� 0 return -> �ֺ� 1 ����������ӵ��ư� -> ������ �ֺ� 2 i �� �Ѿ -> �ٽ� �ֺ�1 �������� ���� 
  //-> �ֺ�1�� �������� ������ �ֺ� 2 i�� �Ǵٽ� �Ѿ -> �ݺ��ؼ� �ֺ�2�� ���������� ������ -> �ֺ� 1 �� i�� �Ѿ -> ��÷���� ���ư� �ٽ� �ݺ�  �̷������� 3���� ��ġ�� ���ٲ� 

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j= 0; j < m; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 0){
				alive++;
			}
		}
	}
	
	alive = alive - 3; // ���� 3�������߹Ƿ� 
	solve(3);
	
    cout << ans << endl;
	
	
	
	
	
}
