#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int  y, x, t;  //y = r , x = c
int graph[51][51];
int dx[4] = {1, -1 , 0 , 0};
int dy[4] = {0 , 0, 1, -1};
vector < pair < int , int > > ac; // 공기청소기 있는 곳 위 아래 저장 
int ans;

void bfs()
{
	queue < pair < int, int > > q;
	vector < pair < int , int > > v; 
	// 미세먼지있는 공간 저장 
	for(int i = 1; i <= y; i++){  
		for(int j = 1; j <=x; j++){
			if(graph[i][j] > 0){
				v.push_back({i, j});
			}
		}
	}
	
	for(int i = 0; i < v.size(); i++){
		q.push({v[i].first, v[i].second});
	}
	
	vector < pair < pair < int , int > , int > > cal; // 나중에 한꺼번에 확산계산 
	
	while(!q.empty()){   // 1초에 확산되는 미세먼지 구현 
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		int dir = 0;
		for(int i = 0; i < 4; i++){
			int ny = cy+ dy[i];
			int nx = cx + dx[i];
			if(ny < 1 || nx < 1 || ny > y || nx > x || graph[ny][nx] == -1){
				continue;
			}
			dir++;
			cal.push_back({{ny, nx} , graph[cy][cx] / 5});	
		}
		cal.push_back({{cy, cx} , -((graph[cy][cx] / 5) * dir)});
	}
	
	for(int i = 0; i < cal.size(); i++){
		int yy = cal[i].first.first;
		int xx = cal[i].first.second;
		int a = cal[i].second;
		graph[yy][xx] = graph[yy][xx] + a;
	}
	
}

void airclean()
{
	int top_ac_y = ac[0].first;
	int top_ac_x = ac[0].second;
	
	int bottom_ac_y = ac[1].first;
	int bottom_ac_x = ac[1].second;
	
	//반시계방향 왼쪽줄 
	for(int i = top_ac_y; i >= 2; i--){
		graph[i][1] = graph[i-1][1];
		if(graph[i][1] == graph[top_ac_y][1]){
			graph[i][1] = -1; //공기청정기 라는 표시를 해서 없애주기 나중에 0이상만 계산  
		}
	}
		
	//반시계방향 맨윗줄 
	for(int i = 1; i <= x-1; i++){
		graph[1][i] = graph[1][i+1];
	}
	
	// 반시계방향 오른쪽 줄
	for(int i = 1; i < top_ac_y; i++){
		graph[i][x] = graph[i+1][x];
	}
	
	// 반시계방향 아래쪽 줄
	for(int i = x; i >= 2; i--){
		graph[top_ac_y][i] = graph[top_ac_y][i-1];
		if(graph[top_ac_y][i] == -1){
			graph[top_ac_y][i] = 0;
		}
	} 
	//////////////////////////////////////////////
	//시계방향 왼쪽줄
	for(int i = bottom_ac_y; i < y; i++){
		graph[i][1] = graph[i+1][1];
		if(graph[i][1] == graph[bottom_ac_y][1]){
			graph[i][1] = -1;
		}
	} 
	
	// 시계방향 아래쪽줄
	for(int i = 1; i <= x-1; i++ ){
		graph[y][i] = graph[y][i+1];
	} 
	
	//시계방향 오른쪽줄
	for(int i = y; i > bottom_ac_y; i--){
		graph[i][x] = graph[i-1][x];
	} 

	//시계방향 맨윗줄
	for(int i = x; i >=2; i--){
		graph[bottom_ac_y][i] = graph[bottom_ac_y][i-1];
		if(graph[bottom_ac_y][i] == -1){
			graph[bottom_ac_y][i] = 0;
		}
	} 

	
}

int main()
{
	cin >> y >> x >> t;
	for(int i = 1; i <= y; i++){
		for(int j = 1; j <=x; j++){
			cin >> graph[i][j];
			if(graph[i][j] == -1){
				ac.push_back({i, j});
			}
		}
	}
	
	for(int i = 0; i < t; i++){
		bfs();
		airclean();
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <=x; j++){
			if(graph[i][j] > 0){
				ans = ans + graph[i][j];
			}
		}
	}
	cout << ans << "\n";
	
	
}
