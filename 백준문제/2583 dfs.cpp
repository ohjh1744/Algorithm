#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n, m;
int ct = 0;

int visited[101][101];   
int map[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void dfs(int x, int y)
{
	visited[x][y] = 1;
	ct++;
	for(int i =0; i<4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx >= n || ny >= m){
			continue;
		}
		if(map[nx][ny] == 0 && visited[nx][ny] == 0){
			dfs(nx, ny);
		}
	}
	
}

int main()
{
	int k;
	cin >> n >> m >> k; 
	
	vector<int> v;
	
	
	for(int i=0; i < k; i++){
		int l_x, l_y, r_x, r_y;
		cin >> l_y >> l_x >> r_y >> r_x;
		for(int j= l_x; j < r_x; j++){
			for(int z = l_y; z < r_y; z++){
				map[j][z] = 1;
			}
		}
	}
	
	for(int i=0; i< n; i++){
		for(int j=0; j <m; j++){
			if(map[i][j] == 0 && visited[i][j] == 0){
				ct = 0;
				dfs(i, j);
				v.push_back(ct);
			}
		}
	}

	cout << v.size() << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
}
