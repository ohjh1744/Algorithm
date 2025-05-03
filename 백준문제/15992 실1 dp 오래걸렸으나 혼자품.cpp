#include <iostream>
#include <vector>
using namespace std;

long long dp[1001][1001];
int t, n, m;

int main(){
	cin >> t;
	
	// 기본 dp 초기화 
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	
	for(int i= 4; i <= 1000; i++){
		for(int j = 2; j <= 1000; j++){
			if(i-3 >= j-1){
				dp[i][j] += dp[i-3][j-1] % 1000000009;
			}
		    if(i-2 >= j-1){
				dp[i][j] += dp[i-2][j-1] % 1000000009;
			}
			if(i-1 >= j-1){
				dp[i][j] += dp[i-1][j-1] % 1000000009;
		    }
		}
	}
	
	for(int i = 0; i < t; i++){			
		cin >> n >> m;			
		cout << dp[n][m] % 1000000009 << "\n";				
	}
	
} 
