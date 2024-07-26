#include <iostream>
using namespace std;

long long dp[9999999];
int n;
int t;
int main()
{
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
    dp[3] = 4;
    
	while(t--)
	{
		cin >> n;
     	for(int i = 4; i <= n; i++){
		   dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	    }
	
     	cout << dp[n] % 1000000009<< "\n";
	}
	return 0;
	
}
