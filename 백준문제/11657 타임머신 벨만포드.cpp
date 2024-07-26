#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, c;
vector < pair < int , pair < int, int > > > v;
long long dist[501];
// ll 이용한이유는 최대값의 음의 사이클 발생시 int형 벗어남
// 간선개수 6000개, 1 -> 2 -> *** -> n -> 1 (간선길이 -10000)경우, -60000000 *반복한 만큼 최단길이 계속변화. 

// 벨만포드는 간선의 길이(n-1)만큼 반복하고, 정상적인 그래프면 n-1안에 이미 값이 정해지지만,
// 비정상적인그래프(음의사이클, 양의사이클)는 계속 값이 변화~. 

bool bellmanFord(int start)
{
	dist[start] = 0;
	
	// n-1 번만 반복 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < v.size(); j++){
			int fr = v[j].first;
			int to = v[j].second.first;
			int d = v[j].second.second;
			
			if(dist[fr] == 1e9){
				continue;
			}
			
			if(dist[to] > dist[fr] + d){
				dist[to] = dist[fr] + d;
				
				if(i == n){
					return true;   //n번째부터 또 값이변경된다면 사이클이 발생햇다는것. 
				}
			}
		}
		
		cout << dist[1] << " " << dist[2] << " " << dist[3] << "\n"; 
	}
	
	return false;
}


int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		v.push_back({a, { b, c}});
	}
	
	for(int i = 1; i <= n; i++){
		dist[i] = 1e9;
	}
	
	bool b = bellmanFord(1);
	
	if(b == true){
		cout << -1;
		return 0;
	} 
	else{
		for(int i = 2; i <= n; i++){
			if(dist[i] == 1e9){
				cout << -1 << "\n";
			}
			else{
				cout << dist[i] << "\n";
			}
		}
	}
	
}
