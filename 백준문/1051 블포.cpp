#include <iostream>
#include <algorithm>
using namespace std;

int graph[51][51];

int main()
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j= 1; j<= m; j++){
			scanf("%1d", &graph[i][j]);
		}
	}
	
	int ans = 1;
	int ct = 1;
	for(int i = 1; i <= n; i++){  //1 3  3 5 
		ct = 1;
		for(int j = 1; j <= m; j++){
			for(int k = 1; ; k++){
				if(i+k > n || j+k > m){
					break;
				}
				if(graph[i+k][j] == graph[i][j] && graph[i][j+k] == graph[i][j] && graph[i+k][j+k] == graph[i][j]){
					ct = (k+1)*(k+1); 
				}
			}
			ans = max(ans, ct);
		}

	}
	
	cout << ans << endl;

}
