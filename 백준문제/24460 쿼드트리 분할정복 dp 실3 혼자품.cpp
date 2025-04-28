#include <iostream>
#include <algorithm>
using namespace std;

int n;
unsigned int graph[1025][1025]; // ÀÇÀÚ 

int dfs(int y, int x, int size){
	
	int temp[4];
	
	if(size == 1)
	{
		return graph[y][x];	   	
	}
	else{
		temp[0] = dfs(y, x, size/2);
		temp[1] = dfs(y, x + (size/2), size/2);
		temp[2] = dfs(y + (size/2), x, size/2);
		temp[3] = dfs(y + (size/2), x+ (size/2), size/2);
		
		sort(temp, temp + 4);
		
		return temp[1];
	}
}

int main(){
	cin >> n;
	for(int i = 1; i<= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	
	cout << dfs(1, 1, n);
}
