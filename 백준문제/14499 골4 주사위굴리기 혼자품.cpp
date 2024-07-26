#include <iostream>
using namespace std;

int n, m; //세로 가로 
int x, y;
int k;

int dice[7] = {0 ,0 ,0 ,0 ,0 ,0 ,0}; // 0빼고 1~6사용
int graph[21][21];
int dy[4] = {0 , 0, -1, 1}; //동 서 남 북 
int dx[4] = {1 , -1, 0, 0};

void roll(int dir) // dir는 굴리는 방향 
{
	int temp[7];
	for(int i = 1; i <= 6; i++){
		temp[i] = dice[i];
	}
	if(dir == 1){
		dice[1] = temp[4];
		dice[2] = temp[2];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[5] = temp[5];
		dice[6] = temp[3];
	}
	else if(dir == 2){
		dice[1] = temp[3];
		dice[2] = temp[2];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[5] = temp[5];
		dice[6] = temp[4];
	}
	else if(dir == 3){
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[3] = temp[3];
		dice[4] = temp[4];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	else if(dir == 4){
		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[3] = temp[3];
		dice[4] = temp[4];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}
}
	
int main()
{
	cin >> n >> m >> y >> x >> k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j];
		}
	}
	
    for(int i = 0; i < k; i++){
    	int num;
    	cin >> num;
    	y = y + dy[num-1];
    	x = x + dx[num-1];
    	
    	// 바깥이동명령일경우 무시 
		if(y >= n || x >= m || y < 0 || x < 0){
			y = y - dy[num-1];
    	    x = x - dx[num-1];
    	    continue;
		}
		
		roll(num);
		// 이동한 지도의 바닥이 0일경우 
		if(graph[y][x] == 0){
			graph[y][x] = dice[6];
		}
		else{  // 0이 아닐경우 
			dice[6] = graph[y][x];
			graph[y][x] = 0;
		}
		
		cout << dice[1] << "\n";		 		 
	}
	 
}
