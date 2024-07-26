#include <iostream>
using namespace std;


int dx[4] = {1, -1, 0 , 0};
int dy[4] = {0, 0, 1, -1};

int visited[50][50];
int map[50][50];


int t, m, n , k;
int ct = 0;

void dfs(int x, int y)
{
  visited[x][y] = 1;
  for(int i=0; i < 4 ; i++){
  	int nx = x + dx[i];
  	int ny = y + dy[i];
  	if(nx < 0 || nx >= m || ny <0 || ny >= n){
  		continue;
	}
	if(map[nx][ny] == 1 && visited[nx][ny] == false){
		dfs(nx, ny);
	}
	
  }
}

void reset()
{
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			map[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			visited[i][j] = 0;
		}
	}
	ct = 0;
}



int main(){

	int x, y;
	cin >> t;
		
	for(int i = 0 ; i < t; i++){
		cin >> m >> n >> k;
	  for(int j = 0 ; j < k; j++){
		cin >> x >> y;
		map[x][y] = 1;
	  }
	
	for(int i = 0; i < m; i++){
   	for(int j = 0; j < n; j++){
   		if(map[i][j] == 1 && visited[i][j] == false){
   			dfs(i,j);
   			ct++;
		   }
	   }
    }
    cout << ct << endl;
    reset();
    
    }
    
    
		
	
} 
