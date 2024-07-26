#include <iostream>
using namespace std;

int dp[1001];
int main()
{
	int n;
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 0;
	for(int i = 5; i <= n; i++){
		if(i%2 == 1){
			dp[i] = 1;
		}
		else{
			dp[i] = 0;
		}
	}
	
	if(dp[n] == 0){
		cout << "SK" << endl;
	}
	else{
		cout << "CY" << endl;
	}
	
}
