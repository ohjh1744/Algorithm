#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0 , 0 , 1, -1};
int dy[] = {1, -1, 0 , 0};

int graph[1001][1001];
int visited[1001][1001];

int M , N; // y x

bool ans = false;

void bfs(int y, int x)
{
	visited[y][x] = true;
	queue < pair< int, int> > q;
	q.push({y , x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		
		if(cy == M){
			ans = true;
			break;
		}
		
		for(int i =0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if(ny <= 0 || nx <= 0 || ny > M || nx > N){
				continue;
			}
			
			if(!visited[ny][nx] && graph[ny][nx] == 0){
				q.push({ny, nx});
				visited[ny][nx] = true;
			}
		}
	}
	
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N ;
	
	for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }
	
	for(int i = 1; i <= N; i++){
		if(!visited[1][i] && graph[1][i] == 0){
				bfs(1, i);
			}
	}
	
	if(ans){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	
}


