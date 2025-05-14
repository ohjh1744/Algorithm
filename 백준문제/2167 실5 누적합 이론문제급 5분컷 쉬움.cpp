#include <iostream>
#include <map>
using namespace std;

int n, m, k;
int graph[301][301];
int dp[301][301];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	cin >> k;
	
	//ДЉРћЧе 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + graph[i][j];
		}
	}
	
	
	
	for(int i = 0; i < k; i++){
		int fi, fj, ei, ej;
		cin >> fi >> fj >> ei >> ej;
		cout << dp[ei][ej] - dp[fi-1][ej] - dp[ei][fj-1] + dp[fi-1][fj-1] << "\n";
	}
}
