#include <iostream> 
#include <algorithm> 
using namespace std;

int dp[1001]; // n까지 최대 크기 
int temp[1001];

int main()
{
	int n;
	cin >> n;
	for(int i = 1 ; i<= n; i++){
		cin >> temp[i];
		dp[i] = temp[i];
	}
	
	int ans = 0;
	
	for(int i = 1 ; i<= n; i++){
		for(int j = 1; j < i; j++){
			if(temp[j] < temp[i] && dp[j] + temp[i] > dp[i] ){
				dp[i] = dp[j] + temp[i];
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl; 
}
