#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[500001];
int visited[500001];
queue <int> q;
int ans = 0;

void bfs(int x){
	q.push(x);
	visited[x] = 0;
	
	while(!q.empty()){
		int nx = q.front();
		q.pop();
		for(int i = 0; i< v[nx].size(); i++){
			int y = v[nx][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = visited[nx] + 1;
			}
			
		}
	}
}


int main()
{
	int n;
	cin >> n;
	
	int a, b;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b ;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs(1);
	
	for(int i = 1; i <= n; i++){
		if(v[i].size() == 1){
			ans = ans + visited[i];
		}
	}
	
	if(ans % 2 == 0){
		cout << "No" << endl;
	}
	else{
		cout << "Yes" << endl;
	}
	
	
}
