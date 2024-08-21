#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001]; //가격 저장 
int dp[1001]; // n장 을 고를때 최소 비용 
int ans = 99999999;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	
	for(int i = 1; i <=n; i++){
		dp[i] = 99999999;
	}
	
	
	dp[1] = p[1];
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i] = min(dp[i] , dp[i-j] + p[j]);
		}
	}
	
	cout << dp[n] << endl;

	
}
