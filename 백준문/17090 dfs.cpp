#include <iostream>
using namespace std;

int visited[502][502]; // 0�� �湮 x, -1�� Ż�� x, 1 �� Ż�� 0  
char graph[502][502]; 
int n, m;

int dfs(int y, int x)
{
	if(visited[y][x] != 0){ // Ż����ϰų� Ż���ϴ� ĭ�� ��������� 
		return visited[y][x];
	}	
	visited[y][x] = -1;
	
	if(y < 1 || x < 1 || y > n || x> m){ // Ż���ϸ� 1�� �ٲ��ֱ� 
		visited[y][x] = 1;
	}
	else{
		if(graph[y][x] == 'U'){
		    visited[y][x] = dfs(y-1 , x);
	    }
	    else if(graph[y][x] == 'R'){
		    visited[y][x] = dfs(y , x+1);
	    }
	    else if(graph[y][x] == 'D'){
		    visited[y][x] = dfs(y+1 , x);
	    }
	    else{
		    visited[y][x] = dfs(y , x-1);
     	}
	}
	
	return visited[y][x];
	
}


int main()
{
	cin >> n >> m ;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			 if(visited[i][j] == 0){
			 	dfs(i, j);
			 }
		}
	}
	int ct = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			 if(visited[i][j] == 1){
			 	ct++;
			 }
		}
	}
	cout << ct << endl;
	return 0;
	
}
