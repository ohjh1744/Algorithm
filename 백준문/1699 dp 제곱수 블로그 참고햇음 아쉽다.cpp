#include <iostream>
#include <algorithm>
using namespace std;

int dp[100001];
//https://chanhuiseok.github.io/posts/baek-10/
int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n ; i++){
		dp[i] = i;
		for(int j = 1; j*j <= i ; j++){
			dp[i] = min(dp[i], dp[i - j*j] + 1);
		}
	}
	
	cout << dp[n] << "\n";
}
