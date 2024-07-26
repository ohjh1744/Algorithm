#include <iostream>
using namespace std;

int n;
int dp[1001]; // 0은 상근, 1은 창영 

int main()
{
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		if(dp[i-1] == 1){
			dp[i] = 0;
		}
		else{
			dp[i] = 1;
		}
	}
	
	if(dp[n] == 0){
		cout << "SK";
	}
	else{
		cout << "CY";
	}
}
