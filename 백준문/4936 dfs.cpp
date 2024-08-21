#include <iostream>

using namespace std;

bool visited[50][50];
int map[50][50];

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};


int h; //세로 
int w; // 가로 

void dfs(int y, int x)
{
	visited[y][x] = true;
	for(int i=0; i< 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= w || ny >= h){
			continue;
		}
		if(map[ny][nx] == 1 && visited[ny][nx] == 0){
			dfs(ny, nx);
		}
	}
}

void reset()
{
	for(int i =0; i<h; i++){
		for(int j =0; j <w; j++){
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

int main()
{
  	while(true){
  	    reset();
		cin >> w >> h;
		
		if(w == 0 && h == 0){
			break;
		} 
		
		for(int i = 0; i <h ; i++){
			for(int j =0; j < w; j++){
				cin >> map[i][j];
			}
		} 
		
		int ct =0;
		for(int i = 0; i <h ; i++){
			for(int j =0; j < w; j++){
				if(map[i][j] == 1 && visited[i][j] == false){
					ct++;
					dfs(i, j);
				}
			}
		} 
		cout << ct << endl;	
	}
	
	
	
	
	
} 
