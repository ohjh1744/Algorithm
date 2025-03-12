#include <iostream>
#include <vector>
using namespace std;

int dp[1001]; // i개일 때 창영이가 이기는 경우 0, 상근이가 이기는 경우 1 
int n;

int main(){
	
	cin >> n;
	
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	
	for(int i = 5; i <= n; i++){
		if(dp[i-1] == 0 || dp[i-3] == 0 || dp[i-4] == 0){
			dp[i] = 1;
		}
		else{
			dp[i] = 0;
		}
	}
	
	if(dp[n] == 1){
		cout << "SK";
	}
	else{
		cout << "CY";
	}
}
