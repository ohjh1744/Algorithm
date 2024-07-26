#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n , m;
int graph[50][50]; 
bool sel[2500]; // combi 에서 사용하는 bool 
vector<int> v; // 2인 곳 저장 

int visited[50][50]; // 최초바이러스와 벽은 0, 감염안된곳은 -1 
int dx[4] = {0 , 0, -1, 1};
int dy[4] = {1 , -1, 0, 0};

int ans = 99999999; 

bool spread() //벽을제외한 모두 감염됫는지 확인 
{
	for(int i = 0; i < n; i++){    
		for(int j = 0; j < n; j++){
			if(visited[i][j] == -1){
				return false;
			} 
		}
	}
	return true;
}

int bfs() //시간 구하기 
{
	queue < pair < int, int > > q;
	int t_s = 0; 
	for(int i = 0; i < n; i++){    //벽을 제외한 곳 모두 visited -1로 초기화 
		for(int j = 0; j < n; j++){
			if(graph[i][j] != 1){
				visited[i][j] = -1;
			} 
		}
	}
	for(int i = 0 ; i < v.size(); i++){
		if(sel[i] == true){
			int y = v[i] / n;
			int x = v[i] % n;
			q.push({y, x});
			visited[y][x] = 0;
		}
	}
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 0 || nx < 0 || ny >=n || nx >= n){
				continue;
			}
			if(visited[ny][nx] == -1 && graph[ny][nx] != 1){
				q.push({ny, nx});
				visited[ny][nx] = visited[cy][cx] + 1;
				t_s = visited[ny][nx];  //맨 마지막에 감연되는칸이 모든 빈칸 감염시키는데 최소걸리는 시간
			}
		}
		
	}
	
	return t_s;
	
}


void combi(int idx, int cnt)
{
	if(cnt == m){
		int spread_time = bfs();
		if(spread()){
			if(ans > spread_time){
				ans = spread_time;
			}
		}
		return;
	}
	
	for(int i = idx; i < v.size(); i++){
		if(sel[i] == true){
		   continue;
		}
		sel[i] = true;
		combi(i, cnt+1);
		sel[i] = false;
	}	
}

int main()
{
	cin >> n >> m;
	int ct = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 2){
				v.push_back(ct);
			}
			ct++;
		}
	}

	combi(0, 0);
	
	if(ans == 99999999){
		cout << "-1" << endl;
	}
	else{
		cout << ans << endl;
	}
	
}
