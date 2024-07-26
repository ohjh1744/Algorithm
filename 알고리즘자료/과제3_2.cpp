#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001][2001];
int dp[2001][2001];
int n;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = n; j >= 1; j--){
			cin >> arr[i][j];
		}
	}
	
	dp[1][1] = arr[1][1];
	
	for(int i = 2; i <= n; i++){
		dp[i][1] = dp[i-1][1] + arr[i][1];
		dp[1][i] = dp[1][i-1] + arr[1][i];
	}
	
	
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++){			
			dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + arr[i][j];
		}
	}
	
	cout << dp[n][n] << "\n";
	
	
}
