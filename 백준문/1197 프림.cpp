#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int n, e;
int a, b, c;
int visited[10001];
int dist[10001];
vector<pair<int,int> >v[10001];
long long cnt;


void prim(int start)
{
	for(int i = 0; i <= n; i++){
		dist[i] = 1e9;
	}
	
	dist[start] = 0;
	
	priority_queue< pair< int, int> , vector< pair < int, int > > , greater< pair < int, int > > > pq;
	
	pq.push({0, start});
	
	while(!pq.empty()){
		int cn = pq.top().second;
		int cd = pq.top().first;
		pq.pop();
		
		if(visited[cn]){
			continue;
		}		
		visited[cn] = true;
		
		cnt = cnt + cd;
		
		for(int i = 0; i < v[cn].size(); i++){
			int nn = v[cn][i].first;
			int nd = v[cn][i].second;
			
			if(dist[nn] > nd){
				dist[nn] = nd;
				pq.push({nd, nn});

			}
		}
	}
}



int main()
{
	cin >> n >> e;
	for(int i = 0; i < e; i++){
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c}); // 양방향 그래프 -> 이걸뺴면 ex) 2 1 1 , 3 1 3, 4 1 2 의 간선이 주어졌다고 할때, 노드 1에서 간선체크를 제대로 할 수가 없다.(노드 1 에 연결된 간선이 없기 때문에)
	}
	
	prim(1);
	
	cout << cnt << "\n";
}
