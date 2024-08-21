#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[50][50];
int map[50][50];
vector<int> v;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int y, int x, int num, int ct)
{
	if( ct == 6){
		v.push_back(num);
		return;
	}
	
	for(int i=0; i< 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5){
			continue;
		}
		
		dfs(ny, nx , num*10 + map[ny][nx] , 1+ ct);
		
	}
}

int main()
{
	for(int i =0; i <5; i++){
		for(int j =0; j < 5; j++){
			cin >> map[i][j];
		}
	}
	
	for(int i =0; i <5; i++){
		for(int j =0; j < 5; j++){
			dfs(i, j, 0, 0);
		}
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	cout << v.size() << endl;
	
	
}
