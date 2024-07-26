#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int m, n , h; // 가로 세로  z
int visited[101][101][101];
int graph[101][101][101];
vector < pair< pair <int, int > , int > > v; // 익은 토마토 저장공간 y x z
int dz[6] = {0 , 0 , 0 , 0 , 1 , -1};
int dx[6] = {0 , 0 , 1 , -1 , 0 , 0};
int dy[6] = {1 , -1, 0, 0 , 0 , 0};
int ans;
void bfs()
{
	queue < pair < pair< int, int > , pair < int, int >  > > q; // y x  z 시간 
	for(int i = 0; i < v.size(); i++){
		q.push({{v[i].first.first, v[i].first.second} , {v[i].second , 0}});
	}
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cz = q.front().second.first;
		int ct = q.front().second.second;
		ans = ct;
		q.pop();
		for(int i = 0; i < 6; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nz = cz + dz[i];
			if(ny < 1 || nx < 1 || nz < 1 || ny > n || nx > m || nz > h){
				continue;
			}
			if(!visited[nz][ny][nx] && graph[nz][ny][nx] == 0){
				q.push({{ny, nx} , {nz , ct+1}});
				visited[nz][ny][nx] = true;
			}
		}
	}
	
}

int main()
{
	cin >> m >> n >> h;
	for(int k = 1 ; k <= h; k++){
		for(int i = 1; i <= n; i++){
		   for(int j = 1; j <= m; j++){
			   cin >> graph[k][i][j];
		       if(graph[k][i][j] == 1){
				  v.push_back({{i, j} , k}); // 익은 토마토 위치 저장 
				  visited[k][i][j] = true;
			   }
			   else if(graph[k][i][j] == -1){
				visited[k][i][j] = true;   // 벽인곳은  방문체크해주기 
			   }
		   }
	    }
    }
	
	bool full_tomato = true;
	for(int k = 1; k<= h; k++){
		for(int i = 1; i <= n; i++){
		    for(int j = 1; j <= m; j++){
			   if(visited[k][i][j] == false){  // 모두 익은 상태인지 확인 
			      full_tomato = false;			
			    }
		    }
	    }
	}
	if(full_tomato){  //다익은상태면 0 출력 
		cout << 0 ;
		return 0;
	}
	
	bfs();
	for(int k = 1; k <= h; k++){
		for(int i = 1; i <= n; i++){
		   for(int j = 1; j <= m; j++){
			   if(visited[k][i][j] == 0){ //안익은 토마토가 있다면 -1 출력 
				  cout << -1;
				  return 0;
			    }
		    }  
	    }
	}
	cout << ans;
	return 0;
	
}
