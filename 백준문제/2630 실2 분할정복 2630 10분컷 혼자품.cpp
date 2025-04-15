#include <iostream>
#include <vector>
using namespace std;

int n;
int graph[128][128];
int color[2]; //0 하얀색, 1 파란색 

void dfs(int y, int x, int size){
	
	int f_color = graph[y][x];
	bool isSame = true;
	
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x + size; j++){
			if(f_color != graph[i][j]){
				isSame = false;
				break;
			}
		}
	}
	
	if(isSame == true){
		color[f_color]++;
		return;
	}
	
	dfs(y, x, size/2);
	dfs(y, x + (size/2), size/2);
	dfs(y + (size/2), x, size/2);
	dfs(y + (size/2), x + (size/2), size/2);
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}
	
	dfs(0, 0, n);
	
	cout << color[0] << "\n";
	cout << color[1] << "\n";
	
}
