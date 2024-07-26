#include <iostream>
using namespace std;

int n, m;
int dp[41]; //ÁÂ¼®n°³ÀÏ¶§ ¾ÉÀ»¼öÀÕ´Â ¹æ½Ä
int vip[41]; // vip 

int main()
{
	cin >> n;

    dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> vip[i]; 
	}
	int ans = 1;
	int start = 0;
	for(int i = 1; i <= m; i++){
		ans = ans * dp[vip[i] - start - 1]; 
		start = vip[i];
		
	}
	ans = ans * dp[n-vip[m]];
	cout << ans << "\n";

	
	
	
	
}
