#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int paper[500][500];
bool visited[500][500];

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
int w;
vector<int> v;

void dfs(int y, int x) // y는 세로, x는가로 
{
	w++;
	visited[y][x] = true;
	for(int i =0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= m || ny>= n){
			continue;
		}
		if(visited[ny][nx] == false && paper[ny][nx] == 1){
			dfs(ny, nx);
		}
	}
	
}

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j< m; j++){
			scanf("%1d" , &paper[i][j]);
		}
	}
	
	int paint_num = 0;
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j< m; j++){
		 if(visited[i][j] == false && paper[i][j] == 1){
			paint_num++;
			dfs(i, j);
			v.push_back(w);
			w = 0;
		 } 	
		}
	}
		
	sort(v.rbegin(), v.rend());
	
	cout << paint_num << endl;	
	if(paint_num == 0){
		v.push_back(0);
	}
	cout << v[0] << endl;
	
	return 0;	
	
}
