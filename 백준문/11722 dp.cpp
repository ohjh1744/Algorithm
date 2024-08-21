#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int temp[1001];
int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> temp[i+1];
		dp[i+1] = 1; 
	}
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j= 1; j <= i; j++){
			if(temp[i] < temp[j] && dp[j]+1 > dp[i]){
				dp[i] = dp[i] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	
}


