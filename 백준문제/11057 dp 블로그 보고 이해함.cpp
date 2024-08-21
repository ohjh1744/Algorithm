#include <iostream>
using namespace std;

int dp[1001][10];

int main()
{
	int n;
	cin >> n ;

	for(int i = 0; i < 10; i++){
		dp[1][i] = 1;
	}
	for(int i = 2; i <= n; i++){
		dp[i][0] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < 10; j++){
			dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 10007;
		}
	}
	int ans = 0;
	for(int i = 0; i <= 9 ; i++){
		ans = ans + dp[n][i];
	}
	
	cout << ans % 10007 << endl;
}
//https://ssinee.tistory.com/38
//https://yabmoons.tistory.com/525
//아래방식이 더 이해감
 


