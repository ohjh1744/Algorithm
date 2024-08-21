#include <iostream>
using namespace std;

int t, n , node1, node2, find1, find2;
int parent[10001];
bool visited[10001];

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			parent[i] = i;
			visited[i] = true;
		}
		for(int i = 0; i < n-1; i++){
			cin >> node1 >> node2 ;
			parent[node2] = node1;
		}
		cin >> find1 >> find2;
		
		visited[find1] = true;
		while(parent[find1] != find1){
			find1 = parent[find1];
			visited[find1] = true;
		}
		while(1){
			if(visited[find2] == 1 || parent[find2] == find2){
				break;
			}
			else{
				find2 = parent[find2];
			}
		}
		cout << find2 << endl;
	}
}
