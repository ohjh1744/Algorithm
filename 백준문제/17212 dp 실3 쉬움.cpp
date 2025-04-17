#include <iostream>
using namespace std;

int n;
int dp[100001];

int main(){
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 2;
	dp[7] = 1;
	
	for(int i = 8; i <= n; i++){
		dp[i] = min(min(min(dp[i-1], dp[i-2]), dp[i-5]), dp[i-7]) + 1;
	}
	
	cout << dp[n];
}
