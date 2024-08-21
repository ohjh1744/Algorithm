#include <iostream>
#include <algorithm> 
using namespace std;

int dp[301][301];
int graph[301][301];
int n, m; //세로 가로 
int ans;
int main()
{
	cin >> n >> m;
	for(int i = 0; i <n; i++){
		for(int j = 0; j < m; j++){
			cin >> graph[i][j];
		}
	}
	
	dp[0][0] = graph[0][0];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){			
			dp[i][j+1] = max(dp[i][j+1], graph[i][j+1] + dp[i][j]);
			dp[i+1][j] = max(dp[i+1][j], graph[i+1][j] + dp[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
}
