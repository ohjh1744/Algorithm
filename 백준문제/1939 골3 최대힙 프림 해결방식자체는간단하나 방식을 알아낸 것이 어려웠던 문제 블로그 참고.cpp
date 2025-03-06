#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

int n, m;
vector < pair < int, int > > v[10001];
int sn, en;
int dist[10001];
int visited[10001]; 
int ans = 1e9;

// 해결방식자체는 간단하나 그 해결 방식을 알아내는 것이 어려웠던 문제 
// 프림은 mst를 구하는 알고리즘이지만 과정이 다익스트라랑 비슷하기에
// 단일 출발점에서 다른 노드까지의 최적경로 구하기 가능. 
// 최대스패닝트리를 구하는 과정에서  end노드를 처음 만낫을 때까지 구한  dist중에 가장 작은 값이 정답. 
void prim(int x){
	
    for(int i = 0; i < n; i++){
   	   dist[i] = 0;
    }
   	
	dist[x] = 1e9;
	
	priority_queue < pair< int, int> >  pq;
	
	pq.push({1e9, x});
	
	while(!pq.empty()){
		int cd = pq.top().first;
		int cx = pq.top().second;
		pq.pop();
		
		// 이미 꺼낸 노드면 
		if(visited[cx] == true){
			continue;
		}
		
		visited[cx] = true;
		
		//스패닝경로에서 가장 작은값이 정답. 
		if(ans > cd){
			ans = cd;
		}
		//end만나면 종료 
		if(cx == en){
			return;
		}
		
		for(int i = 0; i < v[cx].size(); i++){
			int nx = v[cx][i].first;
			int nd = v[cx][i].second;
			
			if(dist[nx] < nd){
				dist[nx] = nd;
				pq.push({nd, nx});
			}
		}
	}
}

int main(){
   cin >> n >> m;
   
   for(int i = 0; i < m; i++){
      int n1, n2, dist;
      cin >> n1 >> n2 >> dist;
      v[n1].push_back({n2, dist});
      v[n2].push_back({n1, dist});
   }
   
   
   cin >> sn >> en;
   
   prim(sn);
   
   cout << ans ;
   
   
}
