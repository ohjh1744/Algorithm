#include <iostream>
using namespace std;

int dp[1000000];

int main()
{
	cin.tie(0);
	cout.tie(0);
	int t, n;
	
	cin >> t ;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	
	for(int i =0; i < t; i++){
		cin >> n;
		for(int i = 4 ; i <= n ; i++){
			dp[i] = dp[i-3] + dp[i-2] +dp[i-1];
		}
		cout << dp[n] << endl;
	}
	
	
	
}
