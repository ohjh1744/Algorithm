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
		for(int j = 1; j<= n; j++){
			cin >> arr[i][j];
		}
	}
	
	dp[1][n] = arr[1][n];
	
	for(int i = 2; i <= n; i++){
		dp[i][n] = dp[i-1][n] + arr[i][n];
	}
	
	for(int i = n-1; i >= 1; i--){
		dp[1][i] = dp[1][i+1] + arr[1][i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	
		
	for(int i = 2; i <= n; i++){
		for(int j = n-1; j >= 1; j--){			
			dp[i][j] = min(dp[i-1][j], min(dp[i][j+1], dp[i-1][j+1])) + arr[i][j];
		}
	}
	
	cout << dp[n][1] << "\n";
	
	
}
