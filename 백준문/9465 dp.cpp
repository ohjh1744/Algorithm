#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][100000]; // 그 위치에 있는 카드를 뽑을때 의 최대값 

int main()
{
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		
		for(int i = 0; i <2; i++){
			for(int j = 0; j <n; j++){
				cin >> dp[i][j];
			}
		}
		
		dp[0][1] = dp[0][1] + dp[1][0];
		dp[1][1] = dp[1][1] + dp[0][0];
		
		for(int i = 2; i < n; i++){
			dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + dp[0][i];
			dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + dp[1][i];
		}
        cout << max(dp[0][n-1] , dp[1][n-1]) << "\n";
	}
	
}
