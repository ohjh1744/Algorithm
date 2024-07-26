#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];
int main()
{
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	for(int i = 4; i <= n ; i++){
		dp[i] = i;
		if(i % 2 == 0){    // 조건 둘다 if로 ex)6 같은 경우 
			dp[i] = min(dp[i], dp[i/2] + 1);
		}
		if(i % 3 == 0){
			dp[i] = min(dp[i], dp[i/3] + 1);
		}
		dp[i] = min(dp[i], dp[i-1] + 1);
	}
	cout << dp[n] << "\n";
	while(true){
		cout << n << " ";
		if(n == 1){
			break;
		}
		else if(dp[n] == dp[n-1] + 1){
			n = n-1;
		}
		else if(n%2 == 0 && dp[n] == dp[n/2] + 1){ // 앞에 조건 필수 
			n = n/2;
		}
		else if(n%3 == 0 && dp[n] == dp[n/3] + 1){// 앞에 조건 필수 
			n = n/3;
		}
	}
}
