#include <iostream>
using namespace std;

int n;
bool visited[100001];
int stone[100001];

void dfs(int x)
{	
	if(x < 1 || x > n){
		return;
	}
	
	visited[x] = true;
	
	dfs(x + stone[x]);
	dfs(x - stone[x]);
	
}

int main()
{
	int ai;
	cin >> n;
	for(int i = 1; i<= n; i++){
		cin >> stone[i]; 
	}
	
	int start = 0;
	cin >> start;
	dfs(start);
	
	int ct = 0;
	for(int i =1 ; i <= n; i++){
		if(visited[i]){
		   ct++;	
		}
	}
	
	cout << ct << endl;
	return 0;
}
