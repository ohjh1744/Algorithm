#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int i = 0;
vector < pair < int, int > > v[500001];
int dist[500001];
int visited[500001];
long long cost;
int i_w_c;
int i_w;

//프림은 다익스트라 돨리 vist으로 처리하는게 수월한듯 
void prim(int start)
{
	for(int i = 1; i <= n; i++){
		dist[i] = 1e9;
	}
	dist[start] = 0;
	priority_queue< pair<int, int >, vector<pair<int,int > > , greater<pair<int,int> > > pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int c_d = pq.top().first;
		int c_n = pq.top().second;
		pq.pop();
	 
		
		if(visited[c_n]){
			continue;
		}		
		visited[c_n] = 1;
		
		if(i==i_w_c){
			i_w = c_d;
		}
		
		i_w_c++;
		cost = cost + c_d;
		
		for(int i = 0; i < v[c_n].size(); i++){
			int n_d = v[c_n][i].second;
			int n_n = v[c_n][i].first;
			cout << n_n << " " << n_d << endl;
			if(n_d < dist[n_n]){
				dist[n_n] = n_d;
				pq.push({dist[n_n], n_n});
			}
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	cin >> i;
	
	for(int i = 0; i < m; i++){
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		v[n1].push_back({n2, w});
		v[n2].push_back({n1, w});
	}
	
	prim(1);
	cout << cost << "\n";
	cout << i_w << "\n";
}
