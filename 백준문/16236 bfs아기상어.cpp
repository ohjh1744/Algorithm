#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[21][21];
int visited[21][21];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
int bs_size = 2;
int eat_ct;
int near_d;
int near_x;
int near_y;
bool b = false; // 더이상 먹을 먹이 있는지 확인
int bs_y;  //아기상어 위치 저장. 
int bs_x; 
int ans;

// 이 문제는 거리순, y순, x순으로 최소힙으로 저장하면 쉬움
 
void bfs(int y, int x) //가장가까운먹이찾기 
{
	visited[y][x] = true;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //가까운먹이저장 
	queue< pair< int, pair < int, int > > > q; //이동가능구역
	q.push({0, {y, x}});
	while(!q.empty()){
		int cd = q.front().first;
		int cy = q.front().second.first;
		int cx = q.front().second.second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int nd = cd + 1;
			int ny = cy + dy[i];
			int nx = cx + dx[i];			
			if(ny < 1 || nx < 1 || ny > n || nx > n){
				continue;
			}
			if(!visited[ny][nx] && graph[ny][nx] <= bs_size){   // 아기상어보다 크기가 같거나 작으면 칸지나갈수있음. 
				q.push({nd,{ny ,nx}});
				visited[ny][nx] = true;
				if(graph[ny][nx] > 0 && graph[ny][nx] < bs_size){ //아기상어보다 크기가 작으면 먹을수있으니 pq에 저장. 
					pq.push({nd,{ny ,nx}});
				} 
			}			
		}				
	}
	
	if(pq.empty()){ //먹을 먹이가 없다면 
		b = true;
		return;
	}
	
	near_d = pq.top().first;
	near_y = pq.top().second.first;
	near_x = pq.top().second.second;
}

void reset()
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			visited[i][j] = false;
		}
	}
	graph[bs_y][bs_x] = 0; //원래 아기상어위치 0으로바꿔줌. 
	bs_y = near_y;  //아기상어위치 바꿔줌 
	bs_x = near_x; 	
	graph[bs_y][bs_x] = 9; //아기상어위치 9로바꿔줌.  
}


int main()
{
	cin >> n;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			cin >> graph[i][j];
			if(graph[i][j] == 9){
				bs_y = i;
				bs_x = j;
			}
		}
	}
	
	while(1){
		bfs(bs_y, bs_x);		
		if(b){			
			break;
		}
		ans = ans + near_d;
		eat_ct++; // 먹은 먹이갯수늘려주기 
		if(eat_ct == bs_size){ 
			bs_size++;
			eat_ct = 0;
		}
		reset();
	}
	
	cout << ans << "\n"; 
	
}
