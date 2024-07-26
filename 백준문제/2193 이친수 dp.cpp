#include <iostream>
using namespace std;

long long dp[91][2];
long long answer;
int n;
int main()
{
	cin >> n;
	dp[1][0] = 0;
	dp[1][1] = 1;
	
	dp[2][0] = 1;
	dp[2][1] = 0;
	
	for(int i = 3 ; i <= n ; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
	answer = dp[n][0] + dp[n][1];
	
	cout << answer << endl;
}
