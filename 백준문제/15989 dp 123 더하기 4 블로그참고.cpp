#include <iostream>
using namespace std;

//https://nim-code.tistory.com/133
int dp[10001][4]; // 1 2 3 으로 끝나는 
int n;
int t;

// 중복피해 오른차순으로만 더하기 
 
int main()
{
	cin >> t;
	dp[1][1] = 1;
	dp[1][2] = 0;
	dp[1][3] = 0;
	
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[2][3] = 0;
	
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	
	while(t--)
	{
		cin >> n;
		for(int i = 4; i <= n; i++){
			dp[i][1] = dp[i-1][1];
			dp[i][2] = dp[i-2][1] + dp[i-2][2];
			dp[i][3] = dp[i-3][1] + dp[i-3][2] +  dp[i-3][3];
		}
		cout << dp[n][1] + dp[n][2] +dp[n][3] << "\n";
	}
	
}
