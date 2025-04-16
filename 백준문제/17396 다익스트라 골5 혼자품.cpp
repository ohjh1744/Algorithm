#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//17396
int n, m;
vector < pair < int, int > > v[100001];
long long dist[100001];
int visited[100001]; // 시야로 인하여 방문가능한지 불가능한지.  0이면 방문가능. 1이면 불가능. 

void djstra(int start){
	
	for(int i = 0; i < n; i++){
		dist[i] = 999999999999;
	}
	dist[start] = 0;
	
	priority_queue < pair < long long, int> , vector < pair < long long, int > > , greater < pair < long long , int > > > pq;
	
	pq.push({0, start});
	while(!pq.empty()){
		int cn = pq.top().second;
		long long cd = pq.top().first;
		pq.pop();
		
		if(dist[cn] < cd){
			continue;
		}
		
		for(int i = 0; i < v[cn].size(); i++){
			int nn = v[cn][i].first;
			long long nd = v[cn][i].second;
			
			if(visited[nn] == 1){
				continue; 
			}
			
			if(dist[nn] > nd + cd){
				dist[nn] = nd + cd;
				pq.push({nd+cd, nn});
			} 
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		visited[i] = num; 
	}
	
	// 마지막 종점은 방문할수있또록 Update. 
	visited[n-1] = 0;
	
	for(int i = 0; i < m; i++){
		int fn, sn, d;
		cin >> fn >> sn >> d;
		v[fn].push_back({sn, d});
		v[sn].push_back({fn, d});
	}
	
	
	djstra(0);
	if(dist[n-1] == 999999999999){
		cout << -1;
	}
	else{
		cout << dist[n-1];
	}
	
}
