#include <iostream>
using namespace std;

int graph[64][64];
int n;

void dfs(int y, int x, int size){
	
	int num = graph[y][x];
	bool _isSame = true;
	
	for(int i = y; i < y + size; i++){
		for(int j = x; j < x+ size; j++){
			if(num != graph[i][j]){
				_isSame = false;
				break;
			}
		}
	}
	
	if(_isSame == false){
		cout << "(";
		dfs(y, x, size/2);
		dfs(y, x + size/2, size/2);
		dfs(y + size/2, x , size/2);
		dfs(y + size/2, x + size/2, size/2);
		cout << ")";
	}
	else if(_isSame == true){
		cout << num;
		return;
	}
	
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%1d", &graph[i][j]);
		}
	}
		
	dfs(0, 0, n);
}
