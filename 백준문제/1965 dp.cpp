#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1001]; // n번째 상자의 크기 
int box[1001];
int ans;

int main()
{
	cin >> n;
	for(int i = 1; i <= n ; i++ ){
		dp[i] = 1;
	}
	
	for(int i = 1; i <= n ; i++ ){
		cin >> box[i];
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(box[j] < box[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
}
