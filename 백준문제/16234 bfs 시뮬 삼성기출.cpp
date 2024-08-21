#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n, l, r;
int graph[51][51];
int visited[51][51]; 
int dx[4] = {0 , 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ct; // 날짜수 세기 
bool b = false; //연합 존재하면 true 
 
void bfs(int y, int x)   
{
	visited[y][x] = true;
	queue < pair < int, int > > q;
	vector < pair < pair <int, int > , int > >v; // 연합인구계산을위한 저장공간  y와x 좌표값 및 그좌표의값 
    q.push({y, x});
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		v.push_back({{cy, cx} , graph[cy][cx]});
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(ny < 1 || nx < 1 || ny > n || nx > n){
				continue;
			}
			if(!visited[ny][nx] && abs(graph[cy][cx] - graph[ny][nx]) >= l && abs(graph[cy][cx] - graph[ny][nx]) <= r){
				q.push({ny, nx});
				visited[ny][nx] = true;   
				b = true; //연합 존재하면  
			}
		}
	}
	
	int human = 0;  
	for(int i = 0; i < v.size(); i++){ // 좌표값 다 더해주기 
		human = human + v[i].second;
	}
	human = human / v.size();  // 나눠주기 
	 
	for(int i = 0; i < v.size(); i++){
		graph[v[i].first.first][v[i].first.second] = human; // 인구이동 
	}

	 
}

void reset()  //방문초기화 
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			visited[i][j] = false;
		}
	}
}

int main()
{
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	
	while(1){
		b = false;
		reset();
		for(int i = 1; i <= n; i++){
		    for(int j = 1; j <= n; j++){
		    	if(!visited[i][j]){
		    		bfs(i, j);
				}
		    }
	    }
		if(b == false){ // 연합이 존재하지 않으면 
			cout << ct ;
			return 0;
		}
		ct++;	//날짜수 증가	
	}
	  
	  
}
