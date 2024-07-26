#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];

int main()
{
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2] ;
	}
	
	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i][0] + min(dp[i-1][1] , dp[i-1][2]); // dp[3][0]
		dp[i][1] = dp[i][1] + min(dp[i-1][0] , dp[i-1][2]);
		dp[i][2] = dp[i][2] + min(dp[i-1][0] , dp[i-1][1]);
	}
	
	int ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	cout << ans << endl;
	
}
