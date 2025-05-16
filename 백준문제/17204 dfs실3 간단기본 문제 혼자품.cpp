#include <iostream>
#include <vector>
using namespace std;

int temp[151]; // i°¡ j¸¦ °¡¸£Å´ 
int n, k;
int visited[151];
int ans = -1;

void dfs(int x, int cnt){
	visited[x] = true;
	
	if(x == k){
		ans = cnt;
		return;
	}
	if(visited[temp[x]] == false){
		dfs(temp[x], cnt+1);
	}
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
	}
	
	dfs(0, 0);
	
	cout << ans;
}
