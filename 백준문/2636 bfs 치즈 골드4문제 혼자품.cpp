#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; //세로 가로 
int dx[4] = { 0 , 0 , -1, 1};
int dy[4] = { -1, 1, 0 , 0};
int visited[101][101];
int graph[101][101];

int ct = 0; // 시간체크 
int piece = 1;  // 조각 몇개 

vector < pair < int, int> > v; //시간과 1시간 전의 남은 치즈조각 저장 

void bfs(int y, int x) //바깥공기 2로 바꾸기 
{
	visited[y][x] = true;
	graph[y][x] = 2;
	queue <pair <int, int> > q;
	q.push({y, x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		
		for(int i =0; i < 4; i++){
			int f_y = cy + dy[i];
			int f_x = cx + dx[i];
			if(graph[f_y][f_x] == 1){  // 바깥공기접촉한 치즈 4로바꾸기 
				graph[f_y][f_x] = 4;
			}
		}
		
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 1 || nx < 1 || ny > n || nx > m){
				continue;
			}
			if(graph[ny][nx] == 0 && visited[ny][nx] == false){
				graph[ny][nx] = 2;
				q.push({ny, nx});
				visited[ny][nx] = true;
			}
		}
	}
}

void reset()
{
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			visited[i][j] = false;
		}
	}
} 

int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	
	while(piece > 0){
		reset();
		bfs(1, 1);
		piece = 0;
		for(int i = 1; i <= n ; i++){
		    for(int j = 1; j <= m; j++){
			   if(graph[i][j] == 2){
				 graph[i][j] = 0;
			   }
			   if(graph[i][j] == 4){
			   	piece++;
			   	graph[i][j] = 0;
			   }
			   if(graph[i][j] == 1){
			   	piece++;
			   }
		    }
	    }
	    ct++;
	    v.push_back({ct, piece});
	} 
	
	sort(v.rbegin(), v.rend());
	
	cout << v[1].first << endl;
	cout << v[1].second;
	
}
