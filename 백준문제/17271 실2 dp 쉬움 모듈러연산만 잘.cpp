#include <iostream>
using namespace std;

int n, m;
long long dp[10001];

// 모듈러 연산에서 시간 좀 씀
// dp 자체는 해결 쉬운문제 
int main(){
	cin >> n >> m;
	
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		if(i < m){
			dp[i] = 1;
		}
		else{
			int temp = (dp[i-1] + dp[i-m]) % 1000000007;
			dp[i] = (dp[i]  + temp) % 1000000007;
		}
	}
	
	cout << dp[n];
}
