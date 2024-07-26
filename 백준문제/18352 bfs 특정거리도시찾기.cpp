#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<int> q;
vector<int> v[300001];
int visited[300001];

vector<int> answer;

int n , m, k , x;
int a, b;

void bfs(int node)
{
	visited[node] = 0;
	q.push(node);
	while(!q.empty()){
		int cx = q.front();
		q.pop();
		for(int i = 0; i < v[cx].size(); i++){
			int nx = v[cx][i];
			if(!visited[nx] && nx != node){ // nx != node 이유는  시작점으로 다시 돌아가는걸 막기위해, 시작점은 무조건 거리 0인데  if문조건에 적합해서 visited 값이 나중에 달라질수가 있기때문  
				q.push(nx);
				visited[nx] = visited[cx] + 1;
				if(visited[nx] == k){
					answer.push_back(nx);
				}
			}
			
		}
	}
	
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> x;
	
	for(int i =0; i < m; i++){
		cin >> a >> b;
		v[a].push_back(b);
	}
	
	bfs(x);
	sort(answer.begin(), answer.end());
	
	if(answer.empty()){
		cout << "-1" << endl;
	}
	else{
		for(int i = 0; i < answer.size(); i++){
		  cout << answer[i] << endl;
	    }
	}
	
	
}




