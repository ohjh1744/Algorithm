#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[100001];
vector <pair <int, int > > v_2; // 결과확인용 m저장 
int inedge[100001];
int n, m;
queue <int> q;
int result[100001]; // result[1] = 4 -> 1은 4번째 

void kahn()
{
	int rank = 1;
	while(!q.empty()){
		int c_node = q.front();
		q.pop();
		result[c_node] = rank;
		rank++;
		
		for(int i = 0; i < v[c_node].size(); i++){
			int n_node = v[c_node][i];
			inedge[n_node]--;
			
			if(inedge[n_node] == 0){
				q.push(n_node);
			}
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, u_2;
		cin >> u >> u_2;
		v[u].push_back(u_2);
		v_2.push_back({u, u_2});
	}
	
	//inedge 개수 
	for(int i = 1; i<= n; i++){
		for(int j = 0; j < v[i].size(); j++){
			inedge[v[i][j]]++;
		}
	}
	
	//inedge없는 node 큐에넣기 
	for(int i = 1; i <= n; i++){
		if(inedge[i] == 0){
			q.push(i);
		}
	}
	
	if(q.empty()){
		cout << "Yes" << "\n";
		return 0;
	}

	
	kahn();
	
	for(int i = 0; i < v_2.size(); i++){
		int u = v_2[i].first;
		int u_2 = v_2[i].second;
		if(result[u_2] < result[u]){
			cout << "Yes" << "\n";
			return 0;
		}
	}
	
	cout << "No" << "\n";
	return 0;
	
}
