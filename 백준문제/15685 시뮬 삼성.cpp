#include <iostream>
#include <vector>
using namespace std;

int n, x, y, d, g;
int dx[4] = {1 , 0, -1, 0};  
int dy[4] = {0 , -1, 0, 1};
vector <int> v; // 세대에 따른 방향저장 
int graph[101][101]; // 0 으로초기화 true는 갓다옴 

int r_y, r_x; //끝점 저장 
int ct; //사각형 개수 
void dfs()
{
	int s = v.size();
	for(int i = s-1; i >= 0; i--){
		int nd = (v[i] + 1) % 4;
		int ny = r_y + dy[nd];
		int nx = r_x + dx[nd];
		if(ny < 0 || nx < 0 || ny > 100 || nx > 100){
			continue;
		}
		r_y = ny;
		r_x = nx;
        graph[ny][nx] = true;
		v.push_back(nd);	
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		v.clear();
		v.push_back(d);
		graph[y][x] = true;
		int ny = y + dy[d]; 
		int nx = x + dx[d];
		graph[ny][nx] = true;
		r_y = ny;
		r_x = nx;
		for(int j = 0; j < g; j++){
			dfs();
		} 	
	}
	
	for(int i = 0; i < 100; i++){
		for(int j = 0 ; j < 100; j++){
			if(graph[i][j] == true && graph[i][j+1] == true && graph[i+1][j] == true && graph[i+1][j+1] == true){
				ct++;
			}
		}
	}
	
	cout << ct << endl;
	 
	
}
