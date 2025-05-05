#include <iostream>
#include <vector>
using namespace std;

int n;
long long ans;
vector< pair < int , int > > v[5001];
int visited[5001];

void dfs(int x, long long dist){
	visited[x] = true;
	
	if(ans < dist){
		ans = dist;
	}
	for(int i = 0; i < v[x].size(); i++){
		int nx = v[x][i].first;
		int nd = v[x][i].second;
		
		if(visited[nx] == false){
			dfs(nx, dist + nd);
		}
	}
} 

int main(){
	cin >> n;
	
	for(int i = 0; i < n-1; i++){
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({to, dist});
		v[to].push_back({from, dist});
	}
	
	dfs(1, 0);
	
	cout << ans ;
	
}
