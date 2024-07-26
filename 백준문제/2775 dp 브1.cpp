#include <iostream>
using namespace std;

int t, k , n;
int dp[15][15]; // 0Ãþ~ 14Ãþ , 1È£~ 14È£±îÁö 

int main()
{
	cin >> t;
	
	for(int i = 1; i <= 14; i++){
		dp[0][i] = i;
	}
	
	while(t--){
		cin >> k;
		cin >> n;
		if(k == 0){
			cout << dp[k][n] << "\n";
		}
		else{
			for(int i = 1; i <= k; i++){
				for(int j = 1; j <= n; j++){
					dp[i][j] = dp[i][j-1] + dp[i-1][j];
				}
			}
		}
		cout << dp[k][n] << "\n";
	}
	
}
