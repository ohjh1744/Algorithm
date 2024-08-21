#include <iostream>
#include <algorithm>
using namespace std;
//https://yabmoons.tistory.com/18
int dp[10001]; // n��° ���� �������ִ� ������ �ִ��
int grape[10001]; // n��° �����־�

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <=n ; i++){
		cin >> grape[i]; 
	}
	
	dp[1] = grape[1];
	dp[2] = dp[1] + grape[2];
	dp[3] = max(max(dp[2] , grape[2] + grape[3]) , grape[1] + grape[3] );
	for(int i = 4; i <= n; i++){
		dp[i] = max(max(dp[i-1] , dp[i-2] + grape[i]) ,  dp[i-3] + grape[i-1] + grape[i] );
	}
	
	cout << dp[n] << endl;
	
} 

