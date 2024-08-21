#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector <pair< int, int> > v[1001];  // 이어지는 노드와 길이저장 
int visited[1001];

void bfs(int x , int fx)
{
   visited[x] = true;
   queue <pair< int, int> > q;
   q.push({x, 0});
   while(!q.empty()){
   	 visited[x] = 1;
	 int cx = q.front().first;
	 int cl = q.front().second;
   	 q.pop();
   	 if(cx == fx){
   	 	cout << cl  <<endl;
   	 	return ;
	 }
   	 for(int i = 0; i < v[cx].size(); i++){
   	 	int nx = v[cx][i].first;
   	 	int nl = v[cx][i].second;
		if(!visited[nx]){
   	 		q.push({nx, cl + nl});
   	 		visited[nx] = true;
		}
	 }
   }
   cout << "0" << endl;
   return;
}

void clear()
{
	for(int i = 0; i <= n; i++){
		visited[i] = 0;
	}
}

int main()
{
	cin >> n >> m;
	int node1, node2, length;
	
	for(int i = 0; i < n-1; i++){
		cin >> node1 >> node2 >> length;
		v[node1].push_back({node2, length});
		v[node2].push_back({node1, length});
	}
	
	int want1 , want2;
	for(int i = 0; i < m; i++){
	    cin >> want1 >> want2;
		bfs(want1, want2);
		clear();
	}
	
}
