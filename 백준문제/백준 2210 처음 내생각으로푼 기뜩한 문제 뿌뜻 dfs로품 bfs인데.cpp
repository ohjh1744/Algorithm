#include <iostream>

using namespace std;

bool visited[100][100];
int map[100][100];


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n;
int h = 0;
int temp = 0;

void dfs(int y, int x)
{	
	visited[y][x] = true;
	for(int i=0; i< 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= n || ny >= n){
			continue;
		}
		
		if(visited[ny][nx] == false && map[ny][nx] > h){
			dfs(ny, nx);
		}
		
		
	}
}

void reset()
{
	for(int i =0; i<n; i++){
		for(int j =0; j <n; j++){
			visited[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n;
	
	int ct;
	
	for(int i =0; i <n; i++){
		for(int j =0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
	
	while(h<101){
		for(int i =0; i <n; i++){
		for(int j =0; j < n; j++){
			if(visited[i][j] == false && map[i][j] > h){
				ct++;
				dfs(i, j);
			}
		}
	 }
	 if(temp < ct){
	 	temp = ct;
	 }
	 h++;
	 ct = 0;
	 reset();
	}
	
	cout << temp << endl;
	
	

	
	
}
