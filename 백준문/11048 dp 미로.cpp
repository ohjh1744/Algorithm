#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int graph[1001][1001];
int dp[1001][1001];
int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i = 1 ; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + graph[i][j];
		}
	}
	
	cout << dp[n][m] << endl;

}
