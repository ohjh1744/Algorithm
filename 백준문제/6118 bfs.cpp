#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, a_i, b_i;

vector <int> v[20001];
int visited[20001];

int h = 0;

void bfs(int x)
{
	visited[x] = 0;
	queue <int> q;
	q.push(x);
	while(!q.empty()){
		int cx = q.front();
		q.pop();
		for(int i = 0; i < v[cx].size(); i++){
			int nx = v[cx][i];
			if(!visited[nx] && nx != 1){
				q.push(nx);
				visited[nx] = visited[cx] + 1;
				h = visited[nx]; // 가장 먼거리가 몇인지 구하기 
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a_i >> b_i;
		v[a_i].push_back(b_i);
		v[b_i].push_back(a_i);
	}
	
    bfs(1);
    
    vector <int> ans;
    
    for(int i = 1; i <= n; i++){
    	if(visited[i] == h){
    		ans.push_back(i);
		} 
	}
	
	
	cout << ans.front() << " " << h << " " << ans.size() << endl;
}

