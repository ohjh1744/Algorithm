#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[1001][2][3]; // i번째날까지  지각 0번과 1번, 결석 0번연속, 1번연속,2번연속  
int mod = 1000000; 
int ans;

// 블로그 참고 엄청쉽지도 엄청어렵지도 않은 문제..  
int main(){
	
	cin >> n;
	
	dp[1][0][0] = 1; // 출석 
	dp[1][1][0] = 1; // 지각 
	dp[1][0][1] = 1; // 결석 1번연속 
	
	for(int i = 2; i <= n; i++){
	dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]) % mod; 
	//결석의 경우는 연속이기 때문에  
	dp[i][0][1] = dp[i-1][0][0];
	dp[i][0][2] = dp[i-1][0][1];
		
	dp[i][1][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2] + dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2]) % mod;
	//전날에 무조건 결석 및 지각 경험이 있어야함. 
	dp[i][1][1] = dp[i-1][1][0];
	dp[i][1][2] = dp[i-1][1][1];
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			ans = (ans + dp[n][i][j]) % mod;
		}
	}
	
	cout << ans;

}
