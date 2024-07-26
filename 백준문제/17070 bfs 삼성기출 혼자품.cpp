#include <iostream>
#include <queue>
using namespace std;

int graph[17][17];
int dy[3] = {0,1,1}; //오른쪽 대각선 아래 
int dx[3] = {1,1,0}; //  0      1     2
int ct;
int n;

void bfs()
{
	queue < pair < pair < int, int >, int > > q; //y x 보는방향 
	q.push({{1, 2} , 0});
	while(!q.empty()){
		int cy = q.front().first.first;
		int cx = q.front().first.second;
		int cd = q.front().second;
		q.pop();
		
		if( cy == n && cx == n){
			ct++;
		}
		
		for(int i = 0; i < 3; i++){
			if(cd == 0){ // 오른쪽일때 아래제외 
				if(i == 2){
					continue;
				}
			}
			else if( cd == 2){ // 아래일때 오른쪽 제외 
				if( i == 0){
					continue;
				}
			}
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			// 크기를 넘어가거나 놓을곳에 벽이있다면 불가 
			if(ny < 1 || nx < 1 || ny > n || nx > n || graph[ny][nx] == 1){
			   continue;
		    }
		    if(i == 1){ //오른쪽이나 아래에 벽이있다면 대각선 불가 
		    	if(graph[cy + dy[0]][cx + dx[0]] == 1 || graph[cy + dy[2]][cx + dx[2]] == 1){
		    		continue; 
				}
			}
			q.push({{ny, nx}, i}); 
			
		}
	}
}



int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	bfs();
	cout << ct << "\n";
	
}
