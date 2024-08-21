#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

char graph[101][101];
int visited[101][101] ;

int n , m; //가로 세로 

vector <int> w_c;
vector <int> b_c;

int wct = 0;
int bct = 0;

void w_dfs(int y, int x)
{
	wct++;
	visited[y][x] = true; // y = m , x = n
	for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m ){
			continue;
		}
		
		if(graph[ny][nx] == 'W' && !visited[ny][nx]){
			visited[ny][nx] = 1;
			w_dfs(ny , nx);
		}
	}
	
}

void b_dfs(int y, int x)
{
	bct++;
	visited[y][x] = true; // y = m , x = n
	for(int i = 0 ; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m ){
			continue;
		}
		
		if(graph[ny][nx] == 'B' && !visited[ny][nx]){
			visited[ny][nx] = 1;
			b_dfs(ny , nx);
		}
	}
	
}

void reset(){
	wct = 0;
	bct = 0;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >>  m; //가로 세로  4 2 
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){  //저장은 웬만해서 가로형태로 하자 
			cin >> graph[i][j] ;    
		}
	}
	
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < m ; j++){
	        if(graph[j][i] == 'W' && !visited[j][i]){
	        	w_dfs(j, i);
			    w_c.push_back(wct);
				reset(); 
			}
			if(graph[j][i] == 'B' && !visited[j][i]){
	        	b_dfs(j, i);
			    b_c.push_back(bct);
				reset(); 
			}
		}
	}
	
	int w_temp = 0;
	int b_temp = 0;
	
	
	
	for(int i = 0 ; i < w_c.size(); i++){
	   	w_temp = w_temp + (w_c[i] * w_c[i]);
	}
	
	for(int i = 0 ; i < b_c.size(); i++){
	   	b_temp = b_temp + (b_c[i] * b_c[i]);
	}
	
	cout << w_temp << " " << b_temp;
	

	
	return 0;
}
