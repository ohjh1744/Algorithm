#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int visited[101];
vector<int> v[101];
queue<int> q;


void bfs(int x){
	q.push(x);
	visited[x] = 0;  // 본인 자신은 0촌이므로  
	
	while(!q.empty()){
		int nx = q.front();
		q.pop();
		for(int i = 0; i< v[nx].size(); i++){
			int y = v[nx][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = visited[nx] + 1;  //촌수계산  
			}
			
		}
	}
}



int main()
{
	int n,a ,b,m;
	cin >> n;
	cin >> a >> b;
	cin >> m;
	
	int n1, n2;
	
	
	for(int i=0; i<m; i++){
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	

	bfs(a);
	
	if(visited[b]==0){
		cout << -1;
	}
	else
	cout << visited[b] ;
	
	
	
}   
