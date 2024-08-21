#include <iostream>
#include <algorithm>
using namespace std;

int n;
int temp[2001];
int dp[2001];
int ans; 

// 11053 이랑 비슷한문제 
// https://www.acmicpc.net/problem/18353 참고 
int main()
{
	cin >> n;
	for(int i = 0; i <n; i++){
		cin >> temp[i];
	}
	
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j= 0; j < i; j++){
			if(temp[i] < temp[j] && dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans,dp[i]);
		
	}
	
	cout << n - ans<< endl;
	
    
}
