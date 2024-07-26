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
		v[b].push_back({a, c}); // 양방향 그래프 -> 이걸 빼면 a가 1이 없는 경우, 정점1을 기준으로 체크를 못함. 
	}
	
	prim(1);
	
	cout << cnt << "\n";
}
