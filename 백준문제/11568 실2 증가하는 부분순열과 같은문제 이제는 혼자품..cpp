#include <iostream>
#include <algorithm> 
using namespace std;

int dp[1001]; // 현재 모두 1 , 각 n까지의 최대길이 
int temp[1001];
int n;
int ans = 1;

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		temp[i] =  num;
	}
	
	for(int i = 1; i <= n; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++){
			if(temp[j] < temp[i] && dp[j] +1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
		
	}
	
	cout << ans << "\n";
	
}
