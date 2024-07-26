#include <iostream>
using namespace std;

unsigned long long dp[10000000];
int n;
int main()
{
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i = 2; i <=n; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 10;
	}
	cout << dp[n]<< "\n";
}
