#include <iostream>
#include <queue>
using namespace std;

int visited[51][51];
int graph[51][51];

int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int y , int x)
{
	queue <pair < pair < int, int> , int> > q;
	q.push({{y,x}, 0});
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int ct = q.front().second; // 현재 여기까지 오는데 방바꾼수 
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nt = visited[ny][nx];
			if( ny < 1 || nx < 1 || ny > n || nx > n){
				continue;
			}
			if(ct < nt ){ // ex) ct = 1, nx = 0이면 queuepush 안함 , ct가 다음방으로 가기위한 방바꾸기 수보다 작다면 
				if(graph[ny][nx] == 1){
				  q.push({{ny, nx}, ct});
				  visited[ny][nx] = ct;
			    }
			    if(graph[ny][nx] == 0){
				  q.push({{ny, nx} , ct + 1});
				  visited[ny][nx] = ct + 1;
			    }
			}
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j<=n ; j++){
			scanf("%1d", &graph[i][j]); 
			visited[i][j] = 99999; // 임의로 큰수 지정  
		}
	}
	bfs(1, 1);
	cout << visited[n][n] << endl; 
}
