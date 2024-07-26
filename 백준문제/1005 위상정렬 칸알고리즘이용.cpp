#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
int n, k;
int w;
vector< int > v[1001];
int cost[1001];
int inedge[1001];
int result[1001];

void khan()
{
	
	queue <int> q;
	for(int i = 1; i <= n; i++){
		if(inedge[i] == 0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int c_node = q.front();
		q.pop();
	
		for(int i = 0; i < v[c_node].size(); i++){
			int n_node = v[c_node][i];
			inedge[n_node]--;
			result[n_node] = max(result[n_node], result[c_node] + cost[n_node]);
					
			if(inedge[n_node] == 0){
				q.push(n_node);
			}
		}
	}
	
}


void reset()
{
	for(int i = 1; i <= n; i++){
		result[i] = 0;
		cost[i] = 0;
		inedge[i] = 0;
		for(int j = 0; j < v[i].size(); j++){
			v[i][j] = 0;
		}
	}

	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--){
		reset();
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> cost[i];
			result[i] = cost[i];
		}
		for(int i = 0; i < k ; i++){
			int x, y;
			cin >> x >> y;
			inedge[y]++;
			v[x].push_back(y);
		}
		cin >> w;
		khan();
		cout << result[w] << "\n";
		
	}   
	
}
